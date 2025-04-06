#ifndef EFECTOSCOMBATE_HPP
#define EFECTOSCOMBATE_HPP

#include "IEfecto.hpp"

using namespace std;

class EfectoSangrado : public IEfecto {
    private:
        static const int cantidad = 50;
    public:
        EfectoSangrado();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
        static const int getCantidad();
};

class EmptyEfecto : public IEfecto {
    public:
        EmptyEfecto();
        void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) override;
        string getNombre() const override;
};

#endif