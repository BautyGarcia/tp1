#ifndef HACHA_DOBLE_HPP
#define HACHA_DOBLE_HPP

#include "ArmaCombate.hpp"

using namespace std;

class HachaDoble : public ArmaCombate {
    public:
        HachaDoble(string nombre, int damage, int costoMana, int alcance);
};

#endif
