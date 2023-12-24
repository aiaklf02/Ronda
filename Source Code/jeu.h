#ifndef JEU_H
#define JEU_H

#include <QObject>
#include "cartesmasquees.h"
#include "table.h"
#include "joueur.h"
#include "carte.h"
#include <QDebug>
#include <QList>
#include <QString>


class jeu : public QObject
{
    Q_OBJECT

private:
    CartesMasquees carteMasquee;
    Table table;
    Joueur j1;
    Joueur j2;

    QList<Carte> tmp;

    bool computer;
    bool fin_jeu;
    bool annimationDestribution;
    int diffeculte=1;// by default easy

//    bool dernier_tour =false;
    bool j2_denier_levement = false;
    bool j1_denier_levement = false;

    Q_PROPERTY(bool computer  NOTIFY computerPlay FINAL)

    Q_PROPERTY(bool fin_jeu  NOTIFY fin_jeuChanged FINAL)

    Q_PROPERTY(bool annimationDestribution NOTIFY annimationDestributionChanged FINAL)

public:
     jeu();

     void re_initialiser_cartes_masque();

     CartesMasquees& getCarteMasquee();

     Q_INVOKABLE Table& getTable();
     Q_INVOKABLE Joueur& getJ1();
     Q_INVOKABLE Joueur& getJ2();

     void re_initialiser_table();
     void initialiser_Les_joueurs();

     Q_INVOKABLE void demarer_nouveau_jeu();

     void distribuer_3_Cartes();

     Q_INVOKABLE void clicksurcartes(int Carte_nombre,QString carte_nom);

     int traiter_main(QList<Carte> t){
         /*here i compare cards in hand , to check for ronda and rondes and return respectivly score */
         int x = 0;

         if(t[0].getNombre() == t[1].getNombre()){
             x += 2;
         }

         if(t[0].getNombre() == t[2].getNombre()){
            x += 2;
         }

         if(t[1].getNombre() == t[2].getNombre()){
            x += 2;
         }
         return x;
     }

     void donner_tours_a_ordinateur(){
         j1.unset_MonTour();
         j2.set_MonTour();
     }

     void donner_tours_a_joeur(){
         j1.set_MonTour();
         j2.unset_MonTour();
     }

     Q_INVOKABLE void ordinateur();

     int ordinateur_decision(){
         // pour chaque carte dans la main
         // il doit savoir la valeur de chque carte dans la table
         // selon la defficulte va returner l'index de la carte que l'ordinateur doit deposer
         int carte_max_potentiel = -1, carte_min_potentiel = 999;

         for (int i = 0;i < j2.nmbrCartesMain();i++){

           int potentiel =  table.A_propos_de_cette_carte( j2.numero_de_Carteparindex(i));

             if(potentiel > carte_max_potentiel ){
                 carte_max_potentiel = i;
             }
             if (potentiel < carte_min_potentiel ){
                 carte_min_potentiel = i;
             }

         }

         if(diffeculte == 3 /* difficile: on prent max potentiel*/){
             return carte_max_potentiel;

         }else if ( diffeculte == 1){
             return carte_min_potentiel;

         }else if (diffeculte == 2){
             /*rendomly return either max or min*/
             bool choose = QRandomGenerator::global()->bounded(2) == 1;
             return choose ? carte_max_potentiel : carte_min_potentiel;
         }

         return 0;// just in case if no ifcase been caugh , i have to return 0 as a back up plan in order for the program to not crash
     }

     Q_INVOKABLE void changerDificulter(int i){
         if(i != diffeculte){
             diffeculte = i;
         }
     }

     bool getComputer() const;
     void setComputer(bool newComputer);

    Q_INVOKABLE int getScoreJoueur(){
         return j1.getScore();
     }
    Q_INVOKABLE int getnombrecarteObtenueJoeur(){
         return j1.nmbrCartObtenue();
    }

    Q_INVOKABLE int getScoreOrdinateur(){
         return j2.getScore();
     }
    Q_INVOKABLE int getnombrecarteObtenueOrdinateur(){
         return j2.nmbrCartObtenue();
    }
 signals:
     void computerPlay();
     void fin_jeuChanged();
     void annimationDestributionChanged();
};

#endif // JEU_H
