#include <iostream>
#include <string>

int main() {

  int value_a {}; 
  int value_b {};
  std::string unit_a {};
  std::string unit_b {};

  std::cin >> value_a >> unit_a >> value_b >> unit_b;

  // "10mm 14cm" becomes value_a = 10, value_b = 14, unit_a = "mm", unit_b = "cm"
  // WRITE YOUR CODE HERE
  int converted_a {};
  int converted_b {};

  if (unit_a == "cm") {
    converted_a = value_a * 10;
  }
  else if (unit_a == "m") {
    converted_a = value_a * 1000;
  }
  else if (unit_a == "km") {
    converted_a = value_a * 100000;
  }
  else {
    converted_a = value_a;
  }

  if (unit_b == "cm") {
    converted_b = value_b * 10;
  }
  else if (unit_b == "m") {
    converted_b = value_b * 1000;
  }
  else if (unit_b == "km") {
    converted_b = value_b * 100000;
  }
  else {
    converted_b = value_b;
  }

  if (converted_a > converted_b) {
    std::cout << value_a << unit_a << " is larger than " << value_b << unit_b << "\n";
  }
  else if (converted_a < converted_b) {
    std::cout << value_a << unit_a << " is smaller than " << value_b << unit_b << "\n";
  }
  else {
    std::cout << value_a << unit_a << " is the same as " << value_b << unit_b << "\n";
  } 
}

