#include "doctest.h"
#include "vector.h"
#include "point.h"

TEST_CASE("{vector} Un vecteur est cree correctement"){
    //Teste les constructeurs de la classe vector
    //On considere que cela testera les fonctions x() et y() en meme temps
    SUBCASE("Constructeur de vecteur avec parametres x et y"){
        int x=1;
        int y=2;
        geom::vector v{x,y};
        REQUIRE_EQ(x,v.x());
        REQUIRE_EQ(y,v.y());
        //Fonctionne si les fonctions x() et y() de la meme classe fonctionnent
    }
    SUBCASE("Constructeur de vecteur avec deux points en parametres"){
        int x1=1;
        int y1=2;
        int x2=3;
        int y2=4;
        geom::point p1{x1,y1};
        geom::point p2{x2,y2};
        geom::vector v{p1,p2};
        REQUIRE_EQ(p2.x()-p1.x(),v.x());
        REQUIRE_EQ(p2.y()-p1.y(),v.y());
        //Fonctionne si les fonctions x() et y() de la meme classe fonctionnent
    }
    SUBCASE("Constructeur de vecteur sans parametres"){
        geom::vector v{};
        REQUIRE_EQ(0,v.x());
        REQUIRE_EQ(0,v.y());
    }
}

TEST_CASE("{vector} Un point est change correctement"){
    //Teste la fonction change(x,y)
    int x=1;
    int y=2;
    int dx=5;
    int dy=10;
    geom::vector v{x,y};
    v.change(dx,dy);
    REQUIRE_EQ(dx,v.x());
    REQUIRE_EQ(dy,v.y());

}

TEST_CASE("{vector} Un vecteur est affiche et lu correctement"){
    //Teste les fonctions print(ost) et read(ist) de la classe vector
    SUBCASE("Un vecteur est affiche correctement"){
        //Teste la fonction print(ost)
    }
    SUBCASE("Un vecteur est lu correctement"){
        //Teste la fonction read(ist)
    }
}
