#include <string>
#include <vector>
#include <iostream>
#include "../headers/EntidadOrganizativa.hpp"

using namespace std;

EntidadOrganizativa::EntidadOrganizativa(string nombre) :
    nombre(nombre),
    subentidades(vector<EntidadOrganizativa>()) 
{}

string EntidadOrganizativa::getNombre() const {
    return this->nombre;
}

bool EntidadOrganizativa::agregarSubentidad(const EntidadOrganizativa& subentidad) {
    for (const EntidadOrganizativa& e : this->subentidades) {
        if (e.getNombre() == subentidad.getNombre()) {
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