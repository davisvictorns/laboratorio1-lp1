#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include "Date.h"
using namespace std;

class Employee{
    private:
        string name;
        string cpf; //That way we can make the employee unique
        float wage;
        Date admission_date;
    public:
        Employee();
        Employee(string& name_, string& cpf_, float& wage_, Date& admission_date_);

        string getName();
        string getCpf();
        Date getAdmissionDate();
    
};

bool operator == (const string&, const string&);

#endif