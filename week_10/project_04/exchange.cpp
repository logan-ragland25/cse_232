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
            this->openBuyOrders.push_back(order);
            return 1;
        }
    } else if (order.side == "Sell") {
        if (user.GetPortfolio().at(order.asset) >= order.amount) {
            this->MakeWithdrawal(order.username, order.asset, order.amount);
            this->openSellOrders.push_back(order);
            return 1;
        }
    }
    
    return 0;
}

void Exchange::PrintUsersOrders(std::ostream &os) {

}

void Exchange::PrintTradeHistory(std::ostream &os) {

}

void Exchange::PrintBidAskSpread(std::ostream &os) {

}