#include "Company.h"

Company::Company(string& name_, string& cnpj_){
    name = name_;
    cnpj = cnpj_;
    employees_count = 0;
}

string Company::getName(){
    return name;
}

string Company::getCnpj(){
    return cnpj;
}

bool Company::addEmployee(string& name_, string& cpf_, float& wage_, Date& admission_date_){
    for(int i = 0; i < employees.size(); i++)
    {
        if(employees[i].getCpf() == cpf_){
            return false;
        }
    }

    Employee n_employee(name_, cpf_, wage_, admission_date_);
    employees.push_back(n_employee);
    employees_count++;

    return true;
}

void Company::seeEmployees(){
    for(int i = 0; i < employees.size(); i++)
    {
        cout<<employees[i].getName()<<"("<<employees[i].getCpf()<<", "<<employees[i].getAdmissionDate()<<")"<<" | ";
    }

    if(employees_count == 0){
        cout<<"No employees working in "<<name<<endl;
    }else{
        cout<<employees_count<<endl;
    }
}