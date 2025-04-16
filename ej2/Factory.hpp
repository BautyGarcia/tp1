#include "../ej1/headers/armas/Amuleto.hpp"
#include "../ej1/headers/armas/Baston.hpp"
#include "../ej1/headers/armas/LibroDeHechizos.hpp"
#include "../ej1/headers/armas/Pocion.hpp"

#include "../ej1/headers/armas/Espada.hpp"
#include "../ej1/headers/armas/Hacha.hpp"
#include "../ej1/headers/armas/Lanza.hpp"
#include "../ej1/headers/armas/HachaDoble.hpp"
#include "../ej1/headers/armas/Garrote.hpp"

#include "../ej1/headers/personajes/Brujo.hpp"
#include "../ej1/headers/personajes/Conjurador.hpp"
#include "../ej1/headers/personajes/Hechicero.hpp"
#include "../ej1/headers/personajes/Nigromante.hpp"

#include "../ej1/headers/personajes/Barbaro.hpp"
#include "../ej1/headers/personajes/Caballero.hpp"
#include "../ej1/headers/personajes/Mercenario.hpp"
#include "../ej1/headers/personajes/Paladin.hpp"
#include "../ej1/headers/personajes/Gladiador.hpp"

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


// Nota, permito el crear un personaje sin armas, pero nunca lo uso
// Esta implementacion es solamente para cumplir con lo pedido en el enunciado
// No le encontre una razon practica para usarlo
class Factory {
    public:
        static unique_ptr<IArma> crearArma(Armas arma);
        static unique_ptr<IPersonaje> crearPersonaje(Personajes personaje);
        static unique_ptr<IPersonaje> crearPersonajeArmado(Personajes personaje, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
};