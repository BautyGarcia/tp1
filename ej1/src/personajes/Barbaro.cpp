#include "../../headers/personajes/Barbaro.hpp"

Barbaro::Barbaro(string nombre, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) : 
    Guerrero(nombre, vida, armadura, magicResistance, std::move(armas))
{}

void Barbaro::mostrarInfo() const {
    cout << "Barbaro: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}