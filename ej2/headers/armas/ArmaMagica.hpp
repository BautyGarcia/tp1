#ifndef ARMAMAGICA_HPP
#define ARMAMAGICA_HPP

#include "IArma.hpp"

using namespace std;

class IEfecto;
class IPersonaje;

class ArmaMagica : public IArma {
    private:
        string nombre;
        int damage;
        int costoMana;
        int alcance;
        shared_ptr<IEfecto> efecto;
    public:
        ArmaMagica(string nombre, int damage, int costoMana, int alcance, shared_ptr<IEfecto> efecto);
        string getNombre() const override;
        int getDamage() const override;
        int getAlcance() const override;
        int getCostoMana() const;
        virtual void mostrarInfo() const override = 0;
        void usar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) override;
};

#endif