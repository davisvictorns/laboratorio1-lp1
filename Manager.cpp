#include "Manager.h"

Manager::Manager(){
    companies_count = 0;
}

Company Manager::createCompany(string name, string cnpj){
    Company n_company(name, cnpj);
    companies.push_back(n_company);
    companies_count++;

    return n_company;
}

void Manager::seeCompanies(){
    for(int i = 0; i < (int) companies.size(); i++)
    {
        cout<<companies[i].getName()<<"("<<companies[i].getCnpj()<<")"<<" | ";
    }
    cout<<companies_count<<endl;
}

string Manager::addEmployeeAt(string name_, string cpf_, float wage_, Date admission_date_, string company_cnpj){

    for(int i = 0; i < (int) companies.size(); i++)
    {
        if(companies[i].getCnpj() == company_cnpj){
            if(companies[i].addEmployee(name_, cpf_, wage_, admission_date_)){
                return name_ + " was added to the company";
            }else{
                return name_ + " already is working in this company";
            }
        }
    }

    return "Company not found";
}

void Manager::seeEmployeesAt(string company_name, string company_cnpj){
    int multiple_company = 0;
    for(int i = 0; i < (int) companies.size(); i++)
    {
        if(company_cnpj != ""){
            if(companies[i].getCnpj() == company_cnpj){
                companies[i].seeEmployees();
                multiple_company++;
            }
        }else{         
            if(company_name != ""){
                if(companies[i].getName() == company_name){
                    companies[i].seeEmployees();
                    multiple_company++;
                }
            }else{
                cout<<"Company name and CNPJ are invalids."<<endl;
            }
        }
    }
    if(multiple_company > 1){
        cout<<"Was found "<<multiple_company<<" companies with this name."<<endl;
    }else if(multiple_company == 0){
        cout<<"Company not found."<<endl;
    }
}

void Manager::riseEmployeesWageAt(string company_cnpj, float amount){
    int was_found = 0;
    for(int i = 0; i < (int) companies.size(); i++)
    {
        if(companies[i].getCnpj() == company_cnpj){
            companies[i].riseEmployeesWage(amount);
            was_found++;
        }
    }
    if(was_found == 0){
        cout<<"Company not found."<<endl;        
    }
}
