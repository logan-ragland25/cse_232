#include <iostream>
#include "Measurement.hpp"
int main() {
    Measurement m_1(22.00, 0.03, "m");
    Measurement m_2{m_1.RaisedToPower(2)};
    std::cout << (m_2.ToString() == "4.84e+02 +- 1.32e+00 m^2 ");
    Measurement m_3(10.88, 0.4, "sec");
    Measurement m_4{m_3.RaisedToPower(-7)};
    std::cout << (m_4.ToString() == "5.54e-08 +- 1.43e-08 sec^-7 ");
    Measurement m_5(12.88, 0.4, "sec");
    Measurement m_6{m_5.RaisedToPower(3)};
    std::cout << (m_6.ToString() == "2.14e+03 +- 1.99e+02 sec^3 ");
    Measurement m_7(12.88, 0.4, "sec");
    Measurement m_8{m_7.RaisedToPower(0)};
    std::cout << (m_8.ToString() == "1.00e+00 +- 0.00e+00 ");
    Measurement m_9(12.88, 0.4, "sec");
    Measurement m_10{m_9.RaisedToPower(1)};
    std::cout << (m_10.ToString() == "1.29e+01 +- 4.00e-01 sec ");
    Measurement m_11(2.88, 0.04, "josh");
    Measurement m_12{m_1.RaisedToPower(4)};
    std::cout << (m_12.ToString() == "2.34e+05 +- 1.28e+03 m^4 ");
//   Measurement m_1{2.00, 0.03, "sec"};
//   std::cout << m_1.ToString() << std::endl;
//   // 2.00e+00 +- 3.00e-02 sec

//   Measurement m_2{0.88, 0.04, "sec"};
//   Measurement m_3{m_1.Add(m_2)};
//   std::cout << m_3.ToString() << std::endl;
//   // 2.88e+00 +- 5.00e-02 sec

//   Measurement m_4{120.0, 3.0, "m"};
//   Measurement m_5{20.0, 1.2, "sec"};
//   Measurement m_6{m_4.Divide(m_5)};
//   std::cout << m_6.ToString() << std::endl;
//   // 6.00e+00 +- 3.90e-01 m sec^-1

//   Measurement m_7{0.20, 0.01, "sec"};
//   Measurement m_8{m_7.RaisedToPower(2)};
//   std::cout << m_8.ToString() << std::endl;
//   // 4.00e-02 +- 4.00e-03 sec^2

//   Measurement m_9{120.0, 3.0, "m"};
//   Measurement m_10{20.0, 1.2, "m"};
//   Measurement m_11{m_9.Add(m_10)};
//   Measurement m_12{14.0, .2, "sec"};
//   Measurement m_13{m_11.Divide(m_12)};
//   std::cout << m_13.ToString() << std::endl;
//   // 1.00e+01 +- 2.71e-01 m sec^-1

//   Measurement m_14{m_1.Multiply(m_13)};
//   Measurement m_15{200.0, .2, "l"};
//   Measurement m_16{m_15.RaisedToPower(-2)};
//   Measurement m_17{m_16.Divide(m_14)};
//   std::cout << m_17.ToString() << std::endl;
//   // 1.25e-06 +- 3.88e-08 l^-2 m^-1
}