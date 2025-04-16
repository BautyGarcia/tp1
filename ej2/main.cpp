#include "Factory.hpp"

using namespace std;

// Genera un numero aleatorio entre el rango [min, max]
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Genera una arma aleatoria magica o no magica
unique_ptr<IArma> getRandomArma(bool isMago) {
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

// Genera un personaje aleatorio magico o no magico
unique_ptr<IPersonaje> getRandomPersonaje(bool isMago, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) {
    if (isMago) {
        switch (getRandomNumber(0, 3)) {
            case 0: return Factory::crearPersonajeArmado(Personajes::NIGROMANTE, std::move(armas));
            case 1: return Factory::crearPersonajeArmado(Personajes::CONJURADOR, std::move(armas));
            case 2: return Factory::crearPersonajeArmado(Personajes::HECHICERO, std::move(armas));
            case 3: return Factory::crearPersonajeArmado(Personajes::BRUJO, std::move(armas));
            default: return nullptr;
        }
    } else {
        switch (getRandomNumber(0, 4)) {
            case 0: return Factory::crearPersonajeArmado(Personajes::BARBARO, std::move(armas));
            case 1: return Factory::crearPersonajeArmado(Personajes::CABALLERO, std::move(armas));
            case 2: return Factory::crearPersonajeArmado(Personajes::MERCENARIO, std::move(armas));
            case 3: return Factory::crearPersonajeArmado(Personajes::PALADIN, std::move(armas));
            case 4: return Factory::crearPersonajeArmado(Personajes::GLADIADOR, std::move(armas));
            default: return nullptr;
        }
    }
}

// Agrega una cantidad N de personajes magicos o no magicos a un vector pasado por referencia
void crearPersonajes(vector<unique_ptr<IPersonaje>>& personajes, int cantidad, bool isMago) {
    for (int i = 0; i < cantidad; i++) {
        int cantArmas = getRandomNumber(0, 2);
        
        pair<unique_ptr<IArma>, unique_ptr<IArma>> armas;
        armas.first = (cantArmas > 0) ? getRandomArma(isMago) : nullptr;
        armas.second = (cantArmas > 1) ? getRandomArma(isMago) : nullptr;

        auto personaje = getRandomPersonaje(isMago, std::move(armas));
        if (personaje) personajes.push_back(std::move(personaje));
    }
}

// Muestra los datos de un personaje
void mostrarPersonaje(const IPersonaje* personaje) {
    if (!personaje) {
        cout << "Error: Personaje nulo" << endl;
        return;
    }

    cout << "=== " << personaje->getNombre() << " ===" << endl;
    cout << "Vida: " << personaje->getVida() << endl;
    cout << "Armadura: " << personaje->getArmadura() << endl;
    cout << "Resistencia Mágica: " << personaje->getResistenciaMagica() << endl;

    cout << "Armas:" << endl;
    const auto& armas = personaje->getArmas();
    
    cout << "  Principal: ";
    if (armas.first) {
        cout << armas.first->getNombre() 
             << " (Daño: " << armas.first->getDamage() 
             << ", Alcance: " << armas.first->getAlcance() << ")" << endl;
    } else {
        cout << "Ninguna" << endl;
    }
    
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

// Muestra los personajes de un vector pasado por referencia
void mostrarPersonajes(const vector<unique_ptr<IPersonaje>>& personajes, const string& tipo) {
    cout << "\n" << tipo << " creados: " << personajes.size() << endl;
    for (const auto& personaje : personajes) {
        // Validacion por si no se pudo alocar memoria para el personaje
        if (personaje) {
            mostrarPersonaje(personaje.get());
            cout << endl;
        }
    }
}

int main() {
    srand(time(0));

    vector<unique_ptr<IPersonaje>> magos;
    vector<unique_ptr<IPersonaje>> guerreros;

    int cantMagos = getRandomNumber(3, 7);
    int cantGuerreros = getRandomNumber(3, 7);

    cout << "Creando " << cantMagos << " magos y " << cantGuerreros << " guerreros..." << endl;

    crearPersonajes(magos, cantMagos, true);
    crearPersonajes(guerreros, cantGuerreros, false);

    mostrarPersonajes(magos, "Magos");
    mostrarPersonajes(guerreros, "Guerreros");

    return 0;
}