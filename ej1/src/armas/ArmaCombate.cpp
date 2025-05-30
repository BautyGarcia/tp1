#include "../../headers/efectos/IEfecto.hpp"
#include "../../headers/armas/ArmaCombate.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

ArmaCombate::ArmaCombate(string nombre, int damage, int alcance, unique_ptr<IEfecto> efecto) : 
    nombre(nombre),
    damage(damage),
    alcance(alcance),
    usosRestantes(100),
    efecto(std::move(efecto))
{}

string ArmaCombate::getNombre() const {
    return this->nombre;
}

int ArmaCombate::getDamage() const {
    return this->damage;
}

int ArmaCombate::getAlcance() const {
    return this->alcance;
}

void ArmaCombate::usar(IPersonaje* personaje, IPersonaje* objetivo) {
    if (personaje->getEfecto() == Efecto::STUN && personaje->getTurnosRestantesEfecto() > 0) {
        personaje->restarTurnoEfecto();
        cout << personaje->getNombre() << " no puede usar esta arma porque esta stuneado" << endl;
        throw string("El personaje no puede usar esta arma");
    }

    if (this->usosRestantes == 0) {
        cout << personaje->getNombre() << " no puede usar esta arma porque no tiene usos restantes" << endl;
        throw string("Esta arma no tiene usos restantes");
    }

    float boost = (float)personaje->getDamageBoost() / 100 + 1;
    int damage = (this->damage * boost) - objetivo->getArmadura();
    if (damage < 0) damage = 0;

    objetivo->recibirDamage(damage);

    efecto->aplicar(personaje, objetivo);

    objetivo->propagarEfecto();

    this->usosRestantes--;
}

void ArmaCombate::reparar() {
    this->usosRestantes = 100;
}