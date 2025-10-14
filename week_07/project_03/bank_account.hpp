#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <string>

double round_to_cent(double);
void deposit(double &, double);
bool withdraw(double &, double);
void overdraft(double &, double);
double interest_for_month(double, double);
void string_date_to_ints(std::string, int &, int &, int &);
int number_of_first_of_months(std::string, std::string);
double interest_earned(double, double, std::string, std::string);
std::string process_command(std::string, std::string &, double &, double);
std::string process_commands(std::string, double);

#endif