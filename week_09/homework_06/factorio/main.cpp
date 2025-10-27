#include <iostream>

double Centrifuge(int &time, int &ore, double *u_238) {
    double u_235{};
    while (time >= 12 && ore >= 10) {
        time -= 12;
        ore -= 10;
        *u_238 += 0.993;
        u_235 += 0.007;
    }   
    return u_235;
}


int main() {
    int time = 1200;
    int ore = 1000;
    double u_238 = 0;
    double u_235 = Centrifuge(time, ore, &u_238);
    std::cout << time << "\n"; // == 0);
    std::cout << ore << "\n"; // == 0);
    std::cout << std::abs(u_238 - 99.3)  << "\n"; //< 0.001);
    std::cout << std::abs(u_235 - 00.7)  << "\n"; //< 0.001);

    return 0;
}