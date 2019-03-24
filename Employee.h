#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include "Date.h"
using namespace std;

class Employee{
    private:
        string name;
        float wage;
        Date admission_date;
    public:
        Employee();
    
};

#endif