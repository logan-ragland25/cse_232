#include <iostream>
#include <chrono>
#include <sys/resource.h>

void print_memory_usage(){
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cout << "Memory usage: " << usage.ru_maxrss << " KB\n";
}

int factorialIterative(int num) {
    int total{1};
    while (num > 0) {
        total *= num;
        num--;
    }
    return total;
}

int factorialRecursive(int num) {
    if (num == 1) {
        return 1;
    }
    return num * factorialRecursive(num-1);
}

int main() {
    int num = 40;
    //define clock type
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> duration;

    //start timing
    start = std::chrono::high_resolution_clock::now();

    // your c++ code that needs timing
    std::cout << factorialIterative(num) << "\n";

    //end timing
    end = std::chrono::high_resolution_clock::now();

    //calculate duration
    duration = std::chrono::duration<double>(end - start);

    //display duration
    std::cout << duration.count() << "\n";

    print_memory_usage();

    std::cout << "----------------------\n";

    //start timing
    start = std::chrono::high_resolution_clock::now();

    // your c++ code that needs timing
    std::cout << factorialRecursive(num) << "\n";

    //end timing
    end = std::chrono::high_resolution_clock::now();

    //calculate duration
    duration = std::chrono::duration<double>(end - start);

    //display duration
    std::cout << duration.count() << "\n";

    print_memory_usage();

    

    return 0;
}