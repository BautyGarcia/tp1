#include "../../headers/armas/Garrote.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Garrote::Garrote(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<Sangrado>()) 
{}

void Garrote::mostrarInfo() const {
    cout << "Garrote: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}