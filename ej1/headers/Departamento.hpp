#ifndef DEPARTAMENTO_HPP
#define DEPARTAMENTO_HPP

#include <vector>
#include <string>

using namespace std;

class Empleado;

class Departamento {
    private:
        vector<Empleado*> empleados;
    public:
        Departamento(string nombre, string ubicacion);
        string nombre;
        string ubicacion;
        int contarEmpleados() const;
        vector<Empleado*> getEmpleados() const;
        bool contratarEmpleado(Empleado* empleado);
        bool despedirEmpleado(Empleado* empleado);
};

#endif