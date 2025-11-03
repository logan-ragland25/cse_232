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
        UserAccount user = this->accountList.at(pos);
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
    return -1;
}

bool Exchange::AddOrder(Order order) {
    return -1;
}

void Exchange::PrintUsersOrders(std::ostream &os) {

}

void Exchange::PrintTradeHistory(std::ostream &os) {

}

void Exchange::PrintBidAskSpread(std::ostream &os) {

}