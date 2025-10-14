#include <iostream>
#include <string>
#include "bank_account.hpp"

int main() {
    std::string line = "2016-09-03 Deposit $400.50";
    std::string previous_date = "2015-09-30";
    double balance = 100.00;
    double apr = 12.0;
    std::string expected = "On 2016-09-03: Instructed to perform \"Deposit $400.50\"\nSince 2015-09-30, interest has accrued 12 times.\n$12.66 interest has been earned.\nBalance: 513.16\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << "Result: " << std::endl << result << std::endl;
    std::cout << (result == expected);
    return 0;
}