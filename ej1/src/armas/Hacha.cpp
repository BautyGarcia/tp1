#include "../../headers/armas/Hacha.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

Hacha::Hacha(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_unique<Sangrado>()) 
{}

void Hacha::mostrarInfo() const {
    cout << "Hacha: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}