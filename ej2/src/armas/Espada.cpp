#include "../../headers/armas/Espada.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Espada::Espada(string nombre, int damage, int costoMana, int alcance) : 
    ArmaCombate(nombre, damage, costoMana, alcance, make_shared<EfectoSangrado>()) 
{}