#include <iostream>
#include <sstream>
#include "exchange.hpp"
#include "utility.hpp"

int main() {

    Exchange e;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.PrintUserPortfolios(std::cout);
    std::cout << (!e.MakeWithdrawal("Dolson", "USD", 10)); // Dolson has no portfolio
    std::cout << (!e.MakeWithdrawal("Nahum", "USD", 10)); // Nahum has no USD
    std::cout << (!e.MakeWithdrawal("Nahum", "BTC", 11)); // Nahum doesn't have enough BTC
    std::cout << (e.MakeWithdrawal("Nahum", "BTC", 6)); // Success!
    std::cout << "\n\n";
    std::ostringstream oss;
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    std::cout << (oss.str() == "User Portfolios (in alphabetical order):\nNahum's Portfolio: 4 BTC, \n");
    std::cout << (e.MakeWithdrawal("Nahum", "BTC", 4)); 
    std::cout << "\n\n";
    // Success! Remove the last of the BTC
    // Please note that you shouldn't report assets that have an amount of 0.
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    std::cout << oss.str() << "\nvs\nUser Portfolios (in alphabetical order):\nNahum's Portfolio: \n";
    std::cout << (oss.str() == "User Portfolios (in alphabetical order):\nNahum's Portfolio: \n");
    e.MakeDeposit("Dolson", "BTC", 4);
    e.MakeDeposit("Dolson", "USD", 4000);
    e.MakeDeposit("Ofria", "ETH", 77);
    std::cout << (e.MakeWithdrawal("Dolson", "BTC", 1)); 
    std::cout << (e.MakeWithdrawal("Dolson", "USD", 4000)); 
    std::cout << (!e.MakeWithdrawal("Ofria", "BTC", 1)); 
    std::cout << (!e.MakeWithdrawal("Ofria", "Apples", 1)); 
    std::cout << "\n\n";
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    std::cout << (oss.str() == "User Portfolios (in alphabetical order):\nDolson's Portfolio: 3 BTC, \nNahum's Portfolio: \nOfria's Portfolio: 77 ETH, \n");




//   Exchange msu_base;
//   msu_base.MakeDeposit("Nahum", "USD", 1000);
//   msu_base.MakeDeposit("Nahum", "ETH", 400);
//   msu_base.MakeDeposit("Dolson", "BTC", 100);
//   msu_base.MakeDeposit("Dolson", "USD", 7000);
//   msu_base.MakeDeposit("Enbody", "USD", 7000);
//   msu_base.MakeDeposit("Ofria", "BCH", 9);
//   msu_base.MakeWithdrawal("Dolson", "BTC", 10);
//   msu_base.PrintUserPortfolios(std::cout);
//   std::cout << std::endl;
//   Order o_n{"Nahum", "Buy", "BTC", 2, 22};
//   Order o_d{"Dolson", "Sell", "BTC", 3, 17};
//   std::cout << "Before 1st add order" << std::endl;

//   msu_base.AddOrder(o_n);
//   std::cout << "After 1st add order" << std::endl;
//   msu_base.PrintUsersOrders(std::cout);

//   std::cout << std::endl;

//   std::cout << "Before 2nd add order" << std::endl;

//   msu_base.AddOrder(o_d);

//   std::cout << "After 2nd add order" << std::endl;

//   msu_base.PrintTradeHistory(std::cout);
//   std::cout << std::endl;
//   msu_base.PrintUserPortfolios(std::cout);
//   std::cout << std::endl;
//   msu_base.PrintUsersOrders(std::cout);
//   std::cout << std::endl;
//   msu_base.AddOrder({"Dolson", "Buy", "ETH", 10, 200});
//   msu_base.AddOrder({"Enbody", "Buy", "ETH", 15, 300});
//   msu_base.AddOrder({"Nahum", "Sell", "ETH", 20, 100});

//   msu_base.PrintTradeHistory(std::cout);
//   msu_base.PrintUsersOrders(std::cout);
//   msu_base.AddOrder({"Nahum", "Sell", "ETH", 20, 1000});
//   msu_base.AddOrder({"Dolson", "Sell", "ETH", 2, 250});
//   msu_base.AddOrder({"Enbody", "Buy", "BTC", 1, 10});
//   msu_base.PrintTradeHistory(std::cout);
//   msu_base.PrintUserPortfolios(std::cout);
//   std::cout << std::endl << std::endl;
//   msu_base.PrintUsersOrders(std::cout);
//   msu_base.AddOrder({"Enbody", "Buy", "LTC", 1, 10});
//   msu_base.AddOrder({"Ofria", "Sell", "BCH", 2, 55});
//   msu_base.PrintBidAskSpread(std::cout);

  return 0;
}