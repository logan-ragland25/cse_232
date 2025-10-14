#include <iostream>
#include <string>
#include "bank_account.hpp"

int main() {
    std::string input = 
    "2016-09-02 Deposit $500\n"
    "2016-09-02 Withdraw $23.54\n"
    "2016-09-04 Withdraw $58\n"
    "2016-11-02 Deposit $200\n"
    "2017-03-02 Withdraw $1000\n"
    "2019-11-02 Deposit $5000\n"
    "2020-11-02 Deposit $500\n";
    std::string result = process_commands(input, 7);
    std::string expected = "On 2016-09-02: Instructed to perform \"Deposit $500\"\nBalance: 500.00\nOn 2016-09-02: Instructed to perform \"Withdraw $23.54\"\nBalance: 476.46\nOn 2016-09-04: Instructed to perform \"Withdraw $58\"\nBalance: 418.46\nOn 2016-11-02: Instructed to perform \"Deposit $200\"\nSince 2016-09-04, interest has accrued 2 times.\n$4.89 interest has been earned.\nBalance: 623.35\nOn 2017-03-02: Instructed to perform \"Withdraw $1000\"\nSince 2016-11-02, interest has accrued 4 times.\n$14.65 interest has been earned.\nOverdraft!\nBalance: -397.00\nOn 2019-11-02: Instructed to perform \"Deposit $5000\"\nSince 2017-03-02, interest has accrued 32 times.\n$0.00 interest has been earned.\nBalance: 4603.00\nOn 2020-11-02: Instructed to perform \"Deposit $500\"\nSince 2019-11-02, interest has accrued 12 times.\n$332.69 interest has been earned.\nBalance: 5435.69\n";
    std::cout << "Expected:" << std::endl << expected << std::endl;
    std::cout << "Result:" << std::endl << result << std::endl;
    std::cout << (result == expected);
    return 0;
}