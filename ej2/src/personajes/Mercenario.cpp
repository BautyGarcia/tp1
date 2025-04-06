#include "../../headers/personajes/Mercenario.hpp"

Mercenario::Mercenario(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) 
    : Guerrero(nombre, vida, armadura, magicResistance, armas)
{}
