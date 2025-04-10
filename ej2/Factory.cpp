#include "Factory.hpp"

shared_ptr<IArma> Factory::crearArma(Armas arma) {
    try {
        switch (arma) {
            case Armas::ESPADA:
                return make_shared<Espada>("Espada", 50, 2);
            case Armas::HACHA:
                return make_shared<Hacha>("Hacha", 55, 1);
            case Armas::LANZA:
                return make_shared<Lanza>("Lanza", 45, 3);
            case Armas::HACHA_DOBLE:
                return make_shared<HachaDoble>("Hacha Doble", 65, 1);
            case Armas::GARROTE:
                return make_shared<Garrote>("Garrote", 40, 1);
            case Armas::AMULETO:
                return make_shared<Amuleto>("Amuleto", 30, 25, 3);
            case Armas::BASTON:
                return make_shared<Baston>("Baston", 40, 30, 4);
            case Armas::LIBRO_DE_HECHIZOS:
                return make_shared<LibroDeHechizos>("Libro de Hechizos", 20, 20, 5);
            case Armas::POCION:
                return make_shared<Pocion>("Pocion", 0, 10, 1);
            default:
                return nullptr;
        }
    } catch (const bad_alloc& e) {
        cout << "Error al crear el arma" << endl;
        return nullptr;
    }
}

shared_ptr<IPersonaje> Factory::crearPersonajeArmado(Personajes personaje, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) {
    try {
        switch (personaje) {
            case Personajes::BARBARO:
                return make_shared<Barbaro>("Barbaro", 180, 25, 5, armas);
            case Personajes::CABALLERO:
                return make_shared<Caballero>("Caballero", 150, 30, 10, armas);
            case Personajes::MERCENARIO:
                return make_shared<Mercenario>("Mercenario", 140, 20, 10, armas);
            case Personajes::PALADIN:
                return make_shared<Paladin>("Paladin", 160, 25, 25, armas);
            case Personajes::GLADIADOR:
                return make_shared<Gladiador>("Gladiador", 170, 20, 5, armas);
            case Personajes::NIGROMANTE:
                return make_shared<Nigromante>("Nigromante", 150, 110, 5, 35, armas);
            case Personajes::CONJURADOR:
                return make_shared<Conjurador>("Conjurador", 150, 120, 8, 25, armas);
            case Personajes::HECHICERO:
                return make_shared<Hechicero>("Hechicero", 150, 100, 5, 30, armas);
            case Personajes::BRUJO:
                return make_shared<Brujo>("Brujo", 150, 115, 10, 30, armas);
            default:
                return nullptr;
        }
    } catch (const bad_alloc& e) {
        cout << "Error al crear el personaje" << endl;
        return nullptr;
    }
}

shared_ptr<IPersonaje> Factory::crearPersonaje(Personajes personaje) {
    return Factory::crearPersonajeArmado(personaje, {nullptr, nullptr});
}