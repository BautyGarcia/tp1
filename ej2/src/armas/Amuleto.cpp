#include "../../headers/armas/Amuleto.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

Amuleto::Amuleto(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<RoboDeVida>())
{}

void Amuleto::mostrarInfo() const {
    cout << "Amuleto: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}