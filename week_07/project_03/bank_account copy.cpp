#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

std::vector<std::string> ConvertStringToVector(std::string input) {
    std::vector<std::string> inputVector{};
    
    while (input.find("\n") != std::string::npos) {
        inputVector.push_back(input.substr(0, input.find("\n")));
        input = input.substr(input.find("\n") + 1);
    }
    inputVector.push_back(input.substr(0));
    return inputVector;
} 

// std::string GetDate(std::string input) {
//     std::string date{};
//     std::vector<std::string> keywords{"Withdraw", "Deposit"};

//     for (unsigned int pos = 0; pos < keywords.size(); pos++) {   
//         if (input.find(keywords.at(pos)) != std::string::npos) {
//             date = input.substr(0, input.find(keywords.at(pos)) - 1);
//         }   
//     }
//     return date;
// }

// int GetAmount(std::string input) {
//     int amount{}; 
//     std::vector<std::string> keywords{"Withdraw", "Deposit"};

//     for (unsigned int pos = 0; pos < keywords.size(); pos++) {   
//         if (input.find(keywords.at(pos)) != std::string::npos) {
//            amount = std::stod(input.substr(input.find(keywords.at(pos)) + 2 + keywords.at(pos).length())) * 100;
//         }   
//     }
//     return amount;
// }

// std::string GetFunction(std::string input) {
//     if (input.find("Withdraw") != std::string::npos) {
//         return "Withdraw";
//     } else if (input.find("Deposit") != std::string::npos) {
//         return "Deposit";
//     } 
//     return "";
// }
// void AdjustBalance(int &balance, int amount, int direction) {
//     balance += amount * direction;

//     return;
// }

// used https://www.w3schools.com/cpp/ref_math_round.asp
double round_to_cent(double amount) {
    double roundedAmount{};
    roundedAmount = round(amount * 100) / 100.0;
    return roundedAmount;
}

std::string process_commands (std::string input, int lines) {
    std::vector<std::string> inputVector = ConvertStringToVector(input);
    std::cout << round_to_cent(-12.34567);
    // std::string ouput{};
    // int balance{};

    // for (unsigned int pos = 0; pos < inputVector.size() - 1; pos++) {
    //     std::string currentString = inputVector.at(pos);
    //     std::string date = GetDate(currentString);
    //     int amount = GetAmount(currentString) * 100;
    //     std::string function = GetFunction(currentString);

    //     if (function == "Withdraw") {
    //         AdjustBalance(balance, amount, -1);
    //     } else if (function == "Deposit") {
    //         AdjustBalance(balance, amount, 1);
    //     } 

    //     ouput += "On " + date + ": Instructed to perform \"" + function + " $" + ConvertAmountToDollars(amount) + "\"\n";
    // }
    // return ouput;
    return "";
}