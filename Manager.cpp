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
    for(int i = 0; i < companies.size(); i++)
    {
        cout<<companies[i].getName()<<"("<<companies[i].getCnpj()<<")"<<" | ";
    }
    cout<<companies_count;
}


