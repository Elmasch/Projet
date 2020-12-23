#include <iostream>
#include "partie.h"

using namespace std;

int main()
{
    const int hauteur=1000;
    const int largeur=1000;

    int chx;
    do{
        chx=0;
        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1-Jouer"<<endl;
        cout<<"2-Quitter"<<endl;
        cin>>chx;
        if(chx == 1)
            cout<<"Vous pourrez deplacer la raquette avec les touches Q et D !"<<endl;
            //Sleep(4000);
            cout<<"Vous etes prets ??"<<endl;
            //Sleep(2000);
            cout<<"Alors ze partiiiiiiiiiiiii"<<endl;
            //Sleep(2000);
            partie(hauteur,largeur);
            cout<<"FIN"<<endl<<endl<<endl;
    }while(chx == 1);
}



