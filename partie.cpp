#include "partie.h"

partie::partie(std::vector<std::unique_ptr<brique>> &b, balle &ba): d_balle{ba}
{
    for(int i = 0; i < b.size(); ++i){
        d_briques.push_back(std::move(b[i]));
    }
    jouer();
}

void partie::jouer(){
    opengraphsize(800,800);
    setbkcolor(BLACK);
    setcolor(BLUE);
    cleardevice();
    while(!d_balle.morte()){
        d_balle.collision(d_briques);
        Sleep(10);
    }
    closegraph();
}
