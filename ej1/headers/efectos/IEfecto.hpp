#ifndef IEFECTO_HPP
#define IEFECTO_HPP

#include <string>
#include <memory>

using namespace std;

class IPersonaje;

class IEfecto {
    public:
    virtual void aplicar(shared_ptr<IPersonaje> usuario, shared_ptr<IPersonaje> objetivo) = 0;
    virtual string getNombre() const = 0;
    virtual ~IEfecto() = default;
};

#endif