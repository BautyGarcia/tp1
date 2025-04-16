#include "../../headers/personajes/Guerrero.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

Guerrero::Guerrero(string nombre, int vida, int armadura, int resistenciaMagica, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) : 
    nombre(nombre),
    mana(0),
    vida(vida),
    armadura(armadura),
    resistenciaMagica(resistenciaMagica),
    armas(std::move(armas)),
    efectoActual(Efecto::NINGUNO),
    turnosRestantesEfecto(0)
{}

string Guerrero::getNombre() const {
    return this->nombre;
}

int Guerrero::getMana() const {
    return this->mana;
}

int Guerrero::getVida() const {
    return this->vida;
}

int Guerrero::getArmadura() const {
    return this->armadura;
}

int Guerrero::getResistenciaMagica() const {
    return this->resistenciaMagica;
}

int Guerrero::getTurnosRestantesEfecto() const {
    return this->turnosRestantesEfecto;
}

int Guerrero::getDamageBoost() const {
    return this->damageBoost;
}

const pair<unique_ptr<IArma>, unique_ptr<IArma>>& Guerrero::getArmas() const {
    return this->armas;
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
    // Si el efecto no tiene turnos restantes, se elimina
    if (this->turnosRestantesEfecto == 0) {
        this->efectoActual = Efecto::NINGUNO;
        return;
    };

    // Si el efecto es sangrado (Unico efecto con propagacion activa), se reduce la vida del guerrero en la cantidad de sangrado
    if (this->efectoActual == Efecto::SANGRE) {
        this->vida -= Sangrado::getCantidad();
        cout << this->nombre << " pierde " << Sangrado::getCantidad() << " de vida por efecto de sangrado" << endl;
    }

    // Se resta un turno al efecto
    this->restarTurnoEfecto();
}

Efecto Guerrero::getEfecto() const {
    return this->efectoActual;
}