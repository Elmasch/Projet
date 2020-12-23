#include "doctest.h"
#include "partie.h"
#include "surfaceNormale.h"
#include "briqueIncassable.h"
#include "raquette.h"

TEST_CASE("{partie} La partie est cree correctement"){
    //Teste le constructeur avec parametres de la partie
    //Par defau, les briques seront incassables
    //Par defaut, la surface des briques sera normale
    geom::point p1{2,1};
    geom::point p2{1,2};
    surfaceNormale s{};
    std::vector<std::unique_ptr<brique>> b;
    b.push_back(std::make_unique<briqueIncassable>(p1,p2,&s));
    b.push_back(std::make_unique<briqueIncassable>(p2,p1,&s));

    geom::vector v{2,1};
    balle ba{v,p1,4};

    int hauteur=1000;
    int largeur=1000;

    raquette r{p1,p2,&s};

    partie(hauteur,largeur);
    //Necessite des getters pour pouvoir verifier si les valuers sont bien initialises
}

//La fonction jouer() comporte des elements graphiques qu'on ne pourra pas tester
