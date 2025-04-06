#include "../../headers/personajes/Hechicero.hpp"

Hechicero::Hechicero(string nombre, int mana, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas) : 
    Mago(nombre, mana, vida, armadura, magicResistance, armas) 
{}
