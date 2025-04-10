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
void simularBatalla(shared_ptr<IPersonaje> jugador, shared_ptr<IPersonaje> rival);
int seleccionarPersonaje();
shared_ptr<IArma> seleccionarArma();
shared_ptr<IPersonaje> crearPersonajeAleatorio();
string obtenerBarraVida(int vida);
void mostrarMarcadorBatalla(shared_ptr<IPersonaje> jugador, shared_ptr<IPersonaje> rival, int vidaJugador, int vidaRival);