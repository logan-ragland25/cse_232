#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utility.hpp"

class UserAccount {
    private:
        std::string name;
        std::map<std::string, int> portfolio;
        std::vector<Order> openOrders;
    public:
        // Constructor
        UserAccount(std::string name); //*

        // Free of Trading
        void Deposit(std::string asset, int amount); // *
        bool Withdrawal(std::string assert, int amount); // *

        // Involves Trading
        bool AddOrder(Order order);
        void PerformBuy(Order buy_order, Trade trade);
        void PerformSell(Order sell_order, Trade trade);
        void PrintOrders(std::ostream &os);

        // Getters
        std::string GetName(); // *
        std::map<std::string, int> GetPortfolio(); // *
        std::vector<Order> GetOpenOrders(); // *
};