#include "doctest.h"
#include "point.h"
#include "vector.h"

TEST_CASE("{point} Un point est cree correctement"){
    //Teste les constructeurs de la classe point
    //On considere que cela testera les fonctions x() et y() en meme temps
    SUBCASE("Constructeur de point avec parametres"){
        int x=1;
        int y=2;
        geom::point p{x,y};
        REQUIRE_EQ(x,p.x());
        REQUIRE_EQ(y,p.y());
        //Fonctionne si les fonctions x() et y() de la meme classe fonctionnent
    }
    SUBCASE("Constructeur de point sans parametres"){
        geom::point p{};
        REQUIRE_EQ(0,p.x());
        REQUIRE_EQ(0,p.y());
    }
}

TEST_CASE("{point} Un point est deplace correctement"){
    //Teste les fonctions moveTo(x,y), move(x,y) et move(vector) qui utilise la precedente
    int x=1;
    int y=2;
    int dx=5;
    int dy=10;
    geom::point p{x,y};
    SUBCASE("Possibilite de changer les coordonnees d'un point"){
        p.moveTo(dx,dy);
        REQUIRE_EQ(dx,p.x());
        REQUIRE_EQ(dy,p.y());
    }
    SUBCASE("Possibilite d'additionnner des valeurs aux coordonnees d'un point"){
        p.move(dx,dy);
        REQUIRE_EQ(x+dx,p.x());
        REQUIRE_EQ(y+dy,p.y());
    }
    SUBCASE("Possibilite d'additionnner un vecteur aux coordonnees d'un point"){
        geom::vector v{dx,dy};
        p.move(v);
        REQUIRE_EQ(x+dx,p.x());
        REQUIRE_EQ(y+dy,p.y());
    }
    SUBCASE("Possibilite d'additionnner un vecteur aux coordonnees d'un point avec +="){
        geom::vector v{dx,dy};
        p+= v;
        REQUIRE_EQ(x+dx,p.x());
        REQUIRE_EQ(y+dy,p.y());
    }
}

TEST_CASE("{point} Un point est affiche et lu correctement"){
    //Teste les fonctions print(ost) et read(ist) de la classe point
    SUBCASE("Un point est affiche correctement"){
        //Teste la fonction print(ost)
    }
    SUBCASE("Un point est lu correctement"){
        //Teste la fonction read(ist)
    }
}
