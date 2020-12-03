#include "partie.h"

partie::partie(std::vector<std::unique_ptr<brique>> &b, balle &ba, int hauteur, int largeur): d_balle{ba}, d_hauteur{hauteur}, d_largeur{largeur}
{
    for(int i = 0; i < b.size(); ++i){
        d_briques.push_back(std::move(b[i]));
    }
    jouer();
}

void partie::jouer(){
    opengraphsize(d_hauteur,d_largeur);
    setbkcolor(BLACK);
    setcolor(BLUE);
    cleardevice();
    while(!d_balle.morte()){
        d_balle.collision(d_briques, d_hauteur, d_largeur);
        Sleep(10);
    }
    closegraph();
}
