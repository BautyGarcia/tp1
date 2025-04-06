#include "../../headers/armas/Pocion.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

Pocion::Pocion(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<CurarVida>())
{}