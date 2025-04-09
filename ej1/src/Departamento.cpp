#include "../headers/Departamento.hpp"
#include "../headers/Empleado.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int Departamento::cantEmpleadosDepts = 0;

Departamento::Departamento(string nombre, string ubicacion) :
    empleados(vector<Empleado>()),
    nombre(nombre),
    ubicacion(ubicacion)
{}

int Departamento::contarEmpleados() {
    return cantEmpleadosDepts;
}

vector<Empleado> Departamento::getEmpleados() const {
    return this->empleados;
}

bool Departamento::contratarEmpleado(const Empleado& empleado) {
    this->empleados.push_back(empleado);
    cantEmpleadosDepts++;
    return true;
}

bool Departamento::despedirEmpleado(const Empleado& empleado) {
    for (int i = 0; i < this->empleados.size(); i++) {
        if (this->empleados[i].nombre == empleado.nombre) {
            this->empleados.erase(this->empleados.begin() + i);
            cantEmpleadosDepts--;
            return true;
        }
    }
    throw invalid_argument("Empleado no encontrado");
}