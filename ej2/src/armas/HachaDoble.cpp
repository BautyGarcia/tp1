#include "../../headers/armas/HachaDoble.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

HachaDoble::HachaDoble(string nombre, int damage, int costoMana, int alcance) : 
    ArmaCombate(nombre, damage, costoMana, alcance, make_shared<EfectoSangrado>()) 
{}