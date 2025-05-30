#include "../../headers/armas/Espada.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

Espada::Espada(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_unique<Sangrado>()) 
{}

void Espada::mostrarInfo() const {
    cout << "Espada: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}