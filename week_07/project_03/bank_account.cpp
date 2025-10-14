#include <string>
#include <vector>
#include <iostream>
#include <cmath>

double round_to_cent(double amount) {
    return round(amount * 100) / 100.0;
}

void deposit(double &balance, double amount) {
    balance += amount;
}

bool withdraw(double &balance, double amount) {
    if (balance > amount) {
        balance -= amount;
        return 1;
    }
    return 0;
}

void overdraft(double &balance, double amount) {
    balance -= (amount + 35);
}

double interest_for_month (double balance, double apr) {
    return floor(balance * (apr / 100.0) / 12 * 100.0) / 100.0;
} 

void string_date_to_ints(std::string date, int &year, int &month, int &day) {
    year = std::stoi(date.substr(0, 4));
    month = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));
}

int number_of_first_of_months(std::string early, std::string late) {
    int earlyYear{}, earlyMonth{}, earlyDay{};
    int lateYear{}, lateMonth{}, lateDay{};

    string_date_to_ints(early, earlyYear, earlyMonth, earlyDay);
    string_date_to_ints(late, lateYear, lateMonth, lateDay);

    return (lateYear - earlyYear) * 12 +  lateMonth - earlyMonth;
}

double interest_earned(double balance, double apr, std::string early, std::string late) {
    double originalBalance = balance;
    int numMonths = number_of_first_of_months(early, late);
    for (int pos = 0; pos < numMonths; pos++) {
        balance += interest_for_month(balance, apr);
    }
    return round((balance - originalBalance) * 100) / 100;
}

std::string GetDate(std::string input) {
    std::string date{};
    std::vector<std::string> keywords{"Withdraw", "Deposit"};

    for (unsigned int pos = 0; pos < keywords.size(); pos++) {   
        if (input.find(keywords.at(pos)) != std::string::npos) {
            date = input.substr(0, input.find(keywords.at(pos)) - 1);
        }   
    }
    return date;
}

std::string GetFunction(std::string input) {
    if (input.find("Withdraw") != std::string::npos) {
        return "Withdraw";
    } else if (input.find("Deposit") != std::string::npos) {
        return "Deposit";
    } 
    return "";
}

int GetAmount(std::string input) {
    int amount{}; 
    std::vector<std::string> keywords{"Withdraw", "Deposit"};

    for (unsigned int pos = 0; pos < keywords.size(); pos++) {   
        if (input.find(keywords.at(pos)) != std::string::npos) {
           amount = std::stod(input.substr(input.find(keywords.at(pos)) + 2 + keywords.at(pos).length()));
        }   
    }
    return amount;
}

std::string process_command(std::string line, std::string &date, double &balance, double apr) {
    date = GetDate(line);
    std::string command = line.substr(11);
    int amount = GetAmount(line);
    std::string function = GetFunction(line);

    if (function == "Withdraw") {
        withdraw(balance, amount);
    } 
    else if (function == "Deposit") {
        deposit(balance, amount);
    }
    
    std::cout << round_to_cent(balance) << "\n";
    return "On " + date + ": Instructed to perform \"" + command + "\"\nBalance: " + std::to_string(balance);
}

std::string process_commands (std::string input, int lines) {
    return "";
}