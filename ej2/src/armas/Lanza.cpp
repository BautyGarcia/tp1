#include "../../headers/armas/Lanza.hpp"
#include "../../headers/efectos/EfectosCombate.hpp"

Lanza::Lanza(string nombre, int damage, int alcance) : 
    ArmaCombate(nombre, damage, alcance, make_shared<Nada>()) 
{}