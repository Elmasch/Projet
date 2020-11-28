#include <iostream>
#include "graphics.h"
#include "balle.h"
#include "point.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "brique.h"
#include "normale.h"
#include "dure.h"
#include "tueuse.h"

using namespace std;


void test1(){
    tueuse n{200,200};
    balle b {10,100,100};
    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    n.affiche();
    for(int i=0;i<40;i++)
    {
        b.efface();
        n.collision(b);
        std::cout<<b.getY()<<std::endl;
        b.avance();
        b.affiche();
        Sleep(20);
    }
    getch();
    cleardevice();
}
int main()
{
    test1();
}
