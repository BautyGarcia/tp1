#ifndef IEFECTO_HPP
#define IEFECTO_HPP

#include <string>
#include <memory>

using namespace std;

class IPersonaje;

class IEfecto {
    public:
    virtual void aplicar(IPersonaje* usuario, IPersonaje* objetivo) = 0;
    virtual string getNombre() const = 0;
    virtual ~IEfecto() = default;
};

#endif