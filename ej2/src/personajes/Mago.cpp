#include "../../headers/personajes/Mago.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

Mago::Mago(string nombre, int mana, int vida, int armadura, int resistenciaMagica, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) : 
    nombre(nombre),
    mana(mana),
    vida(vida),
    armadura(armadura),
    resistenciaMagica(resistenciaMagica),
    armas(armas),
    efectoActual(Efecto::NINGUNO),
    turnosRestantesEfecto(0)
{}

string Mago::getNombre() const {
    return this->nombre;
}

int Mago::getMana() const {
    return this->mana;
}

int Mago::getVida() const {
    return this->vida;
}

int Mago::getArmadura() const {
    return this->armadura;
}

int Mago::getResistenciaMagica() const {
    return this->resistenciaMagica;
}

int Mago::getTurnosRestantesEfecto() const {
    return this->turnosRestantesEfecto;
}

pair<shared_ptr<IArma>, shared_ptr<IArma>> Mago::getArmas() const {
    return this->armas;
}

void Mago::recibirDamage(int damage) {
    this->vida -= damage;

    if (this->vida < 0) this->vida = 0;
}

void Mago::curarVida(int cantidad) {
    this->vida += cantidad;
}

void Mago::gastarMana(int cantidad) {
    this->mana -= cantidad;

    if (this->mana < 0) this->mana = 0;
}

void Mago::aplicarEfecto(Efecto efecto, int duracion) {
    this->efectoActual = efecto;
    this->turnosRestantesEfecto = duracion;
}

void Mago::restarTurnoEfecto() {
    this->turnosRestantesEfecto--;
}

void Mago::boostDamage(int porcentaje) {
    this->damageBoost += porcentaje;
}

int Mago::getDamageBoost() const {
    return this->damageBoost;
}

Efecto Mago::getEfecto() const {
    return this->efectoActual;
}

void Mago::propagarEfecto() {
    // Si el efecto no tiene turnos restantes, se elimina
    if (this->turnosRestantesEfecto == 0) {
        this->efectoActual = Efecto::NINGUNO;
        return;
    };

    // Si el efecto es sangrado (Unico efecto con propagacion activa), se reduce la vida del mago en la cantidad de sangrado
    if (this->efectoActual == Efecto::SANGRE) {
        this->vida -= Sangrado::getCantidad();
    }

    // Se resta un turno al efecto
    this->restarTurnoEfecto();
}

