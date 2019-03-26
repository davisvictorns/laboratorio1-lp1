#include <iostream>
#include <cstdlib>
#include "Manager.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Manager control;

    control.createCompany("Facebook", "2452");
    control.createCompany("Google", "5345");
    control.createCompany("Amazon", "7547");

    Date AD1(20,6,2018);
    Date AD2(10,12,2018);
    Date AD3(10,6,2017);
    cout<<control.addEmployeeAt("Davis", "8282", 100000.0, AD1, "7547")<<endl;
    cout<<control.addEmployeeAt("Victor", "8102", 100000.0, AD1, "7547")<<endl;
    cout<<control.addEmployeeAt("Nascimento", "1232", 101244.2, AD3, "7547")<<endl;
    cout<<control.addEmployeeAt("Davis", "8282", 150000.0, AD2, "5345")<<endl;
    cout<<control.addEmployeeAt("Davis", "8282", 100000.0, AD3, "7547")<<endl;

    control.seeCompanies();
    control.seeEmployeesAt("Facebook", "");
    control.seeEmployeesAt("", "5345");
    control.seeEmployeesAt("Amazon", "7547");
    
    control.riseEmployeesWageAt("7547", 40.0);
    
    return 0;
}
