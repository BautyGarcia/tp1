#ifndef EFECTOSCOMBATE_HPP
#define EFECTOSCOMBATE_HPP

#include "IEfecto.hpp"

using namespace std;

class Sangrado : public IEfecto {
    private:
        static const int cantidad = 30;
    public:
        Sangrado();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
        static const int getCantidad();
};

class Nada : public IEfecto {
    public:
        Nada();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
};

#endif