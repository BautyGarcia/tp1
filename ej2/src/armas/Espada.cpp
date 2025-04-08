#include "../../headers/armas/Espada.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Espada::Espada(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<Sangrado>()) 
{}