#include "../../headers/personajes/Conjurador.hpp"

Conjurador::Conjurador(string nombre, int mana, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) : 
    Mago(nombre, mana, vida, armadura, magicResistance, armas) 
{}

void Conjurador::mostrarInfo() const {
    cout << "Conjurador: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
