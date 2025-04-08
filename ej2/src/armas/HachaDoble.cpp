#include "../../headers/armas/HachaDoble.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

HachaDoble::HachaDoble(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<EfectoSangrado>()) 
{}