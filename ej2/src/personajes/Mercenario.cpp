#include "../../headers/personajes/Mercenario.hpp"

Mercenario::Mercenario(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) 
    : Guerrero(nombre, vida, armadura, magicResistance, armas)
{}

void Mercenario::mostrarInfo() const {
    cout << "Mercenario: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
