#include "exchange.hpp"
#include "useraccount.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

bool Exchange::UserExists(std::string name) {
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == name) {
            return true;
        }
    }
    return false;
}

UserAccount& Exchange::GetUser(std::string name) {
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == name) {
            return this->accountList.at(pos);
        }
    }
    accountList.push_back(UserAccount(name)); 
    return this->accountList.back();
}

void Exchange::MakeDeposit(std::string username, std::string asset, int amount) {
    UserAccount &user = GetUser(username);
    user.Deposit(asset, amount);
}

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
    std::sort(this->accountList.begin(), this->accountList.end(), [](auto a, auto b) { 
        return a.GetName() < b.GetName(); 
    });

    os << "User Portfolios (in alphabetical order):";
    for (unsigned int pos = 0; pos < this->accountList.size(); pos++) {
        UserAccount &user = this->accountList.at(pos);
        
        os << "\n" << user.GetName() << "\'s Portfolio: ";
        if (user.GetPortfolio().at("BTC") > 0) {
            os << user.GetPortfolio().at("BTC") << " BTC, ";
        }
        if (user.GetPortfolio().at("ETH") > 0) {
            os << user.GetPortfolio().at("ETH") << " ETH, ";
        }
        if (user.GetPortfolio().at("USD") > 0) {
            os << user.GetPortfolio().at("USD") << " USD, ";
        }
    }
    os << "\n";
}

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
    UserAccount &taker = GetUser(takerOrder.username);
    UserAccount &maker = GetUser(makerOrder.username);

    UserAccount* buyer;
    UserAccount* seller;

    if (takerOrder.side == "Buy") {
        buyer = &taker;
        seller = &maker;
    } else {
        buyer = &maker;
        seller = &taker;
    }

    int price = takerOrder.price;
    int amountToBuy = std::min(takerOrder.amount, makerOrder.amount);

    buyer->Deposit(takerOrder.asset, amountToBuy);
    seller->Deposit("USD", amountToBuy * price);

    takerOrder.amount -= amountToBuy;
    makerOrder.amount -= amountToBuy;

    Trade newTrade{};
    newTrade.buyer_username = buyer->GetName();
    newTrade.seller_username = seller->GetName();
    newTrade.asset = takerOrder.asset;
    newTrade.amount = amountToBuy;
    newTrade.price = price;
    this->tradeHistory.push_back(newTrade);
}

void Exchange::ProcessTakerOrder(Order& takerOrder) {
    if (takerOrder.side == "Buy") {
        while (takerOrder.amount > 0) {
            int lowestPricePos = getLowestPrice(takerOrder);
            if (lowestPricePos == -1) { break; }

            Order &makerOrder = this->openOrders.at(lowestPricePos);
            Order originalMakerOrder = makerOrder;

            EnactTrade(takerOrder, makerOrder);
            
            if (makerOrder.amount == 0) {
                this->filledOrders.push_back(originalMakerOrder);
                this->openOrders.erase(this->openOrders.begin() + lowestPricePos);
            }
        }
    } 
    if (takerOrder.side == "Sell") {
        while (takerOrder.amount > 0) {
            int highestPricePos = getHighestPrice(takerOrder);
            if (highestPricePos == -1) { break; }
            Order &makerOrder = this->openOrders.at(highestPricePos);
            Order originalMakerOrder = makerOrder;

            EnactTrade(takerOrder, makerOrder);
            
            if (makerOrder.amount == 0) {
                this->filledOrders.push_back(originalMakerOrder);
                this->openOrders.erase(this->openOrders.begin() + highestPricePos);
            }
        }
    } 
}

bool Exchange::AddOrder(Order newOrder) {
    UserAccount& user = GetUser(newOrder.username);

    // If selling price is less than your max price, buy as many as you can
    // If you are selling, sell until you do not have any more assets

    // Price is determined by BUYER (TAKER)

    Order originalOrder = newOrder;

    if (newOrder.side == "Buy") {
        if (user.GetPortfolio().at("USD") >= newOrder.amount * newOrder.price) {
            user.Withdrawal("USD", newOrder.amount * newOrder.price);
        } else {
            return 0;
        }
    } else if (newOrder.side == "Sell") {
        if (user.GetPortfolio().at(newOrder.asset) >= newOrder.amount) {
            user.Withdrawal(newOrder.asset, newOrder.amount);
        } else {
            return 0;
        }
    }
    ProcessTakerOrder(newOrder);
    Order fullfilledOrder = newOrder;
    fullfilledOrder.amount = originalOrder.amount + fullfilledOrder.amount;
        
    if (newOrder.amount > 0) {
        this->openOrders.push_back(newOrder);
        return 1;
    } else {
        this->filledOrders.push_back(fullfilledOrder);
        return 1;
    }
    
    return 0;
}

void Exchange::PrintUsersOrders(std::ostream &os) {
    std::sort(this->accountList.begin(), this->accountList.end(), [](auto a, auto b) { 
        return a.GetName() < b.GetName(); 
    });

    os << "Users Orders (in alphabetical order):";
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
            if (this->filledOrders.at(pos).username == user.GetName()) {
                os << "\n" << this->filledOrders.at(pos);
            }
        }
    }
    os << "\n";
}

void Exchange::PrintTradeHistory(std::ostream &os) {

}

void Exchange::PrintBidAskSpread(std::ostream &os) {

}