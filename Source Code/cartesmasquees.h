#ifndef CARTESMASQUEES_H
#define CARTESMASQUEES_H

#include <QObject>
#include <QList>
#include <QString>
#include <iostream>
#include <QRandomGenerator>
#include "carte.h"

class CartesMasquees : public QObject
{
    Q_OBJECT


private:
    QList<Carte> Cmasquees;
    QList<Carte> tmp;

public:
    CartesMasquees();

    void genereranouveauLesCartes();

    QList<Carte> getCartes(int n);

    int CmasqueesTaille();

    void melanger(){

        int size = Cmasquees.size();

        for (int i = size - 1; i > 0; --i) {
            int randomIndex = QRandomGenerator::global()->bounded(i + 1);
            Cmasquees.swapItemsAt(i, randomIndex);
        }

    }

};

#endif // CARTESMASQUEES_H
