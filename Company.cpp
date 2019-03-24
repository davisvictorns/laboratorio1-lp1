#include "Company.h"

Company::Company(string name_, string cnpj_){
    name = name_;
    cnpj = cnpj_;
}

string Company::getName(){
    return name;
}

string Company::getCnpj(){
    return cnpj;
}