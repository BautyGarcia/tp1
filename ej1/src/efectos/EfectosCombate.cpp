#include "../../headers/efectos/EfectosCombate.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

Sangrado::Sangrado() {}

void Sangrado::aplicar(IPersonaje* personaje, IPersonaje* objetivo) {
    cout << personaje->getNombre() << " aplica sangrado a " << objetivo->getNombre() << endl;
    objetivo->aplicarEfecto(Efecto::SANGRE, 3);
}

string Sangrado::getNombre() const {
    return "Efecto Sangrado";
}

int Sangrado::getCantidad() {
    return cantidad;
}

Nada::Nada() {}

void Nada::aplicar(IPersonaje*, IPersonaje*) {
    // Nada
}

string Nada::getNombre() const {
    return "Nada";
}