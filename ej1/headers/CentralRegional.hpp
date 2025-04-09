#ifndef CENTRAL_REGIONAL_HPP
#define CENTRAL_REGIONAL_HPP

#include <vector>
#include <set>
#include <string>
#include <array>
#include "EntidadOrganizativa.hpp"
#include "Empresa.hpp"
#include "Empleado.hpp"

using namespace std;

// Le doy un criterio de comparación para que el set funcione
class compareEmpresas {
    public:
        bool operator()(const Empresa& a, const Empresa& b) const {
            return a.nombre < b.nombre;
        }
};

class CentralRegional : public EntidadOrganizativa {
    private:
        int cantEmpleados;
        set<Empresa, compareEmpresas> empresas;
        vector<GerenteAlto> gerentesAlto;
        vector<GerenteMedio> gerentesMedio;
        static const int MAX_GERENTES_ALTO = 5;
        static const int MAX_GERENTES_MEDIO = 20;
    public:
        CentralRegional(string nombre);
        string nombre;
        set<string> paises;
        int getCantEmpleados() const;
        vector<string> getEmpNames() const;
        vector<GerenteAlto> getGerentesAlto() const;
        vector<GerenteMedio> getGerentesMedio() const;
        void agregarPais(string pais);
        bool agregarGerenteAlto(const GerenteAlto& gerente);
        bool agregarGerenteMedio(const GerenteMedio& gerente);
        bool agregarEmpresa(const Empresa& empresa);
};

#endif