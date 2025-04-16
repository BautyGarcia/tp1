#include "../../headers/armas/Baston.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

using namespace std;

Baston::Baston(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_unique<Stun>())
{}

void Baston::mostrarInfo() const {
    cout << "Baston: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}