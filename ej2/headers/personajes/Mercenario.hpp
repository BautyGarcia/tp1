#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP

#include "Guerrero.hpp"

using namespace std;

class Mercenario : public Guerrero {
    public:
        Mercenario(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif