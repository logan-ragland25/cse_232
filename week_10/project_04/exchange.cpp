#include "exchange.hpp"
#include "useraccount.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

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
    UserAccount &user = GetUser(username);
    return user.Withdrawal(asset, amount);
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

void Exchange::CleanUpVec() {
    for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
        if (this->openOrders.at(pos).side == "DEL") {
            this->openOrders.erase(this->openOrders.begin() + pos);
            pos = 0;
        }
    }
}

void Exchange::CheckTrades() {
    for (unsigned int me = 0; me < this->openOrders.size(); me++) {
        if (this->openOrders.at(me).side == "Buy") {
            for (unsigned int you = 0; you < this->openOrders.size(); you++) {
                if (this->openOrders.at(me).username != this->openOrders.at(you).username && this->openOrders.at(you).side == "Sell" && this->openOrders.at(me).asset == this->openOrders.at(you).asset && this->openOrders.at(me).price >= this->openOrders.at(you).price) {
                    std::string asset = this->openOrders.at(me).asset;
                    // std::cout << this->openOrders.at(me).username << " Should Buy " << this->openOrders.at(me).amount << " " << this->openOrders.at(me).asset <<  " From " << this->openOrders.at(you).username << "\n";
                    UserAccount &myAccount = GetUser(this->openOrders.at(me).username);
                    UserAccount &yourAccount = GetUser(this->openOrders.at(you).username);

                    std::map<std::string, int>& myPortfolio = myAccount.GetPortfolio();
                    std::map<std::string, int>& yourPortfolio = yourAccount.GetPortfolio();

                    // std::cout << yourAccount.GetPortfolio().at(asset) << " >= 0 and " << myAccount.GetPortfolio().at("USD") << " >= " << this->openOrders.at(you).price << "\n";
                    while (yourPortfolio.at(asset) > 0 && myPortfolio.at("USD") >= this->openOrders.at(you).price) {
                        yourPortfolio.at(asset) = yourPortfolio.at(asset) - 1;
                        yourPortfolio.at("USD") = yourPortfolio.at("USD") + this->openOrders.at(you).price;

                        myPortfolio.at("USD") = myPortfolio.at("USD") - this->openOrders.at(you).price;
                        myPortfolio.at(asset) = myPortfolio.at(asset) + 1;
                        
                        std::cout << myAccount.GetName() << " now has " << myPortfolio.at(asset) << " " << asset << ", " << yourAccount.GetName() << " now has " << yourPortfolio.at(asset) << " " << asset << "\n";
                        
                        this->openOrders.at(me).amount -= 1;
                        this->openOrders.at(you).amount -= 1;
                    }
                    // Dolson's Portfolio: 5 BTC, 5055 USD, 
                    // Nahum's Portfolio: 5 BTC, 500 USD
                    this->openOrders.at(you).side = "DEL";
                    this->openOrders.at(me).side = "DEL";
                }
            }
        }
    }
    CleanUpVec();
}

bool Exchange::AddOrder(Order order) {
    UserAccount& user = GetUser(order.username);

    if (order.side == "Buy") {
        if (user.GetPortfolio().at("USD") >= order.amount * order.price) {
            this->MakeWithdrawal(order.username, "USD", order.amount * order.price);
            this->openOrders.push_back(order);
            user.AddOrder(order);
            CheckTrades();
            return 1;
        }
    } else if (order.side == "Sell") {
        if (user.GetPortfolio().at(order.asset) >= order.amount) {
            this->MakeWithdrawal(order.username, order.asset, order.amount);
            this->openOrders.push_back(order);
            user.AddOrder(order);
            CheckTrades();
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
        accountList.at(accountNumber).PrintOrders(os);
    }
    os << "\n";
}

void Exchange::PrintTradeHistory(std::ostream &os) {

}

void Exchange::PrintBidAskSpread(std::ostream &os) {

}