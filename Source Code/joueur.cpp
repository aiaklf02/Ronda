#include "joueur.h"


int Joueur::getScore() const
{
    return score;
}

void Joueur::addScore(int newScore)
{
    score += newScore;
}

Joueur::Joueur(){
}

QList<Carte> Joueur::getCartesMain() const
{
    return cartesMain;
}

QList<Carte> Joueur::getCartesObtenues() const
{
   return cartesObtenues;
}


QString Joueur::getNom() const
{
   return nom;
}

void Joueur::setNom(const QString &newNom)
{
   if (nom == newNom)
       return;
   nom = newNom;
   emit nomChanged();
}

bool Joueur::what_is_MonTour() const
{
   return monTour;
}

void Joueur::set_MonTour()
{
   monTour = true;
}

void Joueur::unset_MonTour()
{
   monTour = false;
}


void Joueur::initialiser_cartes_a_main(){
   cartesMain.clear();
   emit cartesMainChanged();

   cartesObtenues.clear();
   emit cartesObtenuesChanged();

   score=0;
}

void Joueur::retirerCartes(QList<Carte> troisCartes){
   cartesMain.append(troisCartes);
//   emit cartesObtenuesChanged();
   emit cartesMainChanged();

}

void Joueur::ObtenirCartes(QList<Carte> listdeCarteObtenue){
    /* hna checki lista li 3tatek table wach khawya  , ila kant khawya , rak ma 3andek matzid f yedek*/
    if (listdeCarteObtenue.size() != 0){
        cartesObtenues.append(listdeCarteObtenue);
       // emit card obtenue changed
       emit cartesObtenuesChanged();
    }
}

Carte Joueur::deposer(int n, QString t){

    // search card index and remove it from hand
    for (int i = 0 ; i< cartesMain.size(); ++i){

        QString Nomcarte = cartesMain[i].getType();
        int numeroCarte = cartesMain[i].getNombre();

        if( t == Nomcarte && n == numeroCarte ){
            Carte copy(cartesMain[i]);
            cartesMain.removeAt(i);
            emit cartesMainChanged();
            return copy;
        }
    }
    throw "la carte que tu a clicker , je l es pas trouver dans la list de vos carte en main";
}
