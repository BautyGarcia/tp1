#include "../../headers/armas/Lanza.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

using namespace std;

Lanza::Lanza(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_unique<Nada>()) 
{}

void Lanza::mostrarInfo() const {
    cout << "Lanza: " << this->getNombre() << endl;
    cout << "Damage: " << this->getDamage() << endl;
    cout << "Alcance: " << this->getAlcance() << endl;
}