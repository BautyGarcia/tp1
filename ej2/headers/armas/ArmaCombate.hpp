#ifndef ARMAMAGICA_HPP
#define ARMAMAGICA_HPP

#include "IArma.hpp"

using namespace std;

class IEfecto;
class IPersonaje;

class ArmaCombate : public IArma {
    private:
        string nombre;
        int damage;
        int costoMana;
        int alcance;
        static const TipoArma tipo = TipoArma::COMBATE;
        shared_ptr<IEfecto> efecto;
    public:
        ArmaCombate(string nombre, int damage, int costoMana, int alcance, shared_ptr<IEfecto> efecto);
        string getNombre() const override;
        TipoArma getTipo() const override;
        int getDamage() const override;
        int getAlcance() const override;
        int getCostoMana() const;
        void usar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) override;
};

#endif