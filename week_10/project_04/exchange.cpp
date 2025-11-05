#include "exchange.hpp"
#include "useraccount.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

// Loop through all accounts and detect if user exists
bool Exchange::UserExists(std::string name) {
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == name) {
            return true;
        }
    }
    return false;
}

// Find and return a user
UserAccount &Exchange::GetUser(std::string name) {
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == name) {
            return this->accountList.at(pos);
        }
    }

    // If user does not exist, create one
    accountList.push_back(UserAccount(name)); 
    return this->accountList.back();
}

// Get user and deposit the stated amount in the stated asset
void Exchange::MakeDeposit(std::string username, std::string asset, int amount) {
    UserAccount &user = GetUser(username);
    user.Deposit(asset, amount);
}

// Get user and withdraw the stated amount from the stated asset
bool Exchange::MakeWithdrawal(std::string username, std::string asset, int amount) {
    if (UserExists(username)) {
        UserAccount &user = GetUser(username);
        return user.Withdrawal(asset, amount);
    } else {
        return 0;
    }
}

void Exchange::PrintUserPortfolios(std::ostream &os) {
    // https://algocademy.com/link/?problem=sorting&lang=cpp&solution=1
    std::sort(this->accountList.begin(), this->accountList.end(), [](auto a, auto b) { return a.GetName() < b.GetName(); });

    os << "User Portfolios (in alphabetical order):";

    // Loop through all accounts
    for (unsigned int pos = 0; pos < this->accountList.size(); pos++) {
        UserAccount &user = this->accountList.at(pos);
        
        os << "\n" << user.GetName() << "\'s Portfolio: ";
        
        // State amount if it is greater than zero
        if (user.GetPortfolio().count("BTC") && user.GetPortfolio().at("BTC") > 0) {
            os << user.GetPortfolio().at("BTC") << " BTC, ";
        }
        if (user.GetPortfolio().count("ETH") && user.GetPortfolio().at("ETH") > 0) {
            os << user.GetPortfolio().at("ETH") << " ETH, ";
        }
        if (user.GetPortfolio().count("LTC") && user.GetPortfolio().at("LTC") > 0) {
            os << user.GetPortfolio().at("LTC") << " LTC, ";
        }
        if (user.GetPortfolio().count("USD") && user.GetPortfolio().at("USD") > 0) {
            os << user.GetPortfolio().at("USD") << " USD, ";
        }
    }
    os << "\n";
}

// Loop through orders and find which is selling for lowest price
int Exchange::getLowestPrice(Order& order) {
    int lowest = 1000000000;
    int lowestPos = -1;
    for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
        if (this->openOrders.at(pos).asset == order.asset && this->openOrders.at(pos).side == "Sell" && this->openOrders.at(pos).price <= order.price && this->openOrders.at(pos).price < lowest) {
            lowest = this->openOrders.at(pos).price;
            lowestPos = pos;
        }
    }
    return lowestPos;
}

// Loop through orders and find which is selling for highest price
int Exchange::getHighestPrice(Order& order) {
    int highest = 0;
    int highestPos = -1;
    for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
        if (this->openOrders.at(pos).asset == order.asset && this->openOrders.at(pos).side == "Buy" && this->openOrders.at(pos).price >= order.price && this->openOrders.at(pos).price > highest) {
            highest = this->openOrders.at(pos).price;
            highestPos = pos;
        }
    }
    return highestPos;
}

void Exchange::EnactTrade(Order& takerOrder, Order& makerOrder) {
    // Modify actual account information
    UserAccount &taker = GetUser(takerOrder.username);
    UserAccount &maker = GetUser(makerOrder.username);

    UserAccount* buyer;
    UserAccount* seller;

    // Figure out which account is buying and which is selling
    if (takerOrder.side == "Buy") {
        buyer = &taker;
        seller = &maker;
    } else {
        buyer = &maker;
        seller = &taker;
    }

    // Figure out information about transaction
    int amountToTrade = std::min(takerOrder.amount, makerOrder.amount);
    int price = takerOrder.price;

    // Adjust balances
    buyer->Deposit(takerOrder.asset, amountToTrade);
    seller->Deposit("USD", amountToTrade * price);

    // Update orders
    takerOrder.amount -= amountToTrade;
    makerOrder.amount -= amountToTrade;

    // Record the transactions
    Order filledMaker{};
    filledMaker.username = makerOrder.username;
    filledMaker.side = makerOrder.side;
    filledMaker.asset = takerOrder.asset;
    filledMaker.amount = amountToTrade;
    filledMaker.price = price;
    this->filledOrders.push_back(filledMaker);

    Order filledTaker{};
    filledTaker.username = takerOrder.username;
    filledTaker.side = takerOrder.side;
    filledTaker.asset = takerOrder.asset;
    filledTaker.amount = amountToTrade;
    filledTaker.price = price;
    this->filledOrders.push_back(filledTaker);

    Trade trade{};
    trade.seller_username = seller->GetName();
    trade.buyer_username = buyer->GetName();
    trade.amount = amountToTrade;
    trade.asset = makerOrder.asset;
    trade.price = price;
    this->tradeHistory.push_back(trade);
}

void Exchange::ProcessTakerOrder(Order& takerOrder) {
    while (takerOrder.amount > 0) {
        int matchPos{};
        if (takerOrder.side == "Buy") {
            matchPos = getLowestPrice(takerOrder);
        } else {
            matchPos = getHighestPrice(takerOrder);
        }

        if (matchPos == -1) { break; }

        Order &makerOrder = this->openOrders.at(matchPos);

        // Enact trade
        EnactTrade(takerOrder, makerOrder);

        // Remove fully filled maker order
        if (makerOrder.amount == 0) {
            this->openOrders.erase(this->openOrders.begin() + matchPos);
        }
    }

    // Any remaining orders should still be in open orders
    if (takerOrder.amount > 0) {
        this->openOrders.push_back(takerOrder);
    }
}

bool Exchange::AddOrder(Order newOrder) {
    UserAccount& user = GetUser(newOrder.username);

    // See if recieved order is to buy or sell
    // Adjust account accordingly
    if (newOrder.side == "Buy") {
        int totalCost = newOrder.amount * newOrder.price;
        if (user.GetPortfolio().at("USD") >= totalCost) {
            user.Withdrawal("USD", totalCost);
        } else { return false; }
    } 
    else if (newOrder.side == "Sell") {
        if (user.GetPortfolio().at(newOrder.asset) >= newOrder.amount) {
            user.Withdrawal(newOrder.asset, newOrder.amount);
        } else { return false; }
    }

    ProcessTakerOrder(newOrder);

    return 1;
}

void Exchange::PrintUsersOrders(std::ostream &os) {
    // Sort list (https://algocademy.com/link/?problem=sorting&lang=cpp&solution=1)
    std::sort(this->accountList.begin(), this->accountList.end(), [](auto a, auto b) { return a.GetName() < b.GetName(); });

    os << "Users Orders (in alphabetical order):";

    // Loop through accounts, then loop through orders
    // If the user has open orders, list them
    // If the user has fullfilled orders, also list them
    for (unsigned int accountNumber = 0; accountNumber < this->accountList.size(); accountNumber++) {
        UserAccount &user = this->accountList.at(accountNumber);
        os << "\n" << user.GetName() << "\'s Open Orders (in chronological order):";
        
        for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
            if (this->openOrders.at(pos).username == user.GetName()) {
                os << "\n" << this->openOrders.at(pos);
            }
        }

        os << "\n" << user.GetName() << "\'s Filled Orders (in chronological order):";
        for (unsigned int pos = 0; pos < this->filledOrders.size(); pos++) {
            if (this->filledOrders.at(pos).username == user.GetName() && this->filledOrders.at(pos).amount != 0) {
                os << "\n" << this->filledOrders.at(pos);
            }
        }
    }
    os << "\n";
}

// Loop through all trades and list the info in them
void Exchange::PrintTradeHistory(std::ostream &os) {
    os << "Trade History (in chronological order):";
    for (unsigned int pos = 0; pos < this->tradeHistory.size(); pos++) {
        os << "\n" << this->tradeHistory.at(pos).buyer_username << " Bought " << this->tradeHistory.at(pos).amount << " of " << this->tradeHistory.at(pos).asset << " From " << this->tradeHistory.at(pos).seller_username << " for " << this->tradeHistory.at(pos).price << " USD";
    }
    os << "\n";
}

// For each asset, look through open orders and find what the current highest bid price and lowest sell price are
void Exchange::PrintBidAskSpread(std::ostream &os) {
    std::vector<std::string> assets = {"BTC", "ETH", "LTC"};
    os << "Asset Bid Ask Spread (in alphabetical order):\n";

    for (unsigned int assetType = 0; assetType < assets.size(); assetType++) {
        int lowestOpenSell = 1000000;
        int highestOpenBuy = -1;

        for (unsigned int orderNumber = 0; orderNumber < this->openOrders.size(); orderNumber++) {
            if (assets.at(assetType) == this->openOrders.at(orderNumber).asset) {
                if (this->openOrders.at(orderNumber).side == "Buy" && this->openOrders.at(orderNumber).amount > 0) {
                    if (this->openOrders.at(orderNumber).price > highestOpenBuy) {
                        highestOpenBuy = this->openOrders.at(orderNumber).price;
                    } 
                }       
                else if (this->openOrders.at(orderNumber).side == "Sell" && this->openOrders.at(orderNumber).amount > 0) {
                    if (this->openOrders.at(orderNumber).price < lowestOpenSell) {
                        lowestOpenSell = this->openOrders.at(orderNumber).price;
                    }
                }
            }
        }
        os << assets.at(assetType) << ": Highest Open Buy = ";
        if (highestOpenBuy == -1) {
            os << "NA";
        }
        else {
            os << highestOpenBuy; 
        }

        os << " USD and Lowest Open Sell = ";
        
        if (lowestOpenSell == 1000000) {
            os << "NA";
        }
        else {
            os << lowestOpenSell;
        }
        os << " USD\n";
    }
}