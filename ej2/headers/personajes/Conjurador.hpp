#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "Mago.hpp"

using namespace std;

class Conjurador : public Mago {
    public:
        Conjurador(string nombre, int mana, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif
