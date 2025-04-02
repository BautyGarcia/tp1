#ifndef CENTRAL_REGIONAL_HPP
#define CENTRAL_REGIONAL_HPP
#define MAX_GERENTES_ALTO 5
#define MAX_GERENTES_MEDIO 20

#include <vector>
#include <set>
#include <string>
#include "EntidadOrganizativa.hpp"

using namespace std;

class Empresa;
class GerenteAlto;
class GerenteMedio;

// Le doy un criterio de comparación para que el set funcione
class compareEmpresas {
    public:
        bool operator()(Empresa* a, Empresa* b) const {
            return a->getNombre() < b->getNombre();
        }
};

class CentralRegional : public EntidadOrganizativa {
    private:
        int cantEmpleados;
        set<Empresa*, compareEmpresas> empresas;
        vector<GerenteAlto*> gerentesAlto;
        vector<GerenteMedio*> gerentesMedio;
    public:
        CentralRegional(string nombre, string pais);
        string nombre;
        set<string> paises;
        int getCantEmpleados() const;
        vector<string> getEmpNames() const;
        vector<GerenteAlto*> getGerentesAlto() const;
        vector<GerenteMedio*> getGerentesMedio() const;
};

#endif