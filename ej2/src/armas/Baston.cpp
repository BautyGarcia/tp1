#include "../../headers/armas/Baston.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

Baston::Baston(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<Stun>())
{}