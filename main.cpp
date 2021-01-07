#include <iostream>
#include "terrain.h"
#include "fluxFichier.h"

using namespace std;

int main()
{
    const int hauteur=800;
    const int largeur=800;
    terrain* t;
    fluxFichier f;
    string nomFichier="";

    int chx;
    do{
        chx=0;
        cout<<"Que voulez-vous faire ? (1-Jouer)(2-Quitter) ";
        cin>>chx;
        if(chx == 1){
            char c;
            do{
                cout<<"Voulez-vous charger un terrain sauvegarde ? (o/n) : ";
                cin>>c;
            }while(c != 'o' && c != 'n');
            if(c == 'o'){
                do{
                    cout<<"Nom du fichier a charger (sans l'extension) : ";
                    cin>>nomFichier;
                }while(!f.fichierExiste(nomFichier));
            }

            if(f.fichierExiste(nomFichier)){
                f.fluxLecture(nomFichier, t);
                cout<< t->getBalle().getPosition().x() << " " << t->getBalle().getPosition().y()<<endl;
            }
            else{
                t = new terrain{hauteur, largeur};
                t->initialisation();
            }
            cout<<"Vous pourrez deplacer la raquette avec les touches Q et D !"<<endl;
            //Sleep(4000);
            cout<<"Vous etes prets ??"<<endl;
            //Sleep(2000);
            cout<<"Alors c'est parti !"<<endl<<endl<<endl;
            //Sleep(2000);
            if(t){
                t->jouer();
            }
                do{
                    cout<<"Voulez-vous sauvegarder le terrain de la partie precedente ? (o/n) : ";
                    cin>>c;
                }while(c != 'o' && c != 'n');
                bool fine=false;
                while(c == 'o' && !fine){
                    string nomFichier="save";
                    cout<<"Entrez le nom de fichier souhaite : ";
                    cin>>nomFichier;
                    fluxFichier f;
                    fine=f.fluxEcriture(nomFichier,*t);
                }

            cout<<"FIN"<<endl<<endl<<endl;
        }
    }while(chx == 1);
}



