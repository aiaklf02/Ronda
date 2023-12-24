#ifndef TABLE_H
#define TABLE_H

#include "carte.h"
#include <iostream>
#include <QList>
#include <QString>
#include <QDebug>


class Table : public QObject
{
    Q_OBJECT

private:
    QList<Carte> Cartestable;
    QList<Carte> tmpList;

    Q_PROPERTY(QList<Carte> Cartestable NOTIFY cartestableChanged FINAL)

public:

    Table(){}

    void sortTbale();

    /* here i need a function that takes a card from player and add it to table , then it checks if i have cards to collect , then i should */
    QList<Carte> traiterCarte(Carte cartePoseParJoeur);

    void prendreCartes_depuis_cartesMasque(QList<Carte> & cartes){
        Cartestable.append(cartes);
        sortTbale();
        emit cartestableChanged();
    }


    void initialiserTable();
    void viderTable();

    QList<Carte> CartesdeTable();

    Q_INVOKABLE QString imagedeCarteenTableParIndex(int i){
        QString x = Cartestable[i].ImageSource() ;
        return x;
    }

    Q_INVOKABLE int table_taille() const{
        return Cartestable.size();
    }


    QList<Carte> getCartestable() ;
//    void setCartestable(const QList<Carte> &newCartestable);

    int A_propos_de_cette_carte(int x){
        // this function should return how many cards i can obtain if i chose to put card number x
        // it will be used inorder for computer use it accordingly to defficulty

        // tableau contient les numero des cartes de jeu
        QList<int> tableauNum= { 1,2,3,4,5,6,7,10,11,12 };

        int nbrCartesLevees=0;
        int Ndepart=-1;

        // on doit savoir l index dans le tableau precedant , le numero de la carte deposee par joeur
        int index = tableauNum.indexOf(x);

        // we loop to find first elemet to start poping from
        for(int v =0 ; v < Cartestable.size() ; ++v){
            if(Cartestable[v].getNombre() ==  tableauNum[index] ){
                Ndepart = v;
                break;
            }
        }
        // here we loop to find how many cards to pop after the starting point
        if(Ndepart != -1){
            for (int var = 0; var < Cartestable.size() ; ++var) {
                Carte tm(Cartestable[var]);
                int n= tableauNum[index];

                if( tm.getNombre() == n ){
                    // compteur var estre utilise comme index initiale de list a returner
                    nbrCartesLevees++;
                    index++;
                }
            }
        }

        return nbrCartesLevees;
    }

signals:
    void cartestableChanged();
};

#endif // TABLE_H
