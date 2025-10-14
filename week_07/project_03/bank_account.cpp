#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>

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

double GetAmount(std::string input) {
    std::string stringAmount{};

    if (input.find("Withdraw") != std::string::npos) {
        stringAmount = input.substr(21);
    } else if (input.find("Deposit") != std::string::npos) {
        stringAmount = input.substr(20);
    }
    double amount = std::stod(stringAmount);

    return amount;

}

std::string CutDecimals(double input) {
    std::string value = std::to_string(input);
    if (value.find('.') != std::string::npos) {
        value = value.substr(0, value.find('.') + 3);
    }
    else {
        value.append(".00");
    }
    return value;
}

std::string process_command(std::string line, std::string &date, double &balance, double apr) {
    int elapsedMonths{};
    std::string currentDate = GetDate(line);
    double interestEarned{};

    if (date == "") {
        elapsedMonths = 0;
        interestEarned = 0;
    } else {
        elapsedMonths = number_of_first_of_months(date, currentDate);
        if (balance > 0) {
            interestEarned = interest_earned(balance, apr, date, currentDate);
        }
    }

    std::string command = line.substr(11);
    double amount = GetAmount(line);
    std::string function = GetFunction(line);

    std::stringstream output; 
    output << "On " << currentDate << ": Instructed to perform \"" << command << "\"\n";

    
    if (elapsedMonths > 0) {
        output << "Since " << date << ", interest has accrued " << elapsedMonths << " times.\n$" << CutDecimals(interestEarned) << " interest has been earned.\n";
    } 

    
    if (function == "Withdraw") {
        if (balance > amount) {
            withdraw(balance, amount);
        } else {
            overdraft(balance, amount);
            output << "Overdraft!\n";
        }
    } 
    else if (function == "Deposit") {
        deposit(balance, amount);
    }

    balance += interestEarned;

    date = currentDate;

    output << "Balance: " << CutDecimals(balance) << "\n";
    return output.str();
}

std::vector<std::string> ConvertStringToVector(std::string input) {
    std::vector<std::string> inputVector{};
    
    while (input.find("\n") != std::string::npos) {
        inputVector.push_back(input.substr(0, input.find("\n")));
        input = input.substr(input.find("\n") + 1);
    }
    inputVector.push_back(input.substr(0));
    return inputVector;
} 

std::string process_commands (std::string input, double apr) {
    double balance = 0;
    std::string date{};

    std::stringstream output; 
    std::vector stringVector = ConvertStringToVector(input);
    for (unsigned int pos = 0; pos < stringVector.size() - 1; pos++) {
        output << process_command(stringVector.at(pos), date, balance, apr);
    }
    return output.str();
}
