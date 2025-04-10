#ifndef BASTON_HPP
#define BASTON_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Baston : public ArmaMagica {
    public:
        Baston(string nombre, int damage, int costoMana, int alcance);
        void mostrarInfo() const override;
};

#endif
