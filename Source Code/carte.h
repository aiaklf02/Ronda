#ifndef CARTE_H
#define CARTE_H

#include <QObject>
#include <QList>
#include <QString>


class Carte : public QObject
{
    Q_OBJECT



private:
    int nombre;
    QString type;


public:

    Carte(int n,QString t);

    Carte(const Carte & c);

    bool operator == (const Carte & other)const {
        if( this->nombre == other.nombre  && this->type == other.type ){
            return true;
        }
        else if( this->nombre != other.nombre  || this->type != other.type ){
            return false;
        }
    }

    Carte & operator = (const Carte & other);

    int getNombre() const;

    QString getType() const;

    /* ImageSource()
images/1C.png 		// coupe
images/1E.png		// epee
images/1B.png		// Batton
images/1M.png		// monnaie
    */
    QString ImageSource(){
        return "images/" + QString::number(nombre) + type + ".png";
    }

};

#endif // CARTE_H
