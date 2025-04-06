#include "../../headers/armas/Amuleto.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

Amuleto::Amuleto(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<CurarVida>())
{}