#include "../../headers/armas/Lanza.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Lanza::Lanza(string nombre, int damage, int costoMana, int alcance) : 
    ArmaCombate(nombre, damage, costoMana, alcance, make_shared<EmptyEfecto>()) 
{}