#ifndef HECHICERO_HPP
#define HECHICERO_HPP

#include "Mago.hpp"

using namespace std;

class Hechicero : public Mago {
    public:
        Hechicero(string nombre, int mana, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif
