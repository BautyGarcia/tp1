#ifndef GARROTE_HPP
#define GARROTE_HPP

#include "ArmaCombate.hpp"

using namespace std;

class Garrote : public ArmaCombate {
    public:
        Garrote(string nombre, int damage, int alcance);
        void mostrarInfo() const override;
};

#endif
