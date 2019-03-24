#include <iostream>
#include <cstdlib>
#include "Manager.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Manager control;

    control.createCompany("Teste1", "1");
    control.createCompany("Teste2", "2");
    control.createCompany("Teste3", "3");
    control.seeCompanies();
    
    return 0;
}
