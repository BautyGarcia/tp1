#include "../../headers/personajes/Nigromante.hpp"

Nigromante::Nigromante(string nombre, int mana, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) : 
    Mago(nombre, mana, vida, armadura, magicResistance, std::move(armas)) 
{}

void Nigromante::mostrarInfo() const {
    cout << "Nigromante: " << this->getNombre() << endl;
    cout << "Vida: " << this->getVida() << endl;
    cout << "Armadura: " << this->getArmadura() << endl;
    cout << "Resistencia magica: " << this->getResistenciaMagica() << endl;
}
