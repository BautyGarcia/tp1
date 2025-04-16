#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "Guerrero.hpp"

using namespace std;

class Caballero : public Guerrero {
    public:
        Caballero(string nombre, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif