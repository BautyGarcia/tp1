#include "../../headers/personajes/Guerrero.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Guerrero::Guerrero(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) : 
    nombre(nombre),
    mana(0),
    vida(vida),
    armadura(armadura),
    magicResistance(magicResistance),
    armas(armas),
    efectoActual(Efecto::NINGUNO),
    turnosRestantesEfecto(0)
{}

int Guerrero::getMana() const {
    return this->mana;
}

int Guerrero::getVida() const {
    return this->vida;
}

int Guerrero::getArmadura() const {
    return this->armadura;
}

int Guerrero::getMagicResistance() const {
    return this->magicResistance;
}

int Guerrero::getTurnosRestantesEfecto() const {
    return this->turnosRestantesEfecto;
}

int Guerrero::getDamageBoost() const {
    return this->damageBoost;
}

void Guerrero::recibirDamage(int damage) {
    this->vida -= damage;
}

void Guerrero::curarVida(int cantidad) {
    this->vida += cantidad;
}

void Guerrero::gastarMana(int cantidad) {
    this->mana -= cantidad;
}

void Guerrero::aplicarEfecto(Efecto efecto, int duracion) {
    this->efectoActual = efecto;
    this->turnosRestantesEfecto = duracion;
}

void Guerrero::restarTurnoEfecto() {
    this->turnosRestantesEfecto--;
}

void Guerrero::boostDamage(int porcentaje) {
    this->damageBoost += porcentaje;
}

void Guerrero::propagarEfecto() {
    if (this->turnosRestantesEfecto == 0) return;

    if (this->efectoActual == Efecto::SANGRE) {
        this->vida -= EfectoSangrado::getCantidad();
    }

    this->restarTurnoEfecto();
}

Efecto Guerrero::getEfecto() const {
    return this->efectoActual;
}