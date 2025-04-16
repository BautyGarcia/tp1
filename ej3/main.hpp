#include <cstdlib>
#include <ctime>
#include <limits>

#include "../ej2/Factory.hpp"

enum class TipoAtaque {
    GOLPE_FUERTE,
    GOLPE_RAPIDO,
    DEFENSA_Y_GOLPE
};

bool isValidInput();
void ClearScreen();
void mostrarOpcionesPersonaje();
void mostrarOpcionesArma();
void mostrarOpcionesAtaque();
TipoAtaque seleccionarAtaque();
TipoAtaque ataqueAleatorio();
void simularBatalla(unique_ptr<IPersonaje>& jugador, unique_ptr<IPersonaje>& rival);
int seleccionarPersonaje();
unique_ptr<IArma> obtenerArma();
unique_ptr<IPersonaje> crearPersonajeAleatorio();
string obtenerBarraVida(int vida);
void mostrarMarcadorBatalla(const IPersonaje* jugador, const IPersonaje* rival, int vidaJugador, int vidaRival);