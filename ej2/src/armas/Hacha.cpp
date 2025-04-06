#include "../../headers/armas/Hacha.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Hacha::Hacha(string nombre, int damage, int costoMana, int alcance) : 
    ArmaCombate(nombre, damage, costoMana, alcance, make_shared<EfectoSangrado>()) 
{}