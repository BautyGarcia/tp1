#ifndef EFECTOSMAGICOS_HPP
#define EFECTOSMAGICOS_HPP

#include "IEfecto.hpp"

using namespace std;

class Stun : public IEfecto {
    private:
        const float probabilidad = 20;
    public:
        Stun();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
};

class CurarVida : public IEfecto {
    private:
        const int cantidad = 100;
    public:
        CurarVida();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
    };

class BoostMagico : public IEfecto {
    private:
        const int porcentaje = 25;
    public:
        BoostMagico();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
};

class RoboDeVida : public IEfecto {
    private:
        const int porcentaje = 15;
    public:
        RoboDeVida();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
};

#endif