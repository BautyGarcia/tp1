#ifndef POCION_HPP
#define POCION_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Pocion : public ArmaMagica {
    public:
        Pocion(string nombre, int damage, int costoMana, int alcance);
};

#endif