#include "cartesmasquees.h"
#include "QSet"

// constructeur de la class cartes masquees genere 40 cartes
CartesMasquees::CartesMasquees(){
    genereranouveauLesCartes();

}

void CartesMasquees::genereranouveauLesCartes(){

    Cmasquees.clear();

    QString t;

    QString typesNom = "CEBM";

    for (int x = 0; x < 4; ++x) {

         t = typesNom.mid(x,1);

        for (int var = 1; var <= 7; ++var) {

            Carte nc(var,t);

            Cmasquees.append(nc);
        }

        for (int var = 10; var <= 12; ++var) {
            Carte nc2(var,t);
            Cmasquees.append(nc2);

        }

    }
    // pour avoir des cartes master melangee del debut du jeu
    melanger();

}

QList<Carte> CartesMasquees::getCartes(int n){
    tmp.clear();

    if(n == 4){

       int var=0;
       for (const Carte c: Cmasquees){

//            auto it = std::find(tmp.begin(), tmp.end(), c);

            auto it = std::find_if(tmp.begin(), tmp.end(), [c](const Carte& tmpCard) {
                return tmpCard.getNombre() == c.getNombre();
            });

            if (it == tmp.end()) {
                tmp.append(c);
                Cmasquees.removeOne(c);
                var++;
                if(var == 4){
                    return tmp;
                    break;
                }

            }
       }

    }

    else{

       for (int i = 0; i < n; ++i) {
            Carte tmpCarte(Cmasquees.at(0));
            tmp.append(tmpCarte);
            Cmasquees.removeAt(0);
        }
    }

    return tmp;


}

int CartesMasquees::CmasqueesTaille(){
    return Cmasquees.size();
}
