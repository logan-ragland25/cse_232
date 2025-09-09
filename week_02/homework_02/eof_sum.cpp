#include <iostream>
#include <string>
#include <vector>


int main () {
  std::string input {};
  int sum = 0;


  while (std::cin >> input) {
    sum += std::stoi(input);
  } 
  
  std::cout << sum;
  
  return 0;
}