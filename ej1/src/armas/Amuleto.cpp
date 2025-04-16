#include "../../headers/armas/Amuleto.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

using namespace std;

Amuleto::Amuleto(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_unique<RoboDeVida>())
{}

void Amuleto::mostrarInfo() const {
    cout << "Amuleto: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}