#include "Table.h"
#include "Carte.h"


QList<Carte> Table::CartesdeTable()
{
    return Cartestable;
}


QList<Carte> Table::getCartestable()
{
    return Cartestable;
}

void Table::sortTbale(){
    // trion la table selon les nombre de cartes , pour que les joeurs ne pas etre concentree sur l ordre des cartes a la table
    std::sort(Cartestable.begin(), Cartestable.end(), [](Carte a, Carte b) {
        return a.getNombre() < b.getNombre();
    });

}

QList<Carte> Table::traiterCarte(Carte cartePoseParJoeur){
    /* 1- chercher ila kayna chi carta mathez */
    int numeroPoserParjoureur = cartePoseParJoeur.getNombre();

    QList<Carte> t;

    int nbrCartesLevees=0;
    int Ndepart=-1;

    // tableau contient les numero des cartes de jeu
    QList<int> tableauNum= { 1,2,3,4,5,6,7,10,11,12 };

    // on doit savoir l index dans le tableau precedant , le numero de la carte deposee par joeur
    int index = tableauNum.indexOf(numeroPoserParjoureur);

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
// here we start poping
/* ila t size == 0 */
    if(Ndepart == -1 ){

    Cartestable.append(cartePoseParJoeur);
    sortTbale();
    emit cartestableChanged();

    return t;// t here is empty
    /**/
    }else if(Ndepart != -1){



    // here we have cards to obtain.
    for(int n = 0 ; n < nbrCartesLevees;n++ ){
            t.append( Cartestable[Ndepart] );
            Cartestable.removeAt(Ndepart);
    }
    t.append(cartePoseParJoeur);

    emit cartestableChanged();
    return t;
    }

    emit cartestableChanged();
    return t;
}

void Table::initialiserTable(){
    // vider la table
    viderTable();

}
void Table::viderTable(){
    // vider tout les list de la class
    Cartestable.clear();
    tmpList.clear();
    emit cartestableChanged();

}
