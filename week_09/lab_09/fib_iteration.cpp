#include <iostream>
#include <chrono>
#include <sys/resource.h>

void print_memory_usage(){
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cout << "Memory usage: " << usage.ru_maxrss << " KB\n";
}

int fib(int inputValue) {
    if (inputValue == 0) {
        return 0;
    }
    if (inputValue == 1) {
        return 1;
    }

    int pos{0};
    int value{0};
    int temp1{0};
    int temp2{1};
    while (pos < inputValue - 1) {
        value = temp1 + temp2;
        temp1 = temp2;
        temp2 = value;
        pos++;
    }
    return value;
}


int main() {
    //define clock type
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> duration;

    //start timing
    start = std::chrono::high_resolution_clock::now();

    // your c++ code that needs timing
    std::cout << fib(45) << "\n";

    //end timing
    end = std::chrono::high_resolution_clock::now();

    //calculate duration
    duration = std::chrono::duration<double>(end - start);

    //display duration
    std::cout << duration.count() << "\n";

    print_memory_usage();

    return 0;
}