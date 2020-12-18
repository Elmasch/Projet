#include <iostream>
#include "partie.h"

partie::partie(std::vector<std::unique_ptr<brique>> &b, balle &ba, int hauteur, int largeur, raquette r): d_balle{ba}, d_hauteur{hauteur}, d_largeur{largeur}, d_raquette{r}
{
    for(int i = 0; i < b.size(); ++i)
        d_briques.push_back(std::move(b[i]));
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
                    d_raquette.bouge(direction);
            }
            Sleep(10);
        }else{
            std::cout<<"FIN"<<std::endl<<std::endl<<std::endl;
            end=true;
        }

    }
    closegraph();
}
