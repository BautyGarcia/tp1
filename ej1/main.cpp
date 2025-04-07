#include "headers/CentralRegional.hpp"
#include "headers/Departamento.hpp"
#include "headers/Empleado.hpp"
#include "headers/Empresa.hpp"
#include "headers/EntidadOrganizativa.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mostrarEmpleados(Departamento* dept) {
    cout << "Empleados de " << dept->nombre << ": " << endl;
    for (Empleado* e : dept->getEmpleados()) {
        cout << e->nombre << endl;
    }
}

void mostrarGerentes(CentralRegional* central) {
    cout << "Gerentes de " << central->nombre << ": " << endl;
    cout << "Gerentes altos: " << endl;
    for (GerenteAlto* g : central->getGerentesAlto()) {
        cout << g->nombre << endl;
    }
    cout << "Gerentes medios: " << endl;
    for (GerenteMedio* g : central->getGerentesMedio()) {
        cout << g->nombre << endl;
    }
}

int main() {
    // Creo la central regional del grupo Volkswagen 
    CentralRegional* VolkswagenLatam = new CentralRegional("Volkswagen Latam");
    VolkswagenLatam->agregarPais("Argentina");
    VolkswagenLatam->agregarPais("Uruguay");

    // Creo las empresas/subentidades de Volkswagen Latam
    Empresa* VolkswagenArgentina = new Empresa("Volkswagen Argentina", "Av. Corrientes 123");
    Empresa* VolkswagenUruguay = new Empresa("Volkswagen Uruguay", "Av. Corrientes Bo 123");
    
    // Creo los departamentos de las empresas
    Departamento* deptITArgentina = new Departamento("IT", "Av. Corrientes 123");
    Departamento* deptRHArgentina = new Departamento("RH", "Av. Corrientes 123");
    Departamento* deptITUruguay = new Departamento("IT", "Av. Corrientes Bo 123");
    Departamento* deptRHUruguay = new Departamento("RH", "Av. Corrientes Bo 123");

    // Creo gerentes
    GerenteAlto* gerenteAltoArgentina = new GerenteAlto("Juan", "Corrector de TPs", 1, 100000, 15, ManagerLevel::ALTO);
    GerenteAlto* gerenteAltoUruguay = new GerenteAlto("Maria", "Lavaplatos", 4, 100000, 15, ManagerLevel::ALTO);
    GerenteMedio* gerenteMedioArgentina = new GerenteMedio("Pedro", "Marinero", 1, 100000, 15, ManagerLevel::MEDIO);
    GerenteMedio* gerenteMedioUruguay = new GerenteMedio("Ana", "Chofer", 2, 100000, 15, ManagerLevel::MEDIO);

    // Creo los empleados
    Empleado* empITArgentina = new Empleado("Juan", "Corrector de TPs", 1, 100000);
    Empleado* empRHArgentina = new Empleado("Maria", "Lavaplatos", 4, 100000);
    Empleado* empITUruguay = new Empleado("Pedro", "Marinero", 1, 100000);
    Empleado* empRHUruguay = new Empleado("Ana", "Chofer", 2, 100000);

    // Agrego los empleados a los departamentos
    deptITArgentina->contratarEmpleado(empITArgentina);
    deptRHArgentina->contratarEmpleado(empRHArgentina);
    deptITUruguay->contratarEmpleado(empITUruguay);
    deptRHUruguay->contratarEmpleado(empRHUruguay);

    // Agrego los departamentos a las empresas
    VolkswagenArgentina->agregarDepartamento(deptITArgentina);
    VolkswagenArgentina->agregarDepartamento(deptRHArgentina);
    VolkswagenUruguay->agregarDepartamento(deptITUruguay);
    VolkswagenUruguay->agregarDepartamento(deptRHUruguay);

    // Agrego las empresas/subentidades a la central regional
    VolkswagenLatam->agregarEmpresa(VolkswagenArgentina);
    VolkswagenLatam->agregarEmpresa(VolkswagenUruguay);
    
    // Agrego los gerentes a la central regional
    VolkswagenLatam->agregarGerenteAlto(gerenteAltoArgentina);
    VolkswagenLatam->agregarGerenteAlto(gerenteAltoUruguay);
    VolkswagenLatam->agregarGerenteMedio(gerenteMedioArgentina);
    VolkswagenLatam->agregarGerenteMedio(gerenteMedioUruguay);
    
    // Muestro los empleados de cada departamento
    cout << "Empleados de cada departamento:" << endl;
    mostrarEmpleados(deptITArgentina);
    mostrarEmpleados(deptRHArgentina);
    mostrarEmpleados(deptITUruguay);
    mostrarEmpleados(deptRHUruguay);
    
    // Juan se porto mal
    cout << "Despidiendo a Juan (Borro la base de datos)..." << endl;
    deptITArgentina->despedirEmpleado(empITArgentina);

    // Muestro los empleados de cada departamento
    cout << "Empleados de cada departamento:" << endl;
    mostrarEmpleados(deptITArgentina);
    mostrarEmpleados(deptRHArgentina);
    mostrarEmpleados(deptITUruguay);
    mostrarEmpleados(deptRHUruguay);

    // Pero al final, se arrepiente y contrata a Juan de nuevo
    cout << "Contratando a Juan de nuevo (Cebaba buenos mates)..." << endl;
    deptITArgentina->contratarEmpleado(empITArgentina);

    // Muestro los empleados de cada departamento
    cout << "Empleados de cada departamento:" << endl;
    mostrarEmpleados(deptITArgentina);
    mostrarEmpleados(deptRHArgentina);
    mostrarEmpleados(deptITUruguay);
    mostrarEmpleados(deptRHUruguay);
    
    // Muestro los gerentes de la central regional
    mostrarGerentes(VolkswagenLatam);
    
    cout << "Cantidad de empleados en departamentos: " << Departamento::contarEmpleados() << endl;
    return 0;
}
