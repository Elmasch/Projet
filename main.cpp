#include <iostream>
#include "terrain.h"
#include "fluxFichier.h"

using namespace std;

int main()
{
    const int hauteur=1000;
    const int largeur=1900;
    terrain t{};
    fluxFichier f;
    string nomFichier="";

    int chx;
    do{
        chx=0;
        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1-Jouer"<<endl;
        cout<<"2-Quitter"<<endl;
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
            cout<<"Vous pourrez deplacer la raquette avec les touches Q et D !"<<endl;
            //Sleep(4000);
            cout<<"Vous etes prets ??"<<endl;
            //Sleep(2000);
            cout<<"Alors ze partiiiiiiiiiiiii"<<endl<<endl<<endl;
            //Sleep(2000);
            if(f.fichierExiste(nomFichier))
                t = f.fluxLecture(nomFichier);
            else
                t = terrain{hauteur,largeur};
            /*if(c != 'o'){
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
                    fine=f.fluxEcriture(nomFichier,t);
                }
            }*/

            cout<<"FIN"<<endl<<endl<<endl;
        }
    }while(chx == 1);
}



