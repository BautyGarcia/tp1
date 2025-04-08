#include "../../headers/armas/Garrote.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Garrote::Garrote(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<EmptyEfecto>()) 
{}