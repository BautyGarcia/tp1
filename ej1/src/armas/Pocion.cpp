#include "../../headers/armas/Pocion.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

using namespace std;

Pocion::Pocion(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_unique<CurarVida>())
{}

void Pocion::mostrarInfo() const {
    cout << "Pocion: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}