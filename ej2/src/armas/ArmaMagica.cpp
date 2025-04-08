#include "../../headers/efectos/IEfecto.hpp"
#include "../../headers/armas/ArmaMagica.hpp"
#include "../../headers/personajes/IPersonaje.hpp"

using namespace std;

ArmaMagica::ArmaMagica(string nombre, int damage, int costoMana, int alcance, shared_ptr<IEfecto> efecto) : 
    nombre(nombre),
    damage(damage),
    costoMana(costoMana),
    alcance(alcance),
    efecto(efecto) 
{}

string ArmaMagica::getNombre() const {
    return this->nombre;
}

int ArmaMagica::getDamage() const {
    return this->damage;
}

int ArmaMagica::getAlcance() const {
    return this->alcance;
}

int ArmaMagica::getCostoMana() const {
    return this->costoMana;
}

void ArmaMagica::usar(shared_ptr<IPersonaje> personaje, shared_ptr<IPersonaje> objetivo) {
    // Validacion de mana
    if (personaje->getMana() < this->costoMana) {
        throw string("El personaje no tiene suficiente mana para usar esta arma");
    }

    if (personaje->getEfecto() == Efecto::STUN && personaje->getTurnosRestantesEfecto() > 0) {
        throw string("El personaje no puede usar esta arma");
    }

    // Calculo de damage
    float boost = (float)personaje->getDamageBoost() / 100 + 1;
    int damage = (this->damage * boost) - objetivo->getResistenciaMagica();
    
    if (damage < 0) damage = 0;

    // Aplico damage al objetivo
    objetivo->recibirDamage(damage);

    // Aplicacion de efecto (No necesariamente hace algo, puede simplemente arrancar la quemadura, por ejemplo)
    efecto->aplicar(personaje, objetivo);
    
    // Gasto mana
    personaje->gastarMana(this->costoMana);

    // Propago efecto (Aca si algunos efectos hacen algo, otros no aplica ya que son de un uso)
    objetivo->propagarEfecto();
}