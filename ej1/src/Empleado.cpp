#include "../headers/Empleado.hpp"
#include <string>
#include <iostream>

using namespace std;

Empleado::Empleado(string nombre, string puesto, int antiguedad, float salario) :
    antiguedad(antiguedad),
    salario(salario),
    nombre(nombre),
    puesto(puesto)
{}

int Empleado::getAntiguedad() const {
    return this->antiguedad;
}

float Empleado::getSalario() const {
    return this->salario;
}

bool Empleado::updateSalario(float nuevoSalario) {
    if (nuevoSalario < 0) {
        cout << "El salario no puede ser negativo" << endl;
        return false;
    }
    
    this->salario = nuevoSalario;
    return true;
}

Manager::Manager(string nombre, string puesto, int antiguedad, float salario, float bono, string nivel) :
    Empleado(nombre, puesto, antiguedad, salario),
    bono(bono),
    nivel(nivel)
{}

float Manager::getBono() const {
    return this->bono;
}

bool Manager::setLevel(string nivel) {
    this->nivel = nivel;
    return true;
}

bool Manager::updateBono(float nuevoBono) {
    if (nuevoBono < 0) {
        cout << "El bono no puede ser negativo" << endl;
        return false;
    }
    
    this->bono = nuevoBono;
    return true;
}

GerenteAlto::GerenteAlto(string nombre, string puesto, int antiguedad, float salario, float bono, string nivel) :
    Manager(nombre, puesto, antiguedad, salario, bono, nivel)
{}

GerenteMedio::GerenteMedio(string nombre, string puesto, int antiguedad, float salario, float bono, string nivel) :
    Manager(nombre, puesto, antiguedad, salario, bono, nivel)
{}

GerenteBajo::GerenteBajo(string nombre, string puesto, int antiguedad, float salario, float bono, string nivel) :
    Manager(nombre, puesto, antiguedad, salario, bono, nivel)
{}

LiderEquipo::LiderEquipo(string nombre, string puesto, int antiguedad, float salario, float bono, string nivel) :
    Manager(nombre, puesto, antiguedad, salario, bono, nivel)
{}