#include "../ej2/headers/armas/Amuleto.hpp"
#include "../ej2/headers/armas/Baston.hpp"
#include "../ej2/headers/armas/LibroDeHechizos.hpp"
#include "../ej2/headers/armas/Pocion.hpp"

#include "../ej2/headers/armas/Espada.hpp"
#include "../ej2/headers/armas/Hacha.hpp"
#include "../ej2/headers/armas/Lanza.hpp"
#include "../ej2/headers/armas/HachaDoble.hpp"
#include "../ej2/headers/armas/Garrote.hpp"

#include "../ej2/headers/personajes/Brujo.hpp"
#include "../ej2/headers/personajes/Conjurador.hpp"
#include "../ej2/headers/personajes/Hechicero.hpp"
#include "../ej2/headers/personajes/Nigromante.hpp"

#include "../ej2/headers/personajes/Barbaro.hpp"
#include "../ej2/headers/personajes/Caballero.hpp"
#include "../ej2/headers/personajes/Mercenario.hpp"
#include "../ej2/headers/personajes/Paladin.hpp"
#include "../ej2/headers/personajes/Gladiador.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

enum class Personajes {
    BARBARO,
    CABALLERO,
    MERCENARIO,
    PALADIN,
    GLADIADOR,
    NIGROMANTE,
    CONJURADOR,
    HECHICERO,
    BRUJO,
};

enum class Armas {
    ESPADA,
    HACHA,
    LANZA,
    HACHA_DOBLE,
    GARROTE,
    AMULETO,
    BASTON,
    LIBRO_DE_HECHIZOS,
    POCION,
};

class Factory {
    public:
        static shared_ptr<IArma> crearArma(Armas arma);
        static shared_ptr<IPersonaje> crearPersonaje(Personajes personaje, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};