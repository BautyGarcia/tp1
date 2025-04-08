#include "../../headers/armas/Hacha.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Hacha::Hacha(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<EfectoSangrado>()) 
{}