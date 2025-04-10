#include "../../headers/personajes/Caballero.hpp"

Caballero::Caballero(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) 
    : Guerrero(nombre, vida, armadura, magicResistance, armas)
{} 

void Caballero::mostrarInfo() const {
    cout << "Caballero: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
