#include "Penultimate.hpp"
#include <string>
#include <cassert>
#include <iostream>

int main() {
    Penultimate p("");
    std::string s = p.push_back("aaa"); 
    std::cout << (s) << "\n";// == "");
    s = p.push_back("aaa"); 
    std::cout << (s) << "\n";// "aaa");
    s = p.push_back("bbb"); 
    std::cout << (s) << "\n";// == "aaa");
    s = p.push_back("ccc"); 
    std::cout << (s) << "\n";// == "bbb");
}