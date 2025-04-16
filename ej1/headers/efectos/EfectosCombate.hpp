#ifndef EFECTOSCOMBATE_HPP
#define EFECTOSCOMBATE_HPP

#include "IEfecto.hpp"

using namespace std;

class Sangrado : public IEfecto {
    private:
        static const int cantidad = 30;
    public:
        Sangrado();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
        static int getCantidad();
};

class Nada : public IEfecto {
    public:
        Nada();
        void aplicar(IPersonaje* usuario, IPersonaje* objetivo) override;
        string getNombre() const override;
};

#endif