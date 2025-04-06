#include "../../headers/efectos/EfectosCombate.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

EfectoSangrado::EfectoSangrado() {}

void EfectoSangrado::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    objetivo->aplicarEfecto(Efecto::SANGRE, 3);
}

string EfectoSangrado::getNombre() const {
    return "Efecto Sangrado";
}

const int EfectoSangrado::getCantidad() {
    return cantidad;
}

EmptyEfecto::EmptyEfecto() {}

void EmptyEfecto::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    // Nada
}

string EmptyEfecto::getNombre() const {
    return "Nada";
}