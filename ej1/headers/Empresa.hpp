#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <vector>
#include <string>
#include "EntidadOrganizativa.hpp"

using namespace std;

class Departamento;

class Empresa : public EntidadOrganizativa {
    private:
        vector<Departamento*> departamentos;
    public:
        Empresa(string nombre, string direccion);
        string nombre;
        string direccion;
        Departamento* getDepByName(string nombre) const;
        vector<Departamento*> getDeps() const;
};

#endif