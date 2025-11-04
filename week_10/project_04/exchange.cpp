#include "exchange.hpp"
#include "useraccount.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void Exchange::MakeDeposit(std::string username, std::string asset, int amount) {
    int position{-1};
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == username) {
            position = pos;
        }
    }
    if (position == -1) {
        accountList.push_back(UserAccount(username));
        position = this->accountList.size() - 1;
    }
    
    this->accountList.at(position).Deposit(asset, amount);
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

bool Exchange::MakeWithdrawal(std::string username, std::string asset, int amount) {
    int position{-1};
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == username) {
            position = pos;
        }
    }
    if (position == -1) {
        return 0;
    }
    
    return this->accountList.at(position).Withdrawal(asset, amount);
}

bool Exchange::AddOrder(Order order) {
    int position{-1};
    for (unsigned pos = 0; pos < this->accountList.size(); pos++) {
        if (this->accountList.at(pos).GetName() == order.username) {
            position = pos;
            break;
        }
    }
    if (position == -1) {
        return 0;
    }

    UserAccount& user = this->accountList.at(position);

    if (order.side == "Buy") {
        if (user.GetPortfolio().at("USD") >= order.amount * order.price) {
            this->MakeWithdrawal(order.username, "USD", order.amount * order.price);
            this->openOrders.push_back(order);
            return 1;
        }
    } else if (order.side == "Sell") {
        if (user.GetPortfolio().at(order.asset) >= order.amount) {
            this->MakeWithdrawal(order.username, order.asset, order.amount);
            this->openOrders.push_back(order);
            return 1;
        }
    }
    
    return 0;
}

void Exchange::PrintUsersOrders(std::ostream &os) {
    std::sort(this->accountList.begin(), this->accountList.end(), [](auto a, auto b) { 
        return a.GetName() < b.GetName(); 
    });

    os << "Users Orders (in alphabetical order):";
    for (unsigned int accountNumber = 0; accountNumber < this->accountList.size(); accountNumber++) {
        os << "\n" << this->accountList.at(accountNumber).GetName() << "\'s Open Orders (in chronological order):";
        for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
            if (this->openOrders.at(pos).username == this->accountList.at(accountNumber).GetName()) {
                os << "\n" << this->openOrders.at(pos).side << " " << this->openOrders.at(pos).amount << " " << this->openOrders.at(pos).asset << " at " << this->openOrders.at(pos).price << " USD by " << this->openOrders.at(pos).username;
            }
        }
        os << "\n" <<  this->accountList.at(accountNumber).GetName() << "\'s Filled Orders (in chronological order):";
    }
    os << "\n";
}
//"Users Orders (in alphabetical order):
//\nDolson's Open Orders (in chronological order):
//\nDolson's Filled Orders (in chronological order):
//\nNahum's Open Orders (in chronological order):
//\nNahum's Filled Orders (in chronological order):
//\nOfria's Open Orders (in chronological order):
//\nOfria's Filled Orders (in chronological order):\n"

void Exchange::PrintTradeHistory(std::ostream &os) {

}

void Exchange::PrintBidAskSpread(std::ostream &os) {

}