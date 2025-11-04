#include "useraccount.hpp"
#include "exchange.hpp"

#include <string>
#include <map>
#include <sstream>

// Constructor
UserAccount::UserAccount(std::string name) {
    this->name = name;
    this->portfolio = {{"BTC", 0}, {"USD", 0}, {"ETH", 0}};
}


//Dont need trades
//https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
void UserAccount::Deposit(std::string asset, int amount) {
    if(this->portfolio.count(asset)) {
        this->portfolio.at(asset) = this->portfolio.at(asset) + amount;
    } 
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

// Need trades
bool UserAccount::AddOrder(Order order) {
    this->openOrders.push_back(order);
    return 1;
}

void UserAccount::PerformBuy(Order buy_order, Trade trade) {

}

void UserAccount::PerformSell(Order sell_order, Trade trade) {

}

void UserAccount::PrintOrders(std::ostream &os) {
    os << "\n" << this->name << "\'s Open Orders (in chronological order):";
    for (unsigned int pos = 0; pos < this->openOrders.size(); pos++) {
        os << "\n" << this->openOrders.at(pos).side << " " << this->openOrders.at(pos).amount << " " << this->openOrders.at(pos).asset << " at " << this->openOrders.at(pos).price << " USD by " << this->name;
    }
    os << "\n" <<  this->name << "\'s Filled Orders (in chronological order):";
}

// Getters
std::string UserAccount::GetName() {
    return this->name;
}

std::map<std::string, int> UserAccount::GetPortfolio() {
    return this->portfolio;
}

std::vector<Order> UserAccount::GetOpenOrders() {
    return std::vector<Order>{};
}
