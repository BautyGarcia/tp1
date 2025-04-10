#ifndef IARMA_HPP
#define IARMA_HPP

#include "../../utils/utils.hpp"
#include "../efectos/IEfecto.hpp"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

class IPersonaje;

class IArma {
    public:
        virtual string getNombre() const = 0;
        virtual int getDamage() const = 0;
        virtual int getAlcance() const = 0;
        virtual void mostrarInfo() const = 0;
        virtual void usar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) = 0;
        virtual ~IArma() = default;
};

#endif