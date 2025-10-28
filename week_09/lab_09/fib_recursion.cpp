#include <iostream>
#include <chrono>
#include <sys/resource.h>

void print_memory_usage(){
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  std::cout << "Memory usage: " << usage.ru_maxrss << " KB\n";
}


int fib(int pos) {
    if (pos == 0) {
        return 0;
    } 
    if (pos == 1) {
        return 1;
    }
    if (pos > 1) {
        return fib(pos - 1) + fib(pos - 2);
    }
    return -1;
}


int main() {
    
    print_memory_usage();
    //define clock type
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> duration;

    //start timing
    start = std::chrono::high_resolution_clock::now();

    // your c++ code that needs timing
    std::cout << fib(10) << "\n";

    //end timing
    end = std::chrono::high_resolution_clock::now();

    //calculate duration
    duration = std::chrono::duration<double>(end - start);

    //display duration
    std::cout << duration.count() << "\n";
    

    print_memory_usage();

    return 0;
}