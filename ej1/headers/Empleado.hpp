#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

using namespace std;

enum class ManagerLevel {
    ALTO,
    MEDIO,
    BAJO
};

class Empleado {
    private:
        int antiguedad;
        float salario;
    public:
        Empleado(string nombre, string puesto, int antiguedad, float salario);
        string nombre;
        string puesto;
        int getAntiguedad() const;
        bool updateSalario(float nuevoSalario);
        float getSalario() const;
};

class Manager : public Empleado {
    private:
        float bono;
        ManagerLevel nivel;
    public:
        Manager(string nombre, string puesto, int antiguedad, float salario, float bono, ManagerLevel nivel);
        float getBono() const;
        bool setLevel(ManagerLevel nivel);
        bool updateBono(float nuevoBono);
};

class GerenteAlto : public Manager {
    public:
        GerenteAlto(string nombre, string puesto, int antiguedad, float salario, float bono, ManagerLevel nivel);
};

class GerenteMedio : public Manager {
    public:
        GerenteMedio(string nombre, string puesto, int antiguedad, float salario, float bono, ManagerLevel nivel);
};

class GerenteBajo : public Manager {
    public:
        GerenteBajo(string nombre, string puesto, int antiguedad, float salario, float bono, ManagerLevel nivel);
};

class LiderEquipo : public Manager {
    public:
        LiderEquipo(string nombre, string puesto, int antiguedad, float salario, float bono, ManagerLevel nivel);
};

#endif