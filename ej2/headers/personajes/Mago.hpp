#ifndef MAGO_HPP
#define MAGO_HPP

#include "IPersonaje.hpp"

using namespace std;

class Mago : public IPersonaje {
    private:
        string nombre;
        int mana;
        int vida;
        int armadura;
        int magicResistance;
        int damageBoost;
        pair<shared_ptr<IArma>, shared_ptr<IArma>> armas;
        Efecto efectoActual;
        int turnosRestantesEfecto;
    public:
        Mago(string nombre, int mana, int vida, int armadura, int magicResistance, pair<shared_ptr<IArma>, shared_ptr<IArma>> armas);
        int getMana() const override;
        int getVida() const override;
        int getArmadura() const override;
        int getMagicResistance() const override;
        int getTurnosRestantesEfecto() const override;
        int getDamageBoost() const override;
        void recibirDamage(int damage) override;
        void curarVida(int cantidad) override;
        void gastarMana(int cantidad) override;
        void aplicarEfecto(Efecto efecto, int duracion) override;
        void restarTurnoEfecto() override;
        void boostDamage(int porcentaje) override;
        void propagarEfecto() override;
        Efecto getEfecto() const override;
};

#endif
