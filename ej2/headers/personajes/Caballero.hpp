#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "Guerrero.hpp"

using namespace std;

class Caballero : public Guerrero {
    public:
        Caballero(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif