#ifndef EFECTOSMAGICOS_HPP
#define EFECTOSMAGICOS_HPP

#include "IEfecto.hpp"

using namespace std;

class Stun : public IEfecto {
    private:
        const int probabilidad = 20;
    public:
        Stun();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
};

class CurarVida : public IEfecto {
    private:
        const int cantidad = 100;
    public:
        CurarVida();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
    };

class BoostMagico : public IEfecto {
    private:
        const int porcentaje = 25;
    public:
        BoostMagico();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
};

class RoboDeVida : public IEfecto {
    private:
        const int porcentaje = 15;
    public:
        RoboDeVida();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
};

#endif