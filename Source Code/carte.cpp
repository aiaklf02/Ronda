#include "carte.h"

int Carte::getNombre() const
{
    return nombre;
}

QString Carte::getType() const
{
    return type;
}

Carte::Carte(const int n,const QString t): nombre(n),type(t){
}

Carte::Carte(const Carte &c){
    this->nombre = c.nombre;
    this->type = c.type;
}

Carte & Carte::operator =(const Carte &other){
    this->nombre = other.nombre;
    this->type = other.type;
    return *this;
}
