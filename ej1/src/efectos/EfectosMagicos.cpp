#include "../../headers/efectos/EfectosMagicos.hpp"
#include "../../headers/personajes/IPersonaje.hpp"
#include "../../utils/utils.hpp"

using namespace std;

Stun::Stun() {}

void Stun::aplicar(shared_ptr<IPersonaje>, shared_ptr<IPersonaje> objetivo) {
    // Si no se cumple la probabilidad, no se aplica el efecto
    if (rand() % 100 > this->probabilidad) return;

    // Aplico Stun
    objetivo->aplicarEfecto(Efecto::STUN, 2);
    cout << objetivo->getNombre() << " queda stuneado por 2 turnos" << endl;
}

string Stun::getNombre() const {
    return "Stun";
}

CurarVida::CurarVida() {}

void CurarVida::aplicar(shared_ptr<IPersonaje>, shared_ptr<IPersonaje> objetivo) {
    cout << objetivo->getNombre() << " se cura " << this->cantidad << " de vida" << endl;
    objetivo->curarVida(this->cantidad);
}

string CurarVida::getNombre() const {
    return "Curar Vida";
}

BoostMagico::BoostMagico() {}

void BoostMagico::aplicar(shared_ptr<IPersonaje>, shared_ptr<IPersonaje> objetivo) {
    cout << objetivo->getNombre() << " recibe un boost de " << this->porcentaje << "% de daño" << endl;
    objetivo->boostDamage(this->porcentaje);
}

string BoostMagico::getNombre() const {
    return "Boost Magico";
}

RoboDeVida::RoboDeVida() {}

void RoboDeVida::aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) {
    // Calculo de vida robada
    int vidaRobada = objetivo->getVida() * this->porcentaje;
    cout << usuario->getNombre() << " roba " << vidaRobada << " de vida a " << objetivo->getNombre() << endl;
    // Curacion del usuario
    usuario->curarVida(vidaRobada);

    // Daño al objetivo
    objetivo->recibirDamage(vidaRobada);
}

string RoboDeVida::getNombre() const {
    return "Robo de Vida";
}