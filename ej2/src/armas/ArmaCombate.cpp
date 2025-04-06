#include "../../headers/efectos/IEfecto.hpp"
#include "../../headers/armas/ArmaCombate.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

ArmaCombate::ArmaCombate(string nombre, int damage, int costoMana, int alcance, shared_ptr<IEfecto> efecto) : 
    nombre(nombre),
    damage(damage),
    costoMana(costoMana),
    alcance(alcance),
    efecto(efecto) 
{}

string ArmaCombate::getNombre() const {
    return this->nombre;
}

TipoArma ArmaCombate::getTipo() const {
    return this->tipo;
}

int ArmaCombate::getDamage() const {
    return this->damage;
}

int ArmaCombate::getAlcance() const {
    return this->alcance;
}

int ArmaCombate::getCostoMana() const {
    return this->costoMana;
}

void ArmaCombate::usar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) {
    if (personaje->getEfecto() == Efecto::STUN && personaje->getTurnosRestantesEfecto() > 0) {
        throw string("El personaje no puede usar esta arma");
    }

    int damage = this->damage - objetivo->getArmadura();
    if (damage < 0) damage = 0;

    objetivo->recibirDamage(damage);

    efecto->aplicar(personaje, objetivo);

    objetivo->propagarEfecto();
}