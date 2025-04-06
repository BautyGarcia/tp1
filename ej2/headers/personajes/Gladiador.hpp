#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "Guerrero.hpp"

using namespace std;

class Gladiador : public Guerrero {
    public:
        Gladiador(string nombre, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
};

#endif