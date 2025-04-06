#include "../../headers/armas/Garrote.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Garrote::Garrote(string nombre, int damage, int costoMana, int alcance) : 
    ArmaCombate(nombre, damage, costoMana, alcance, make_shared<EmptyEfecto>()) 
{}