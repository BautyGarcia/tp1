#ifndef IPERSONAJE_HPP
#define IPERSONAJE_HPP

#include "../../utils/utils.hpp"
#include "../armas/IArma.hpp"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

class IPersonaje {
    public:
        virtual string getNombre() const = 0;
        virtual int getMana() const = 0;
        virtual int getVida() const = 0;
        virtual int getArmadura() const = 0;
        virtual int getResistenciaMagica() const = 0;
        virtual int getTurnosRestantesEfecto() const = 0;
        virtual int getDamageBoost() const = 0;
        virtual pair<unique_ptr<IArma>, unique_ptr<IArma>>& getArmas() = 0;
        virtual void recibirDamage(int damage) = 0;
        virtual void curarVida(int cantidad) = 0;
        virtual void gastarMana(int cantidad) = 0;
        virtual void aplicarEfecto(Efecto efecto, int duracion) = 0;
        virtual void restarTurnoEfecto() = 0;
        virtual void boostDamage(int porcentaje) = 0;
        virtual void propagarEfecto() = 0;
        virtual Efecto getEfecto() const = 0;
        virtual void mostrarInfo() const = 0;
        virtual ~IPersonaje() = default;
};

#endif