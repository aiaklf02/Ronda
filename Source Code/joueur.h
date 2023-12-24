#ifndef JOUEUR_H
#define JOUEUR_H

#include <carte.h>
#include <QList>
#include <QString>
#include <QDebug>



class Joueur : public QObject
{
    Q_OBJECT

private:
    QString nom;
    QList<Carte> cartesMain;
    QList<Carte> cartesObtenues;
    bool monTour;
    int score;

    Q_PROPERTY(QList<Carte> cartesMain READ getCartesMain NOTIFY cartesMainChanged FINAL)

    Q_PROPERTY(QList<Carte> cartesObtenues READ getCartesObtenues NOTIFY cartesObtenuesChanged FINAL)

    Q_PROPERTY(QString nom READ getNom WRITE setNom NOTIFY nomChanged FINAL)

public:
    Joueur();

    void initialiser_cartes_a_main();

    void retirerCartes(QList<Carte> troisCartes);

    void ObtenirCartes(QList<Carte>  listdeCarteObtenue);

    Carte deposer(int n, QString t);

    QList<Carte> getCartesMain() const;
    void setCartesMain(QList<Carte> newCartesMain);


    QList<Carte> getCartesObtenues() const;
    void setCartesObtenues(QList<Carte> newCartesObtenues);

    QString getNom() const;
    void setNom(const QString &newNom);

    Q_INVOKABLE bool what_is_MonTour() const;
    void set_MonTour();
    void unset_MonTour();

    Q_INVOKABLE int numero_de_Carteparindex(int i){
        int x = cartesMain[i].getNombre();
        return x;
    }

    Q_INVOKABLE QString nom_de_CartCarteparindex(int i){
         QString x = cartesMain[i].getType();
        return x;
    }

    Q_INVOKABLE QString imgCarteparindex(int i){
        QString x = cartesMain[i].ImageSource();
        return x;
    }


    Q_INVOKABLE int nmbrCartesMain()const {
        return cartesMain.size();
    }

    int trouve_index_deCarte(int numero, QString type){

        for (int var = 0; var < cartesMain.size(); ++var) {
            if ( cartesMain[var].getNombre() == numero  && cartesMain[var].getType() == type){
                return var;
            }
        }

        return -1;
    }



    Q_INVOKABLE int getScore() const;
    void addScore(int newScore);

    int nmbrCartObtenue()const{
        return cartesObtenues.size();
    }

signals:
    void cartesMainChanged();
    void cartesObtenuesChanged();
    void nomChanged();
};


#endif // JOUEUR_H
