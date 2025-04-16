#ifndef HECHICERO_HPP
#define HECHICERO_HPP

#include "Mago.hpp"

using namespace std;

class Hechicero : public Mago {
    public:
        Hechicero(string nombre, int mana, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif
