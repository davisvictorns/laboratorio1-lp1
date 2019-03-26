#include "Employee.h"

Employee::Employee(string& name_, string& cpf_, float& wage_, Date& admission_date_){
    name = name_;
    cpf = cpf_;
    wage = wage_;
    admission_date = admission_date_;
}

bool operator == (const string& cpf1, const string& cpf2){
    if(cpf1.compare(cpf2) == 0){
        return true;
    }
    return false;
}

string Employee::getName(){
    return name;
}

string Employee::getCpf(){
    return cpf;
}

float Employee::getWage(){
    return wage;
}

Date Employee::getAdmissionDate(){
    return admission_date;
}

void Employee::riseWage(float& amount){
    wage = wage * (1+(amount/100));
}