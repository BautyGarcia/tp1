#include "../../headers/personajes/Barbaro.hpp"

Barbaro::Barbaro(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) : 
    Guerrero(nombre, vida, armadura, magicResistance, armas)
{}

void Barbaro::mostrarInfo() const {
    cout << "Barbaro: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}