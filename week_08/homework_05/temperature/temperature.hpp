#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
    #include <string>
    #include <iostream>

    class Temperature {
        private:
            double celsius{};

            double convertToCelsius(double value, char c) {
              if (c == 'C') {
                return value;
              } else if (c == 'F') {
                return (value - 32) / 1.8;
              } else if (c == 'R') {
                return (value -  491.67) * (5.0/9);
              } else if (c == 'K') {
                return value - 273.15;
              }
              return -1;
            }

        public:
            Temperature (double value, char unit) {
              this->celsius = convertToCelsius(value, unit);
              std::cout << "Celsius Value: " << this->celsius << "\n";
            }

            double AsCelsius () {
              return this->celsius;
            }

            double AsFahrenheit () {
              return this->celsius * 1.8 + 32;
            }
            
            double AsKelvin () {
              return this->celsius + 273.15;
            }

            double AsRankine () {
              return (this->celsius + 273.15) * 1.8;
            }
    };

#endif