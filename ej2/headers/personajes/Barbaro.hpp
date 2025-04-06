#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "Guerrero.hpp"

using namespace std;

class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif