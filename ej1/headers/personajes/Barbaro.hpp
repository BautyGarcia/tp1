#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "Guerrero.hpp"

using namespace std;

class Barbaro : public Guerrero {
    public:
        Barbaro(string nombre, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif