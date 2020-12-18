#include <iostream>
#include "graphics.h"
#include "balle.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "brique.h"
#include "briqueCassable.h"
#include "briqueIncassable.h"
#include "surfaceNormale.h"
#include "surfaceMolle.h"
#include "surfaceDure.h"
#include "surfaceTueuse.h"
#include <memory>
#include "raquette.h"
#include "partie.h"
#include <time.h>

using namespace std;

const int HAUTEUR = 1000;
const int LARGEUR = 1000;

void test1(){
    srand(time(NULL));
    geom::vector v{5,5};
    geom::point p{LARGEUR - LARGEUR/2 ,HAUTEUR - 120};

    geom::point p1;
    geom::point p2;

    geom::point p3{LARGEUR - LARGEUR/2 - 150 ,HAUTEUR - 100};
    geom::point p4{LARGEUR - LARGEUR/2 + 150,HAUTEUR - 80};

    vector<unique_ptr<brique>> briques;

    balle b{v,p,7};
    surfaceNormale sn{};
    surfaceTueuse st{};
    surfaceDure sd{};
    surfaceMolle sm{};

    for(int i = 0; i < 1; ++i){
        int l = rand()%(LARGEUR-400);
        int h = rand()%(HAUTEUR-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        briques.push_back(make_unique<briqueCassable>(p1,p2,&sn,3));
    }

    for(int i = 0; i < 2; ++i){
        int l = rand()%(LARGEUR-400);
        int h = rand()%(HAUTEUR-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        briques.push_back(make_unique<briqueIncassable>(p1,p2,&sd));
    }

    for(int i = 0; i < 2; ++i){
        int l = rand()%(LARGEUR-400);
        int h = rand()%(HAUTEUR-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        briques.push_back(make_unique<briqueCassable>(p1,p2,&sm, 1));
    }

    raquette r(p3,p4,&sn);

    partie jeu{briques, b, HAUTEUR, LARGEUR, r};

    jeu.jouer();

}

int main()
{
    int chx;
    do{
        chx=0;
        cout<<"Que voulez-vous faire ?"<<endl;
        cout<<"1-Jouer"<<endl;
        cout<<"2-Quitter"<<endl;
        cin>>chx;
        if(chx == 1)
            test1();
    }while(chx == 1);

}



