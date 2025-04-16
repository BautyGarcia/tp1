#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "Mago.hpp"

using namespace std;

class Conjurador : public Mago {
    public:
        Conjurador(string nombre, int mana, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif
