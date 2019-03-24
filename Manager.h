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
};

#endif