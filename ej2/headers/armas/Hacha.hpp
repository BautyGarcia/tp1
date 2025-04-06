#ifndef HACHA_HPP
#define HACHA_HPP

#include "ArmaCombate.hpp"

using namespace std;

class Hacha : public ArmaCombate {
    public:
        Hacha(string nombre, int damage, int costoMana, int alcance);
};

#endif
