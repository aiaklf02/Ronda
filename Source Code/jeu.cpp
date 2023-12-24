#include "jeu.h"


CartesMasquees & jeu::getCarteMasquee()
{
    return carteMasquee;
}

Table & jeu::getTable()
{
    return table;
}

Joueur & jeu::getJ1()
{
    return j1;
}

Joueur & jeu::getJ2()
{
    return j2;
}



jeu::jeu()
{

}

void jeu::re_initialiser_cartes_masque(){
    // re start new game
    carteMasquee.genereranouveauLesCartes();
}

void jeu::re_initialiser_table(){
    table.initialiserTable();
}

void jeu::initialiser_Les_joueurs(){
    j1.initialiser_cartes_a_main();
    j2.initialiser_cartes_a_main();
}

void jeu::demarer_nouveau_jeu(){
    re_initialiser_cartes_masque();
    re_initialiser_table();
    initialiser_Les_joueurs();
    // ici je fait signal a qml pour generer le view , puis j attend le click d utilisateur
    tmp.clear();

    emit annimationDestributionChanged();

    // destribuer les cartes au joueurs et a table
    tmp = carteMasquee.getCartes(3);

    j1.retirerCartes(tmp);
    j1.set_MonTour();
    tmp.clear();

    tmp = carteMasquee.getCartes(3);

    j2.retirerCartes(tmp);
    j2.unset_MonTour();
    tmp.clear();

    tmp = carteMasquee.getCartes(4);
    table.prendreCartes_depuis_cartesMasque(tmp); /*prendre list de carte de cartes masquee*/

    tmp.clear();

    return;
}

void jeu::distribuer_3_Cartes(){

    if(carteMasquee.CmasqueesTaille() != 0){
        emit annimationDestributionChanged();

    tmp.clear();
    tmp = carteMasquee.getCartes(3);/****/
    j1.retirerCartes(tmp);
    j1.set_MonTour();

    /* ici je check si il a ronda ou ronda de rondes */
    int xpj1 = traiter_main(tmp);
     j1.addScore(xpj1);

    tmp.clear();
    tmp = carteMasquee.getCartes(3);/****/
    j2.retirerCartes(tmp);
    j2.unset_MonTour();

    /* ici je check si il a ronda ou ronda de rondes */
   int xpj2 =traiter_main(tmp);
     j2.addScore(xpj2);
    }

    else if (carteMasquee.CmasqueesTaille() == 0){


        if ( j1_denier_levement ){
        j1.ObtenirCartes(table.getCartestable());
        table.viderTable();
    }
        else if(j2_denier_levement){
        j2.ObtenirCartes(table.getCartestable());
        table.viderTable();
    }

    // emit signal to finish game
    emit fin_jeuChanged();
        return;
    }

}

// function s'execute lorsque le joeur click pour poser une carte
void jeu::clicksurcartes(int carte_nombre,QString carte_nom){
    if (j1.what_is_MonTour()){

// pass it to table , and let it return qlist , either filled or empty , doesnt matter size is checked to tell if he is the last player lifted a card , what matters is to wait for the return to append to carte obtenue
    Carte tmp(j1.deposer(carte_nombre,carte_nom));

    QList t =  table.traiterCarte(tmp);

    if (t.size() != 0){
            /*im the last player lifted from table*/
            j1_denier_levement = true;
            j2_denier_levement = false;
        }

    j1.ObtenirCartes(t);

    // savoir combien de cartes dans la table , si missa je gagne 5 XP
    if (table.table_taille() == 0){
            j1.addScore(5);
    }

// switch turns
    donner_tours_a_ordinateur();

//  it should call computer to play after qml sleep timer
    emit computerPlay();
    }else {
        return;
    }
}


// this funcion get executed from qml , after timer finishes
void jeu::ordinateur(){

    if( j2.what_is_MonTour() ){

    int index_de_carte_a_poser = ordinateur_decision();// index_de_carte_a_poser based on decision that is taken based on defficulty

    int carte_nombre = j2.numero_de_Carteparindex(index_de_carte_a_poser);
    QString carte_nom = j2.nom_de_CartCarteparindex(index_de_carte_a_poser);

    QList t = table.traiterCarte( j2.deposer(carte_nombre,carte_nom) );

    if (t.size() != 0){
        /*im the last player lifted from table*/
    j1_denier_levement = false;
    j2_denier_levement = true;
    }

    // j2 leve les cartes obtenues
    j2.ObtenirCartes(t);

    // savoir combien de cartes dans la table , si missa je gagne 5 XP
    if (table.table_taille() == 0){
    j2.addScore(5);
    }

    donner_tours_a_joeur();

    // if j1.hand size and j2 . hand size is 0 , mean they have to lift 3 cards , and return;
    if(j2.nmbrCartesMain() == 0 && j1.nmbrCartesMain() == 0){
        distribuer_3_Cartes();

    return;
    }

    // if j1 and j2 still have cards , return; to wait for player click again
    return;
}
    else {
        return;
    }
}
