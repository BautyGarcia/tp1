#include "../headers/Empresa.hpp"
#include "../headers/Departamento.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Empresa::Empresa(string nombre, string direccion) :
    EntidadOrganizativa(nombre),
    nombre(nombre),
    direccion(direccion),
    departamentos(vector<Departamento*>())
{}

vector<Departamento*> Empresa::getDeps() const {
    return this->departamentos;
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