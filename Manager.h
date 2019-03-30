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

        Company createCompany(string name, string cnpj); //returns the company created
        void seeCompanies();
        string addEmployeeAt(string name_, string cpf_, float wage_, Date admission_date_, string company_cnpj); //returns true if added
        void seeEmployeesAt(string company_name, string company_cnpj);
        void riseEmployeesWageAt(string company_cnpj, float amount);
        void employeesAdmittedDaysAgo(string company_cnpj, int days);
        void meanEmployeesByCompany();
};

#endif