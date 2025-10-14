#include <iostream>
#include <string>
#include "bank_account.hpp"

int main() {
    std::string line = "2015-09-03 Deposit $100";
    std::string previous_date = "2015-09-02";
    double balance = 10.00;
    double apr = 12.0;
    std::string expected = "On 2015-09-03: Instructed to perform \"Deposit $100\"\nBalance: 110.00\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << result << std::endl;
    std::cout << (balance == 110.00) << "\n";
    std::cout << (previous_date == "2015-09-03") << "\n";
    std::cout << (result == expected) << "\n";
    return 0;
}