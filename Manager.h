#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <vector>
#include "Date.h"
#include "Employee.h"
#include "Company.h"
using namespace std;

class Manager{
    private:
        vector<Company> companies;
        int companies_count;
    public:
        Manager();

        Company createCompany(string, string); //returns the company created
        void seeCompanies();
        string addEmployeeAt(string, string, float, Date, string); //returns true if added
        void seeEmployeesAt(string, string);
        void riseEmployeesWageAt(string, float);
};

#endif