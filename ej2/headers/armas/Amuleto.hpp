#ifndef AMULETO_HPP
#define AMULETO_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Amuleto : public ArmaMagica {
    public:
        Amuleto(string nombre, int damage, int costoMana, int alcance);
};

#endif