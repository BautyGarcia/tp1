#include "main.hpp"

using namespace std;

// Validacion de input usada en homework 2
bool isValidInput() {
    if (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// Limpieza de terminal usada en homework 2
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrarOpcionesPersonaje() {
    cout << "\nPersonajes Disponibles:" << endl;
    cout << "=== Guerreros ===" << endl;
    cout << "0. Bárbaro" << endl;
    cout << "1. Caballero" << endl;
    cout << "2. Mercenario" << endl;
    cout << "3. Paladín" << endl;
    cout << "4. Gladiador" << endl;
    cout << "=== Magos ===" << endl;
    cout << "5. Nigromante" << endl;
    cout << "6. Conjurador" << endl;
    cout << "7. Hechicero" << endl;
    cout << "8. Brujo" << endl;
}

void mostrarOpcionesArma() {
    cout << "\nArmas Disponibles:" << endl;
    cout << "=== Armas de Combate ===" << endl;
    cout << "0. Espada" << endl;
    cout << "1. Hacha" << endl;
    cout << "2. Lanza" << endl;
    cout << "3. Hacha Doble" << endl;
    cout << "4. Garrote" << endl;
    cout << "=== Armas Mágicas ===" << endl;
    cout << "5. Amuleto" << endl;
    cout << "6. Bastón" << endl;
    cout << "7. Libro de Hechizos" << endl;
    cout << "8. Poción" << endl;
}

void mostrarOpcionesAtaque() {
    cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
}

// Input de seleccion de ataque
TipoAtaque seleccionarAtaque() {
    int opcion;
    bool inputInvalido = false;
    
    while (true) {
        if (inputInvalido) {
            cout << "==================================================" << endl;
            cout << "Opción inválida. Intente nuevamente." << endl;
            cout << "==================================================" << endl;
            cout << endl;
        }
        
        mostrarOpcionesAtaque();
        cin >> opcion;

        if (!isValidInput() || opcion < 1 || opcion > 3) {
            inputInvalido = true;
            continue;
        }

        return static_cast<TipoAtaque>(opcion - 1);
    }
}

// Genera un ataque aleatorio para el rival
TipoAtaque ataqueAleatorio() {
    return static_cast<TipoAtaque>(rand() % 3);
}

// Obtiene el nombre (string) del ataque
string obtenerNombreAtaque(TipoAtaque ataque) {
    switch (ataque) {
        case TipoAtaque::GOLPE_FUERTE: return "Golpe Fuerte";
        case TipoAtaque::GOLPE_RAPIDO: return "Golpe Rápido";
        case TipoAtaque::DEFENSA_Y_GOLPE: return "Defensa y Golpe";
        default: return "Desconocido";
    }
}

// Input de seleccion de personaje, sigue hasta que el input sea valido
int seleccionarPersonaje() {
    int opcion;
    
    while (true) {
        mostrarOpcionesPersonaje();
        cout << "\nSeleccione un personaje (0-8): ";
        cin >> opcion;

        if (!isValidInput() || opcion < 0 || opcion > 8) {
            ClearScreen();
            cout << "Opción inválida. Intente nuevamente." << endl;
            continue;
        }

        return opcion;
    }
}

// Input de seleccion de arma, sigue hasta que el input sea valido, una vez seleccionado, crea el arma
shared_ptr<IArma> obtenerArma() {
    int opcion;
    
    while (true) {
        mostrarOpcionesArma();
        cout << "\nSeleccione un arma (0-8): ";
        cin >> opcion;

        if (!isValidInput() || opcion < 0 || opcion > 8) {
            ClearScreen();
            cout << "Opción inválida. Intente nuevamente." << endl;
            continue;
        }

        return Factory::crearArma(static_cast<Armas>(opcion));
    }
}

// Genera un personaje aleatorio
shared_ptr<IPersonaje> crearPersonajeAleatorio() {
    // Personaje aleatorio (0-8)
    Personajes tipoPersonaje = static_cast<Personajes>(rand() % 9);
    
    // Arma aleatoria (0-8)
    Armas tipoArma = static_cast<Armas>(rand() % 9);
    shared_ptr<IArma> armaAleatoria = Factory::crearArma(tipoArma);

    return Factory::crearPersonajeArmado(tipoPersonaje, {armaAleatoria, nullptr});
}


// Auxiliar para mostrar la barra de vida en la batalla
string obtenerBarraVida(int vida) {
    string barra = "[";
    int numHashtags = vida / 10;
    for (int i = 0; i < 10; i++) {
        barra += (i < numHashtags) ? "#" : " ";
    }
    barra += "] " + to_string(vida) + "/100";
    return barra;
}

// Muestra el marcador de la batalla
void mostrarMarcadorBatalla(shared_ptr<IPersonaje> jugador, shared_ptr<IPersonaje> rival, int vidaJugador, int vidaRival) {
    cout << "==================== ¡Batalla! ====================" << endl;
    cout << "Jugador 1:" << endl;
    cout << jugador->getNombre() << " con " << jugador->getArmas().first->getNombre() << endl;
    cout << obtenerBarraVida(vidaJugador) << endl;
    cout << "\nJugador 2 (CPU):" << endl;
    cout << rival->getNombre() << " con " << rival->getArmas().first->getNombre() << endl;
    cout << obtenerBarraVida(vidaRival) << endl;
    cout << "==================================================" << endl;
}

// Simula la batalla
void simularBatalla(shared_ptr<IPersonaje> jugador, shared_ptr<IPersonaje> rival) {
    // Creo variables aparte para la vida, no utilizo la vida perteneciente al objeto personaje
    int vidaJugador = 100;
    int vidaRival = 100;
    int turno = 1;
    string mensajeResultado = "";
    
    // A la que uno muere, se termina la batalla
    while (vidaJugador > 0 && vidaRival > 0) {
        ClearScreen();

        // Scoreboard con personajes y vida
        mostrarMarcadorBatalla(jugador, rival, vidaJugador, vidaRival);
        cout << endl;
        
        // Mensaje del resultado del turno
        if (!mensajeResultado.empty()) {
            cout << "==================== Resultado =====================" << endl;
            cout << mensajeResultado << endl;
            cout << "==================================================" << endl;
            cout << endl;
        }
        
        // Marcado del numero de turno
        cout << "==================== Turno " << turno << " ====================" << endl;
        
        TipoAtaque ataqueJugador = seleccionarAtaque();
        TipoAtaque ataqueRival = ataqueAleatorio();
        
        cout << "==================================================" << endl;
        
        // Calculo el resultado del turno (Piedra, Papel, Tijera)
        if (ataqueJugador == ataqueRival) {
            mensajeResultado = "¡Empate! Ningún jugador recibe daño.";
        } else if (
            (ataqueJugador == TipoAtaque::GOLPE_FUERTE && ataqueRival == TipoAtaque::GOLPE_RAPIDO) ||
            (ataqueJugador == TipoAtaque::GOLPE_RAPIDO && ataqueRival == TipoAtaque::DEFENSA_Y_GOLPE) ||
            (ataqueJugador == TipoAtaque::DEFENSA_Y_GOLPE && ataqueRival == TipoAtaque::GOLPE_FUERTE)
        ) {
            vidaRival -= 10;
            mensajeResultado = jugador->getNombre() + " ataca con " + jugador->getArmas().first->getNombre() 
                            + " y hace 10 puntos de daño.";
        } else {
            vidaJugador -= 10;
            mensajeResultado = rival->getNombre() + " ataca con " + rival->getArmas().first->getNombre() 
                            + " y hace 10 puntos de daño.";
        }
        
        turno++;
    }
    
    ClearScreen();
    mostrarMarcadorBatalla(jugador, rival, vidaJugador, vidaRival);
    cout << endl;
    cout << "==================== Fin de la Batalla ====================" << endl;
    if (vidaJugador <= 0) {
        cout << "¡" << rival->getNombre() << " es el ganador!" << endl;
    } else {
        cout << "¡" << jugador->getNombre() << " es el ganador!" << endl;
    }
    cout << "======================================================" << endl;
}

// Nota, como el caso de bad_alloc ya esta manejado desde la clase Factory, solamente
// Reviso que los punteros no sean nulos
int main() {
    // Reinicio seed para que los numeros sean aleatorios
    srand(time(0));

    ClearScreen();
    cout << "=== Creación del Personaje del Jugador 1 ===" << endl;
    
    // Obtengo el numero de personaje del jugador
    int opcion_jugador = seleccionarPersonaje();
    
    ClearScreen();

    // Pido y creo el arma del jugador
    shared_ptr<IArma> arma = obtenerArma();

    if (arma == nullptr) {
        cout << "Error al crear el arma" << endl;
        return 1;
    }

    // Pido y creo el personaje del jugador
    shared_ptr<IPersonaje> jugador = Factory::crearPersonajeArmado(
        static_cast<Personajes>(opcion_jugador),
        {arma, nullptr}
    );

    if (jugador == nullptr) {
        cout << "Error al crear el personaje" << endl;
        return 1;
    }

    // Creo el personaje del rival
    shared_ptr<IPersonaje> rival = crearPersonajeAleatorio();

    if (rival == nullptr) {
        cout << "Error al crear el personaje del rival" << endl;
        return 1;
    }

    mostrarMarcadorBatalla(jugador, rival, 100, 100);
    cout << endl;
    simularBatalla(jugador, rival);

    return 0;
}