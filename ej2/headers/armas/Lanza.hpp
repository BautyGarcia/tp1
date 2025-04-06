#ifndef LANZA_HPP
#define LANZA_HPP

#include "ArmaCombate.hpp"

using namespace std;

class Lanza : public ArmaCombate {
    public:
        Lanza(string nombre, int damage, int costoMana, int alcance);
};

#endif
