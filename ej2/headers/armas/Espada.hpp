#ifndef ESPADA_HPP
#define ESPADA_HPP

#include "ArmaCombate.hpp"

using namespace std;

class Espada : public ArmaCombate {
    public:
        Espada(string nombre, int damage, int alcance);
        void mostrarInfo() const override;
};

#endif
