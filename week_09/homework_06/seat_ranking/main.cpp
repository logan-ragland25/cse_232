#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<std::string>> AddRows() {
    std::vector<std::vector<std::string>> output{};
    int value = 55;
    
    for (int row = 0; row < 10; row++) {
        std::vector<std::string> rowVec{};
        for (int pos = 0; pos < 20; pos++) {
            rowVec.push_back(std::to_string(value));
        }
        value += 5;
        output.push_back(rowVec);
    }
    return output;
}

std::string ConvertCoordsToVecPos(std::string coords) {
    int commaLocation = coords.find(",");
    std::string row = coords.substr(1, commaLocation - 1);
    std::string col = coords.substr(commaLocation + 1, coords.find(")") - commaLocation - 1);

    return "(" + std::to_string(9 - std::stoi(col)) + "," + row + ")";
}

void AddSeat(int rowPos, int colPos, std::vector<std::vector<std::string>> &seats) {
    seats.at(rowPos).at(colPos) = " *";

    // Adjacant
    if (rowPos > 0) { if (seats.at(rowPos - 1).at(colPos) != " *") { seats.at(rowPos - 1).at(colPos) = std::to_string(std::stoi(seats.at(rowPos - 1).at(colPos)) - 40); }}
    if (rowPos < 9) { if (seats.at(rowPos + 1).at(colPos) != " *") { seats.at(rowPos + 1).at(colPos) = std::to_string(std::stoi(seats.at(rowPos + 1).at(colPos)) - 40); } }
        
    if (colPos > 0) { if (seats.at(rowPos).at(colPos - 1) != " *") { seats.at(rowPos).at(colPos - 1) = std::to_string(std::stoi(seats.at(rowPos).at(colPos - 1)) - 40); } }
    if (colPos < 19) { if (seats.at(rowPos).at(colPos + 1) != " *") { seats.at(rowPos).at(colPos + 1) = std::to_string(std::stoi(seats.at(rowPos).at(colPos + 1)) - 40); } }

    // Two Away Adjacant
    if (rowPos > 1) { if (seats.at(rowPos - 2).at(colPos) != " *") { seats.at(rowPos - 2).at(colPos) = std::to_string(std::stoi(seats.at(rowPos - 2).at(colPos)) - 20); } }
    if (rowPos < 8) { if (seats.at(rowPos + 2).at(colPos) != " *") { seats.at(rowPos + 2).at(colPos) = std::to_string(std::stoi(seats.at(rowPos + 2).at(colPos)) - 20); } }

    if (colPos > 1) { if (seats.at(rowPos).at(colPos - 2) != " *") { seats.at(rowPos).at(colPos - 2) = std::to_string(std::stoi(seats.at(rowPos).at(colPos - 2)) - 20); } }
    if (colPos < 18) { if (seats.at(rowPos).at(colPos + 2) != " *") { seats.at(rowPos).at(colPos + 2) = std::to_string(std::stoi(seats.at(rowPos).at(colPos + 2)) - 20); } }

    
    //Diagnols
    if (rowPos > 0 && colPos > 0) { if (seats.at(rowPos - 1).at(colPos - 1) != " *") { seats.at(rowPos - 1).at(colPos - 1) = std::to_string(std::stoi(seats.at(rowPos - 1).at(colPos - 1)) - 20); } }
    if (rowPos > 0 && colPos < 19) { if (seats.at(rowPos - 1).at(colPos + 1) != " *") { seats.at(rowPos - 1).at(colPos + 1) = std::to_string(std::stoi(seats.at(rowPos - 1).at(colPos + 1)) - 20); } }

    if (rowPos < 9 && colPos > 0) { if (seats.at(rowPos + 1).at(colPos - 1) != " *") { seats.at(rowPos + 1).at(colPos - 1) = std::to_string(std::stoi(seats.at(rowPos + 1).at(colPos - 1)) - 20); } }
    if (rowPos < 9 && colPos < 19) { if (seats.at(rowPos + 1).at(colPos + 1) != " *") { seats.at(rowPos + 1).at(colPos + 1) = std::to_string(std::stoi(seats.at(rowPos + 1).at(colPos + 1)) - 20); } }
    
}


int main() {
    std::ifstream file {"input.txt"};

    std::vector<std::vector<std::string>> seats = AddRows();
    std::string input{};
    while (std::getline(std::cin, input)) {
        std::string convertedInput = ConvertCoordsToVecPos(input);
        int commaLocation = convertedInput.find(",");

        std::string row = convertedInput.substr(1, commaLocation - 1);
        std::string col = convertedInput.substr(commaLocation + 1, convertedInput.find(")") - commaLocation - 1);
        AddSeat(std::stoi(row), std::stoi(col), seats);
    }
    

    for (unsigned int i = 0; i < seats.size(); ++i) {
        for (unsigned int j = 0; j < seats[i].size(); ++j) {
            if (seats[i][j].length() == 1) {
                std::cout << "   " << seats[i][j] << ",";
            } else if (seats[i][j].length() == 2) {
                std::cout << "  " << seats[i][j] << ",";
            } else if (seats[i][j].length() == 3) {
                std::cout << " " << seats[i][j] << ",";
            } else {
                std::cout << seats[i][j] << ",";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
