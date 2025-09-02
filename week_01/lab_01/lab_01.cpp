#include <iostream>
#include <iomanip>

int main()
{
  double initialdistanceAU = 37.33;
  double initialdistanceKM = initialdistanceAU * 149598000;
  double initialdistanceMI = initialdistanceAU * 92955800;
  double speedoflightKM = 299792458/(1000);
  double secondsperhour = 3600;
  double speedofprobeKMperday = 1238112;
  double speedofprobeMIperday = 768960;
  int days {};

  std::cin >> days;

  std::cout << std::fixed << std::setprecision(2);

  double finaldistanceKM = initialdistanceKM + (days * speedofprobeKMperday);
  double finaldistanceMI = initialdistanceMI + (days * speedofprobeMIperday);
  double commstime = (finaldistanceKM * 2) / (speedoflightKM*secondsperhour);
  std::cout << finaldistanceKM << "\n" << finaldistanceMI << "\n"
  << commstime << "\n";
}