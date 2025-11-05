#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "useraccount.hpp"
#include "utility.hpp"

class Exchange {
    private:
        std::vector<UserAccount> accountList{};
        std::vector<Order> openOrders{};
        std::vector<Order> filledOrders{};
        std::vector<Trade> tradeHistory{};
    public:
        void MakeDeposit(std::string username, std::string asset, int amount);
        void PrintUserPortfolios(std::ostream &os);
        bool MakeWithdrawal(std::string username, std::string asset, int amount);
        bool AddOrder(Order order);
        void PrintUsersOrders(std::ostream &os);
        void PrintTradeHistory(std::ostream &os);
        void PrintBidAskSpread(std::ostream &os);
        UserAccount& GetUser(std::string name);
        void ProcessTakerOrder(Order &takerOrder);
        int getLowestPrice(Order &order);
        int getHighestPrice(Order &order);
        void EnactTrade(Order &takerOrder, Order &makerOrder);
        bool UserExists(std::string name);
        void Cleave();
};