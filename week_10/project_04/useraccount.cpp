#include "useraccount.hpp"
#include "exchange.hpp"

#include <string>
#include <map>

UserAccount::UserAccount(std::string name) {
    this->name = name;
    this->portfolio = {{"BTC", 0}, {"USD", 0}, {"ETH", 0}};
}

//https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
void UserAccount::Deposit(std::string asset, int amount) {
    if(this->portfolio.count(asset)) {
        this->portfolio.at(asset) = this->portfolio.at(asset) + amount;
    } 

}

std::string UserAccount::GetName() {
    return this->name;
}

bool UserAccount::Withdrawal(std::string asset, int amount) {
    if (this->portfolio.count(asset)) {
        if (this->portfolio.at(asset) >= amount) {
            this->portfolio.at(asset) -= amount;
            return 1;
        }
    }
    return 0;
}

bool UserAccount::AddOrder(Order order) {
    return -1;
}

void UserAccount::PerformBuy(Order buy_order, Trade trade) {

}

void UserAccount::PerformSell(Order sell_order, Trade trade) {

}

std::map<std::string, int> UserAccount::GetPortfolio() {
    return this->portfolio;
}

std::vector<Order> UserAccount::GetOpenOrders() {
    return std::vector<Order>{};
}

void UserAccount::PrintOrders(std::ostream &os) {
    
}