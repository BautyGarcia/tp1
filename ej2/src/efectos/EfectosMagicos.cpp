#include "../../headers/efectos/EfectosMagicos.hpp"
#include "../../headers/personajes/IPersonaje.hpp"
#include "../../utils/utils.hpp"

using namespace std;

Stun::Stun() {}

void Stun::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    if (rand() % 100 > this->probabilidad) return;

    objetivo->aplicarEfecto(Efecto::STUN, 2);
}

string Stun::getNombre() const {
    return "Stun";
}

CurarVida::CurarVida() {}

void CurarVida::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    objetivo->curarVida(this->cantidad);
}

string CurarVida::getNombre() const {
    return "Curar Vida";
}

BoostMagico::BoostMagico() {}

void BoostMagico::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    objetivo->boostDamage(this->porcentaje);
}

string BoostMagico::getNombre() const {
    return "Boost Magico";
}

RoboDeVida::RoboDeVida() {}

void RoboDeVida::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    int vidaRobada = objetivo->getVida() * this->porcentaje;
    usuario->curarVida(vidaRobada);
    objetivo->recibirDamage(vidaRobada);
}

string RoboDeVida::getNombre() const {
    return "Robo de Vida";
}