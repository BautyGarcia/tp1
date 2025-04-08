#include "Factory.hpp"

using namespace std;

int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

shared_ptr<IArma> getRandomArma(bool isMago) {
    if (isMago) {
        switch (getRandomNumber(0, 3)) {
            case 0: return Factory::crearArma(Armas::AMULETO);
            case 1: return Factory::crearArma(Armas::BASTON);
            case 2: return Factory::crearArma(Armas::LIBRO_DE_HECHIZOS);
            case 3: return Factory::crearArma(Armas::POCION);
            default: return nullptr;
        }
    } else {
        switch (getRandomNumber(0, 4)) {
            case 0: return Factory::crearArma(Armas::ESPADA);
            case 1: return Factory::crearArma(Armas::HACHA);
            case 2: return Factory::crearArma(Armas::LANZA);
            case 3: return Factory::crearArma(Armas::HACHA_DOBLE);
            case 4: return Factory::crearArma(Armas::GARROTE);
            default: return nullptr;
        }
    }
}

shared_ptr<IPersonaje> getRandomPersonaje(bool isMago, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) {
    if (isMago) {
        switch (getRandomNumber(0, 3)) {
            case 0: return Factory::crearPersonaje(Personajes::NIGROMANTE, armas);
            case 1: return Factory::crearPersonaje(Personajes::CONJURADOR, armas);
            case 2: return Factory::crearPersonaje(Personajes::HECHICERO, armas);
            case 3: return Factory::crearPersonaje(Personajes::BRUJO, armas);
            default: return nullptr;
        }
    } else {
        switch (getRandomNumber(0, 4)) {
            case 0: return Factory::crearPersonaje(Personajes::BARBARO, armas);
            case 1: return Factory::crearPersonaje(Personajes::CABALLERO, armas);
            case 2: return Factory::crearPersonaje(Personajes::MERCENARIO, armas);
            case 3: return Factory::crearPersonaje(Personajes::PALADIN, armas);
            case 4: return Factory::crearPersonaje(Personajes::GLADIADOR, armas);
            default: return nullptr;
        }
    }
}

void crearPersonajes(vector<shared_ptr<IPersonaje>>& personajes, int cantidad, bool isMago) {
    for (int i = 0; i < cantidad; i++) {
        int cantArmas = getRandomNumber(0, 2);
        
        pair<shared_ptr<IArma>, shared_ptr<IArma>> armas;
        armas.first = (cantArmas > 0) ? getRandomArma(isMago) : nullptr;
        armas.second = (cantArmas > 1) ? getRandomArma(isMago) : nullptr;

        shared_ptr<IPersonaje> personaje = getRandomPersonaje(isMago, armas);
        if (personaje) personajes.push_back(personaje);
    }
}

void mostrarPersonaje(const shared_ptr<IPersonaje>& personaje) {
    if (!personaje) {
        cout << "Error: Personaje nulo" << endl;
        return;
    }

    // Mostrar información básica del personaje
    cout << "=== " << personaje->getNombre() << " ===" << endl;
    cout << "Vida: " << personaje->getVida() << endl;
    cout << "Armadura: " << personaje->getArmadura() << endl;
    cout << "Resistencia Mágica: " << personaje->getMagicResistance() << endl;

    // Mostrar armas
    cout << "Armas:" << endl;
    auto armas = personaje->getArmas();
    
    // Primera arma
    cout << "  Principal: ";
    if (armas.first) {
        cout << armas.first->getNombre() 
             << " (Daño: " << armas.first->getDamage() 
             << ", Alcance: " << armas.first->getAlcance() << ")" << endl;
    } else {
        cout << "Ninguna" << endl;
    }
    
    // Segunda arma
    cout << "  Secundaria: ";
    if (armas.second) {
        cout << armas.second->getNombre()
             << " (Daño: " << armas.second->getDamage()
             << ", Alcance: " << armas.second->getAlcance() << ")" << endl;
    } else {
        cout << "Ninguna" << endl;
    }
    
    cout << "===================" << endl;
}

void mostrarPersonajes(const vector<shared_ptr<IPersonaje>>& personajes, const string& tipo) {
    cout << "\n" << tipo << " creados: " << personajes.size() << endl;
    for (const auto& personaje : personajes) {
        mostrarPersonaje(personaje);
        cout << endl;
    }
}

int main() {
    srand(time(0));

    vector<shared_ptr<IPersonaje>> magos;
    vector<shared_ptr<IPersonaje>> guerreros;

    int cantMagos = getRandomNumber(3, 7);
    int cantGuerreros = getRandomNumber(3, 7);

    cout << "Creando " << cantMagos << " magos y " << cantGuerreros << " guerreros..." << endl;

    crearPersonajes(magos, cantMagos, true);
    crearPersonajes(guerreros, cantGuerreros, false);

    mostrarPersonajes(magos, "Magos");
    mostrarPersonajes(guerreros, "Guerreros");

    return 0;
}