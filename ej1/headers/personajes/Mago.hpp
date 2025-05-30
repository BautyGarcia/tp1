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
        int resistenciaMagica;
        int damageBoost;
        pair<unique_ptr<IArma>, unique_ptr<IArma>> armas;
        Efecto efectoActual;
        int turnosRestantesEfecto;
    public:
        Mago(string nombre, int mana, int vida, int armadura, int resistenciaMagica, pair<unique_ptr<IArma>, unique_ptr<IArma>> armas);
        string getNombre() const override;
        int getMana() const override;
        int getVida() const override;
        int getArmadura() const override;
        int getResistenciaMagica() const override;
        int getTurnosRestantesEfecto() const override;
        int getDamageBoost() const override;
        const pair<unique_ptr<IArma>, unique_ptr<IArma>>& getArmas() const override;
        void recibirDamage(int damage) override;
        void curarVida(int cantidad) override;
        void gastarMana(int cantidad) override;
        void aplicarEfecto(Efecto efecto, int duracion) override;
        void restarTurnoEfecto() override;
        void boostDamage(int porcentaje) override;
        void propagarEfecto() override;
        void mostrarInfo() const override = 0;
        Efecto getEfecto() const override;
};

#endif
