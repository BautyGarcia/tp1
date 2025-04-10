#ifndef LIBRODEHECHIZOS_HPP
#define LIBRODEHECHIZOS_HPP

#include "ArmaMagica.hpp"

using namespace std;

class LibroDeHechizos : public ArmaMagica {
    public:
        LibroDeHechizos(string nombre, int damage, int costoMana, int alcance);
        void mostrarInfo() const override;
};

#endif
