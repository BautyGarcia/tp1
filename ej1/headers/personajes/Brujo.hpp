#ifndef BRUJO_HPP
#define BRUJO_HPP

#include "Mago.hpp"

using namespace std;

class Brujo : public Mago {
    public:
        Brujo(string nombre, int mana, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif
