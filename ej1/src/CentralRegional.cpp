#include "../headers/CentralRegional.hpp"
#include "../headers/Empresa.hpp"
#include "../headers/Empleado.hpp"
#include "../headers/Departamento.hpp"
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

CentralRegional::CentralRegional(string nombre) :
    EntidadOrganizativa(nombre),
    empresas(set<Empresa*, compareEmpresas>()),
    gerentesAlto(vector<GerenteAlto*>()),
    gerentesMedio(vector<GerenteMedio*>()),
    nombre(nombre),
    paises(set<string>())
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

void CentralRegional::agregarPais(string pais) {
    this->paises.insert(pais);
}

bool CentralRegional::agregarGerenteAlto(GerenteAlto* gerente) {
    if (this->gerentesAlto.size() < MAX_GERENTES_ALTO) {
        this->gerentesAlto.push_back(gerente);
        this->cantEmpleados++;
        return true;
    }

    cout << "No se puede agregar mas gerentes altos" << endl;
    return false;
}

bool CentralRegional::agregarGerenteMedio(GerenteMedio* gerente) {
    if (this->gerentesMedio.size() < MAX_GERENTES_MEDIO) {
        this->gerentesMedio.push_back(gerente);
        this->cantEmpleados++;
        return true;
    }

    cout << "No se puede agregar mas gerentes medios" << endl;
    return false;
}

bool CentralRegional::agregarEmpresa(Empresa* empresa) {
    return this->empresas.insert(empresa).second;
}