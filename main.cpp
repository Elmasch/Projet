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
#include "surfaceNormale.h"
#include <memory>
#include "raquette.h"

using namespace std;


void test1(){

    geom::vector v{2,5};
    geom::point p{150,40};

    geom::point p1{200,150};
    geom::point p2{400,160};

    geom::point p3{10,510};
    geom::point p4{780,520};

    vector<unique_ptr<brique>> briques;

    balle b{v,p};
    surfaceNormale s{};

    briques.push_back(make_unique<briqueCassable>(p1,p2,&s,2));
    briques.push_back(make_unique<raquette>(p3,p4,&s));

    while(true)
    {
        b.collision(briques);
        Sleep(5);
    }
}
int main()
{
    opengraphsize(800,800);

    setbkcolor(BLACK);
    setcolor(BLUE);
    cleardevice();

    test1();

    getch();
}



