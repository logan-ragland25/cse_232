/*Write a program in SmallestDiff/main.cpp that reads three integers from the standard input stream. 
Print the smallest difference between the three. For example, if the three numbers are 1, 10, and 100, 
the smallest difference is 9 (10 - 1), as (100 - 1) and (100 - 10) are both larger than 9. be sure your 
solution also works if some/all of the numbers are negative.
*/
#include <iostream>

int main() {
    int input_a {};
    int input_b {}; 
    int input_c {};  


    std::cin >> input_a >> input_b >> input_c;

    int largest, middle, smallest, smallest_difference;

    if (input_a > input_b && input_a > input_c) {
        largest = input_a;
        if (input_b > input_c) {
            middle = input_b;
            smallest = input_c;
        }
        else {
            middle = input_c;
            smallest = input_b;
        }
    }
    else if (input_b > input_a && input_b > input_c) {
        largest = input_b;
        if (input_a > input_c) {
            middle = input_a;
            smallest = input_c;
        }
        else {
            middle = input_c;
            smallest = input_a;
        }
    }
    else if (input_c > input_a && input_c > input_b) {
        largest = input_c;
        if (input_a > input_b) {
            middle = input_a;
            smallest = input_b;
        }
        else {
            middle = input_b;
            smallest = input_a;
        }
    }
    else {
        smallest_difference = 0;
    }
    
    if (smallest_difference != 0) {
        int diff_lm = largest - middle;
        int diff_ls = largest - smallest;
        int diff_ms = middle - smallest;

        smallest_difference = diff_lm;

        if (smallest_difference > diff_lm) {
            smallest_difference = diff_lm;
        }
        if (smallest_difference > diff_ms) {
            smallest_difference = diff_ms;
        }
    }

    //std::cout << "Largest " << largest << "\nMiddle: " << middle << "\nSmallest: " << smallest << "\n"; 
    std::cout << "The smallest diff of " << input_a << ", " << input_b << ", and " << input_c << " is " << smallest_difference << ".";
}
