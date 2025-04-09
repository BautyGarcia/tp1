#include "../headers/Empresa.hpp"
#include "../headers/Departamento.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Empresa::Empresa(string nombre, string direccion) :
    EntidadOrganizativa(nombre),
    departamentos(vector<Departamento>()),
    nombre(nombre),
    direccion(direccion)
{}

vector<string> Empresa::getDepNames() const {
    vector<string> nombres;
    for (const Departamento& d : this->departamentos) {
        nombres.push_back(d.nombre);
    }
    return nombres;
}

Departamento Empresa::getDepByName(string nombre) const {
    for (const Departamento& d : this->departamentos) {
        if (d.nombre == nombre) {
            return d;
        }
    }
    throw invalid_argument("Departamento no encontrado");
}

bool Empresa::agregarDepartamento(const Departamento& departamento) {
    for (const Departamento& d : this->departamentos) {
        if (d.nombre == departamento.nombre) {
            return false;
        }
    }
    this->departamentos.push_back(departamento);
    return true;
}