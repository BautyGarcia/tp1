#include <string>
#include <vector>
#include <iostream>
#include "tp1/ej1/headers/EntidadOrganizativa.hpp"

using namespace std;

EntidadOrganizativa::EntidadOrganizativa(string nombre) :
    nombre(nombre),
    subentidades(vector<EntidadOrganizativa*>()) 
{}

string EntidadOrganizativa::getNombre() const {
    return this->nombre;
}

bool EntidadOrganizativa::agregarSubentidad(EntidadOrganizativa* subentidad) {
    for (EntidadOrganizativa* e : this->subentidades) {
        if (e->getNombre() == subentidad->getNombre()) {
            cout << "La subentidad ya existe" << endl;
            return false;
        }
    }

    this->subentidades.push_back(subentidad);
    return true;
}

int EntidadOrganizativa::contarSubentidades() const {
    return this->subentidades.size();
}