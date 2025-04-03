#include "headers/CentralRegional.hpp"
#include "headers/Departamento.hpp"
#include "headers/Empleado.hpp"
#include "headers/Empresa.hpp"
#include "headers/EntidadOrganizativa.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // i. Crear empleados de distintos tipos
    Empleado* emp1 = new Empleado("Juan Perez", "Desarrollador", 5, 50000);
    GerenteBajo* gBajo = new GerenteBajo("Ana Garcia", "Gerente Proyecto", 8, 75000, 10000, "Junior");
    GerenteMedio* gMedio = new GerenteMedio("Carlos Lopez", "Gerente Area", 10, 90000, 20000, "Senior");
    GerenteAlto* gAlto = new GerenteAlto("Maria Rodriguez", "Gerente General", 15, 120000, 50000, "Executive");
    LiderEquipo* lider = new LiderEquipo("Pedro Martinez", "Tech Lead", 7, 70000, 15000, "Senior");

    // Configurar bonos y niveles para gerentes
    gBajo->updateBono(10000);
    gBajo->setLevel("Junior");
    gMedio->updateBono(20000);
    gMedio->setLevel("Senior");
    gAlto->updateBono(50000);
    gAlto->setLevel("Executive");
    lider->updateBono(15000);
    lider->setLevel("Senior");

    // ii. Crear departamentos, empresas y centrales regionales
    Departamento* deptIT = new Departamento("IT", "Piso 3");
    Departamento* deptRH = new Departamento("Recursos Humanos", "Piso 2");
    
    // Contratar empleados en departamentos
    deptIT->contratarEmpleado(emp1);
    deptIT->contratarEmpleado(lider);
    deptRH->contratarEmpleado(gBajo);

    // Crear empresa y agregar departamentos
    Empresa* empresa1 = new Empresa("TechCorp", "Av. Principal 123");
    empresa1->agregarDepartamento(deptIT);
    empresa1->agregarDepartamento(deptRH);

    // Crear central regional
    CentralRegional* centralARG = new CentralRegional("Central Argentina", "Argentina");
    centralARG->paises.insert("Argentina");
    centralARG->paises.insert("Uruguay");
    centralARG->paises.insert("Chile");

    // iii. Relacionar objetos (agregar empresa a la central)
    centralARG->agregarSubentidad(empresa1);

    // Mostrar algunas verificaciones
    cout << "Central Regional: " << centralARG->getNombre() << endl;
    cout << "Cantidad de empleados en IT: " << deptIT->contarEmpleados() << endl;
    cout << "Cantidad de empleados en RH: " << deptRH->contarEmpleados() << endl;
    
    // Ejemplo de búsqueda de departamento por nombre
    Departamento* foundDept = empresa1->getDepByName("IT");
    if (foundDept) {
        cout << "Departamento IT encontrado en " << empresa1->getNombre() << endl;
    }

    // Limpieza de memoria
    delete emp1;
    delete gBajo;
    delete gMedio;
    delete gAlto;
    delete lider;
    delete deptIT;
    delete deptRH;
    delete empresa1;
    delete centralARG;

    return 0;
}
