#include <iostream>
#include "graphics.h"
#include "balle.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "brique.h"
#include "briqueIncassable.h"
#include "surfaceNormale.h"
#include <memory>

using namespace std;


void test1(){

    geom::vector v{0,1};
    geom::point p{150,40};

    geom::point p1{120,10};
    geom::point p2{220,20};

    geom::point p3{120,510};
    geom::point p4{220,520};

    vector<unique_ptr<brique>> briques;

    balle b{v,p};
    surfaceNormale s{};

    briques.push_back(make_unique<briqueIncassable>(p1,p2,&s));
    briques.push_back(make_unique<briqueIncassable>(p3,p4,&s));


    while(true)
    {
        for(int i = 0; i < briques.size(); ++i){
            b.collision(*briques[i]);
            briques[i]->affiche();
        }
        Sleep(10);
    }
}
int main()
{
    opengraphsize(800,800);

    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();

    test1();

    getch();
}



