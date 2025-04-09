#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <vector>
#include <string>
#include "EntidadOrganizativa.hpp"
#include "Departamento.hpp"

using namespace std;

class Empresa : public EntidadOrganizativa {
    private:
        vector<Departamento> departamentos;
    public:
        Empresa(string nombre, string direccion);
        string nombre;
        string direccion;
        Departamento getDepByName(string nombre) const;
        vector<string> getDepNames() const;
        bool agregarDepartamento(const Departamento& departamento);
};

#endif