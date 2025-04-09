#ifndef DEPARTAMENTO_HPP
#define DEPARTAMENTO_HPP

#include <vector>
#include <string>
#include "Empleado.hpp"

using namespace std;

class Departamento {
    private:
        vector<Empleado> empleados;
        static int cantEmpleadosDepts;
    public:
        Departamento(string nombre, string ubicacion);
        string nombre;
        string ubicacion;
        static int contarEmpleados();
        vector<Empleado> getEmpleados() const;
        bool contratarEmpleado(const Empleado& empleado);
        bool despedirEmpleado(const Empleado& empleado);
};

#endif