#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "Guerrero.hpp"

using namespace std;

class Gladiador : public Guerrero {
    public:
        Gladiador(string nombre, int vida, int armadura, int magicResistance, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        void mostrarInfo() const override;
};

#endif