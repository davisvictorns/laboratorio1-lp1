#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <string>
#include <vector>
#include "Date.h"
#include "Employee.h"
using namespace std;

class Company{
    private:
        string name;
        string cnpj;
        vector<Employee> employees;
        int employees_count;
    public:
        Company();
        Company(string&, string&);

        string getName();
        string getCnpj();
        bool addEmployee(string&, string&, float&, Date&);
        void seeEmployees();
        void riseEmployeesWage(float&);
};

#endif