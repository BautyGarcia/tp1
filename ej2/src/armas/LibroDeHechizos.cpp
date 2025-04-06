#include "../../headers/armas/LibroDeHechizos.hpp"
#include "../../headers/efectos/EfectosMagicos.hpp"

LibroDeHechizos::LibroDeHechizos(string nombre, int damage, int costoMana, int alcance) : 
    ArmaMagica(nombre, damage, costoMana, alcance, make_shared<BoostMagico>())
{}