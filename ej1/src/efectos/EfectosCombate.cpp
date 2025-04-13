#include "../../headers/efectos/EfectosCombate.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

Sangrado::Sangrado() {}

void Sangrado::aplicar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) {
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

void Nada::aplicar(shared_ptr<IPersonaje>, shared_ptr<IPersonaje>) {
    // Nada
}

string Nada::getNombre() const {
    return "Nada";
}