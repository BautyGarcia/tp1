#include "../../headers/armas/LibroDeHechizos.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

using namespace std;

LibroDeHechizos::LibroDeHechizos(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_unique<BoostMagico>())
{}

void LibroDeHechizos::mostrarInfo() const {
    cout << "LibroDeHechizos: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Costo de mana: " << this->getCostoMana() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}