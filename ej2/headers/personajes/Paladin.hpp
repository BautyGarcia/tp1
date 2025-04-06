#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "Guerrero.hpp"

using namespace std;

class Paladin : public Guerrero {
    public:
        Paladin(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif