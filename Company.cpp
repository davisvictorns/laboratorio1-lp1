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
    for(int i = 0; i < (int) employees.size(); i++)
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
    for(int i = 0; i < (int) employees.size(); i++)
    {
        cout<<employees[i].getName()<<"("<<employees[i].getCpf()<<", "<<employees[i].getWage()<<", "<<employees[i].getAdmissionDate()<<")"<<" | ";
    }

    if(employees_count == 0){
        cout<<"No employees working in "<<name<<endl;
    }else{
        cout<<employees_count<<endl;
    }
}

void Company::riseEmployeesWage(float& amount){
    for(int i = 0; i < (int) employees.size(); i++)
    {
        employees[i].riseWage(amount);
    }

    Company::seeEmployees();
}

void Company::getEmployeesAdmittedDaysAgo(int& days){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    Date deadline_date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    int was_found = 0;
    string admitted_employees = "";

    for(int i = 0; i < (int) employees.size(); i++)
    {
        if(deadline_date-employees[i].getAdmissionDate() <= days && deadline_date-employees[i].getAdmissionDate() >= 0){
            admitted_employees = admitted_employees + employees[i].getName() + "(" + employees[i].getCpf() + "), ";
            
            was_found++;
        }
    }
    
    if(was_found == 0){
        cout<< name <<" don't have employees admitted at those days."<<endl;
    }else{
        cout<< name <<" have admitted:"<<endl<<admitted_employees<<"at the past "<<days<<" days."<<endl;
    }
}

int Company::getAmountEmplyees(){
    return employees_count;
}