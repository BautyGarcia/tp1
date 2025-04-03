#include "../headers/CentralRegional.hpp"
#include "../headers/Empresa.hpp"
#include "../headers/Empleado.hpp"
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

CentralRegional::CentralRegional(string nombre, string pais) :
    EntidadOrganizativa(nombre),
    nombre(nombre),
    paises(set<string>()),
    empresas(set<Empresa*, compareEmpresas>()),
    gerentesAlto(vector<GerenteAlto*>()),
    gerentesMedio(vector<GerenteMedio*>())
{}

int CentralRegional::getCantEmpleados() const {
    return this->cantEmpleados;
}

vector<string> CentralRegional::getEmpNames() const {
    vector<string> empNames;
    for (Empresa* e : this->empresas) {
        empNames.push_back(e->getNombre());
    }
    return empNames;
}

vector<GerenteAlto*> CentralRegional::getGerentesAlto() const {
    return this->gerentesAlto;
}

vector<GerenteMedio*> CentralRegional::getGerentesMedio() const {
    return this->gerentesMedio;
}