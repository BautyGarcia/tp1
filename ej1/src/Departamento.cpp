#include "tp1/ej1/headers/Departamento.hpp"
#include "tp1/ej1/headers/Empleado.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Departamento::Departamento(string nombre, string ubicacion) :
    nombre(nombre),
    ubicacion(ubicacion),
    empleados(vector<Empleado*>())
{}

int Departamento::contarEmpleados() const {
    return this->empleados.size();
}

vector<Empleado*> Departamento::getEmpleados() const {
    return this->empleados;
}

bool Departamento::contratarEmpleado(Empleado* empleado) {
    for (Empleado* e : this->empleados) {
        if (e->nombre == empleado->nombre) {
            cout << "El empleado ya existe" << endl;
            return false;
        }
    }
    
    this->empleados.push_back(empleado);
    return true;
}

bool Departamento::despedirEmpleado(Empleado* empleado) {
    for (int i = 0; i < this->empleados.size(); i++) {
        if (this->empleados[i]->nombre == empleado->nombre) {
            this->empleados.erase(this->empleados.begin() + i);
            return true;
        }
    }
    return false;
}