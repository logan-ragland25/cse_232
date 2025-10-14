#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::string Two_D_Vector_To_String(std::vector<std::vector<char>> vec){
  std::stringstream os;
  for(int i = 0; i < static_cast<int>(vec.size()); i++){
    for(int j = 0; j < static_cast<int>(vec.at(i).size()); j++){
      os << vec.at(i).at(j) << " ";
    }
    os << "\n";
  }
  return os.str();
}

std::vector<std::vector<char>> CreateVector (int size) {
    std::vector<std::vector<char>> outer {};
    std::vector<char> inner {static_cast<char>(0)};

    for (int pos = 0; pos < size; pos++) {
        inner.push_back('?');
    }

    for (int pos = 0; pos < size; pos++){
        outer.push_back(inner);
    }
    return outer;
}  

// std::vector<std::vector<char>> Right(std::vector<std::vector<char>> vector, int count, int &rowPos, int &colPos, int number) {
//     for (int pos = 0; pos < count; pos++) {
//         colPos++;
//         vector.at(rowPos).at(colPos) = number;
//         number++;
//         //vector.at(rowPos).at(colPos + pos + 1) = number;
//         std::cout << "Value: " << vector.at(rowPos).at(colPos) << "\n";
//     }
//     return vector;
// }

int main() {
    int sizeOfVector = 5;
    std::vector<std::vector<char>> vector = CreateVector(sizeOfVector);
    int center = vector.size() / 2;


    std::string numbers = {"0123456789"};

    int direction = 0;
    int currentStep = 0;
    int maxStep = 1;
    int value = 1;
    int timesAtMaxStep = 0;

    vector.at(center).at(center) = '0';

    int x = center;
    int y = center;
    
    while (x < sizeOfVector && y < sizeOfVector) {
        while (currentStep < maxStep) {
            value %= 10;
            if (direction == 0) {
                x++;
                vector.at(y).at(x) = numbers.at(value);
                value++;
                currentStep++;
            }
            if (direction == 1) {
                y--;
                vector.at(y).at(x) = numbers.at(value);
                value++;
                currentStep++;
            }
            if (direction == 2) {
                x--;
                vector.at(y).at(x) = numbers.at(value);
                value++;
                currentStep++;
            }
            if (direction == 3) {
                y++;
                vector.at(y).at(x) = numbers.at(value);
                value++;
                currentStep++;
            }
        } 
        direction++;
        if (direction == 4) {
            direction = 0;
        }
        currentStep = 0;
        timesAtMaxStep++;
        if (timesAtMaxStep == 2) {
            timesAtMaxStep = 0;
            maxStep++;
        } 
        std::cout << Two_D_Vector_To_String(vector) << "\n";
    }
}