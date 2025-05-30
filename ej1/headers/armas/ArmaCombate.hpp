#ifndef ARMACOMBATE_HPP
#define ARMACOMBATE_HPP

#include "IArma.hpp"

using namespace std;

class IEfecto;
class IPersonaje;

class ArmaCombate : public IArma {
    private:
        string nombre;
        int damage;
        int alcance;
        int usosRestantes;
        unique_ptr<IEfecto> efecto;
    public:
        ArmaCombate(string nombre, int damage, int alcance, unique_ptr<IEfecto> efecto);
        string getNombre() const override;
        int getDamage() const override;
        int getAlcance() const override;
        virtual void mostrarInfo() const override = 0;
        void usar(IPersonaje* personaje, IPersonaje* objetivo) override;
        void reparar();
};

#endif