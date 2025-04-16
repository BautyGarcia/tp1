#include "../../headers/armas/HachaDoble.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

HachaDoble::HachaDoble(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_unique<Sangrado>()) 
{}

void HachaDoble::mostrarInfo() const {
    cout << "HachaDoble: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}