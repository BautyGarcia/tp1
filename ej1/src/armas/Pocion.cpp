#include "../../headers/armas/Pocion.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

Pocion::Pocion(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<CurarVida>())
{}

void Pocion::mostrarInfo() const {
    cout << "Pocion: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}