#include "../../headers/personajes/Caballero.hpp"

Caballero::Caballero(string nombre, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) 
    : Guerrero(nombre, vida, armadura, magicResistance, std::move(armas))
{} 

void Caballero::mostrarInfo() const {
    cout << "Caballero: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
