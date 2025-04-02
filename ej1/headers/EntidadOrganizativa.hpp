#ifndef ENTIDAD_ORGANIZATIVA_HPP
#define ENTIDAD_ORGANIZATIVA_HPP

#include <vector>
#include <string>

using namespace std;

class EntidadOrganizativa {
    private:
        string nombre;
        vector<EntidadOrganizativa*> subentidades;
    public:
        EntidadOrganizativa(string nombre);
        string getNombre() const;
        bool agregarSubentidad(EntidadOrganizativa* subentidad);
        int contarSubentidades() const;
};

#endif