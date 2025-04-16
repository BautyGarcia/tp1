#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP

#include "Mago.hpp"

using namespace std;

class Nigromante : public Mago {
    public:
        Nigromante(string nombre, int mana, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif
