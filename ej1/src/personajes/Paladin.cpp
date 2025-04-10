#include "../../headers/personajes/Paladin.hpp"

Paladin::Paladin(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) 
    : Guerrero(nombre, vida, armadura, magicResistance, armas)
{} 

void Paladin::mostrarInfo() const {
    cout << "Paladin: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
