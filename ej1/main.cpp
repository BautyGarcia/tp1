#include "headers/personajes/Barbaro.hpp"
#include "headers/personajes/Brujo.hpp"
#include "headers/armas/Espada.hpp"
#include "headers/armas/LibroDeHechizos.hpp"
#include "headers/efectos/EfectosCombate.hpp"
#include "headers/efectos/EfectosMagicos.hpp"
#include <iostream>

using namespace std;

int main() {
    // Crear efectos
    auto efectoSangrado = make_shared<Sangrado>();
    auto efectoMagico = make_shared<BoostMagico>();

    // Crear armas
    auto espada = make_shared<Espada>("Espada del Rey", 50, 2);
    auto libro = make_shared<LibroDeHechizos>("Grimorio Antiguo", 40, 30, 4);

    // Crear personajes
    auto barbaro = make_shared<Barbaro>(
        "Conan",         // nombre
        200,            // vida
        50,             // armadura
        20,             // resistencia mágica
        make_pair(espada, nullptr)  // armas
    );

    auto brujo = make_shared<Brujo>(
        "Gandalf",       // nombre
        100,            // mana
        150,            // vida
        20,             // armadura
        40,             // resistencia mágica
        make_pair(libro, nullptr)   // armas
    );

    cout << "=== Información de los Personajes ===" << endl;
    barbaro->mostrarInfo();
    cout << "\n";
    brujo->mostrarInfo();

    cout << "\n=== Simulación de Acciones ===" << endl;
    
    // El bárbaro ataca al brujo
    espada->usar(barbaro, brujo);
    cout << "\nVida de " << brujo->getNombre() << " después del ataque con espada: " << brujo->getVida() << " HP" << endl;

    // El brujo usa su libro
    libro->usar(brujo, barbaro);
    cout << "\nVida de " << barbaro->getNombre() << " después del ataque mágico: " << barbaro->getVida() << " HP" << endl;

    return 0;
}