#include "../headers/Empresa.hpp"
#include "../headers/Departamento.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Empresa::Empresa(string nombre, string direccion) :
    EntidadOrganizativa(nombre),
    departamentos(vector<Departamento*>()),
    nombre(nombre),
    direccion(direccion)
{}

vector<string> Empresa::getDepNames() const {
    vector<string> nombres;
    for (Departamento* d : this->departamentos) {
        nombres.push_back(d->nombre);
    }
    return nombres;
}

Departamento* Empresa::getDepByName(string nombre) const {
    for (Departamento* d : this->departamentos) {
        if (d->nombre == nombre) {
            return d;
        }
    }
    return nullptr;
}

bool Empresa::agregarDepartamento(Departamento* departamento) {
    for (Departamento* d : this->departamentos) {
        if (d->nombre == departamento->nombre) {
            return false;
        }
    }
    this->departamentos.push_back(departamento);
    return true;
}