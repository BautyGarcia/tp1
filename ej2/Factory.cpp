#include "Factory.hpp"

unique_ptr<IArma> Factory::crearArma(Armas arma) {
    try {
        switch (arma) {
            case Armas::ESPADA:
                return make_unique<Espada>("Espada", 50, 2);
            case Armas::HACHA:
                return make_unique<Hacha>("Hacha", 55, 1);
            case Armas::LANZA:
                return make_unique<Lanza>("Lanza", 45, 3);
            case Armas::HACHA_DOBLE:
                return make_unique<HachaDoble>("Hacha Doble", 65, 1);
            case Armas::GARROTE:
                return make_unique<Garrote>("Garrote", 40, 1);
            case Armas::AMULETO:
                return make_unique<Amuleto>("Amuleto", 30, 25, 3);
            case Armas::BASTON:
                return make_unique<Baston>("Baston", 40, 30, 4);
            case Armas::LIBRO_DE_HECHIZOS:
                return make_unique<LibroDeHechizos>("Libro de Hechizos", 20, 20, 5);
            case Armas::POCION:
                return make_unique<Pocion>("Pocion", 0, 10, 1);
            default:
                return nullptr;
        }
    } catch (const bad_alloc& e) {
        cout << "Error al crear el arma" << endl;
        return nullptr;
    }
}

unique_ptr<IPersonaje> Factory::crearPersonajeArmado(Personajes personaje, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas) {
    try {
        switch (personaje) {
            case Personajes::BARBARO:
                return make_unique<Barbaro>("Barbaro", 180, 25, 5, std::move(armas));
            case Personajes::CABALLERO:
                return make_unique<Caballero>("Caballero", 150, 30, 10, std::move(armas));
            case Personajes::MERCENARIO:
                return make_unique<Mercenario>("Mercenario", 140, 20, 10, std::move(armas));
            case Personajes::PALADIN:
                return make_unique<Paladin>("Paladin", 160, 25, 25, std::move(armas));
            case Personajes::GLADIADOR:
                return make_unique<Gladiador>("Gladiador", 170, 20, 5, std::move(armas));
            case Personajes::NIGROMANTE:
                return make_unique<Nigromante>("Nigromante", 150, 110, 5, 35, std::move(armas));
            case Personajes::CONJURADOR:
                return make_unique<Conjurador>("Conjurador", 150, 120, 8, 25, std::move(armas));
            case Personajes::HECHICERO:
                return make_unique<Hechicero>("Hechicero", 150, 100, 5, 30, std::move(armas));
            case Personajes::BRUJO:
                return make_unique<Brujo>("Brujo", 150, 115, 10, 30, std::move(armas));
            default:
                return nullptr;
        }
    } catch (const bad_alloc& e) {
        cout << "Error al crear el personaje" << endl;
        return nullptr;
    }
}

unique_ptr<IPersonaje> Factory::crearPersonaje(Personajes personaje) {
    return Factory::crearPersonajeArmado(personaje, {nullptr, nullptr});
}