#include "partie.h"

partie::partie(const int hauteur, const int largeur) : d_hauteur{hauteur} , d_largeur{largeur}
{
    srand(time(NULL));

    //Initialisation de la balle
    geom::vector v{5,5};
    geom::point p{d_largeur - d_largeur/2 ,d_hauteur - 120};
    d_balle = {v,p,7};

    geom::point p1;
    geom::point p2;
    geom::point p3{d_largeur - d_largeur/2 - 150 ,d_hauteur - 100};
    geom::point p4{d_largeur - d_largeur/2 + 150,d_hauteur - 80};

    surfaceNormale sn{};
    surfaceTueuse st{};
    surfaceDure sd{};
    surfaceMolle sm{};

    //BRIQUES BLANCHES CASSABLES EN n FOIS
    for(int i = 0; i < 1; ++i){
        int l = rand()%(d_largeur-400);
        int h = rand()%(d_hauteur-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        d_briques.push_back(std::make_unique<briqueCassable>(p1,p2,&sn,2));
    }

    //BRIQUES CYANS INCASSABLES
    for(int i = 0; i < 2; ++i){
        int l = rand()%(d_largeur-400);
        int h = rand()%(d_hauteur-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        d_briques.push_back(std::make_unique<briqueIncassable>(p1,p2,&sd));
    }

    //BRIQUES VERTES CASSABLES EN 1 FOIS
    for(int i = 0; i < 2; ++i){
        int l = rand()%(d_largeur-400);
        int h = rand()%(d_hauteur-400);
        p1 = {l,h};
        p2 = {l+200,h+20};
        d_briques.push_back(std::make_unique<briqueCassable>(p1,p2,&sm,1));
    }

    d_raquette={p3,p4,&sn};

    jouer();
}

void partie::jouer(){
    opengraphsize(d_hauteur,d_largeur);
    setbkcolor(BLACK);
    cleardevice();

    char direction;
    bool end=false;

    while(!d_balle.morte() && end == false){
        d_balle.collision(d_briques, d_raquette, d_hauteur, d_largeur);
        if(d_briques.size()>0 && !d_balle.morte()){
            setcolor(9);
            bar(0,0,5, d_hauteur);
            bar(0,0,d_largeur, 5);
            bar(d_largeur-13,0,d_largeur, d_hauteur);
            d_raquette.affiche();
            if(kbhit()){
                direction = getch();
                if(direction == 'q' || direction == 'd' || direction == 'Q' || direction == 'D')
                    d_raquette.bouge(direction, d_largeur);
            }
            Sleep(10);
        }else{
            end=true;
        }
    }
    closegraph();

}
