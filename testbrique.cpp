#include "briqueCassable.h"
#include "briqueIncassable.h"
#include "raquette.h"
#include "surfaceNormale.h"
#include "doctest.h"
#include "balle.h"

TEST_CASE("{brique} La brique est cree correctement"){
    //Teste le constructeur de la brique incassable qui a les memes parametres que celui de la classe brique
    //Le constructeur de la raquette a aussi les memes parametres que celui de la classe brique
    //Teste si les fonctions Getters de la classe brique fonctionnent
    //Par defaut, la brique aura une surface normale
    geom::point p1{1,2};
    geom::point p2{2,1};
    surfaceNormale s{};
    briqueIncassable b{p1,p2,&s};
    SUBCASE("Le point basGauche est cree correctement"){
        REQUIRE_EQ(p1.x(), b.getBasGauche().x());
        REQUIRE_EQ(p1.y(), b.getBasGauche().y());
    }
    SUBCASE("Le point hautDroite est cree correctement"){
        REQUIRE_EQ(p2.x(), b.getHautDroite().x());
        REQUIRE_EQ(p2.y(), b.getHautDroite().y());
    }
    SUBCASE("La surface est cree correctement"){
        REQUIRE_EQ(s,b.getSurface());
    }
    //Test du destructeur possible/necessaire ?...
}

TEST_CASE("{briqueCassable} La brique incassable est cree correctement"){
    //Teste a part le constructeur de la brique cassable qui a un parametre en plus que celui de la classe brique
    //Teste si la fonction getNombre() de la classe briqueCassable fonctionne
    //Par defaut, la brique aura une surface normale
    geom::point p1{1,2};
    geom::point p2{2,1};
    surfaceNormale s{};
    int n = 2;
    briqueCassable b{p1,p2,&s,n};
    SUBCASE("Le nombre de touches necessaires est cree correctement"){
        REQUIRE_EQ(b.getNombre(),n);
    }
}

TEST_CASE("{brique} Le deplacement de la brique fonctionne correctement"){
    //Teste la fonction deplace(direction,hauteur,largeur)
    //Est utilise pour deplacer la raquette (qui est une brique) vers la droite ou la gauche
    //Par defaut, la brique aura une surface normale
    int largeur=1000;
    geom::point p1{largeur-largeur/2-140 ,largeur-100};
    geom::point p2{largeur-largeur/2+140 ,largeur-80};
    surfaceNormale s{};
    raquette r{p1,p2,&s};
    SUBCASE("On peut deplacer la brique(raquette) vers la gauche avec la touche <g>"){
        r.deplace('q',largeur);
        REQUIRE_EQ(r.getBasGauche().x(),p1.x()-30);
        REQUIRE_EQ(r.getHautDroite().x(),p2.x()-30);
    }
    SUBCASE("On peut deplacer la brique(raquette) vers la gauche avec la touche <Q>"){
        r.deplace('Q',largeur);
        REQUIRE_EQ(r.getBasGauche().x(),p1.x()-30);
        REQUIRE_EQ(r.getHautDroite().x(),p2.x()-30);
    }
    SUBCASE("On peut deplacer la brique(raquette) vers la droite avec la touche <d>"){
        r.deplace('d',largeur);
        REQUIRE_EQ(r.getBasGauche().x(),p1.x()+30);
        REQUIRE_EQ(r.getHautDroite().x(),p2.x()+30);
    }
    SUBCASE("On peut deplacer la brique(raquette) vers la droite avec la touche <D>"){
        r.deplace('D',largeur);
        REQUIRE_EQ(r.getBasGauche().x(),p1.x()+30);
        REQUIRE_EQ(r.getHautDroite().x(),p2.x()+30);
    }
    SUBCASE("La brique(raquette) ne sortira pas de la fenetre lors de ses deplacements"){
        for(int i=0;i<20;i++)
            r.deplace('q',largeur);
        REQUIRE_EQ(r.getBasGauche().x(),0);
        for(int i=0;i<30;i++)
            r.deplace('d',largeur);
        REQUIRE_EQ(r.getHautDroite().x(),1000);
    }
}

TEST_CASE("{brique} Les briques casseront sauf celles qui sont incassables"){
    //Teste la fonction casse() de la classe brique
    //Renvoie false instantanement pour les briques incassables et la raquette
    //Par defaut, la brique aura une surface normale
    geom::point pbg{2,4};
    geom::point phd{6,5};
    surfaceNormale s{};
    SUBCASE("La raquette et les briques incassables ne casseront jamais"){
        briqueIncassable b{pbg,phg,&s};
        raquette r{p1,p2,&s};
        REQUIRE_FALSE(b.casse());
        REQUIRE_FALSE(r.casse());
    }
    SUBCASE("Les briques cassables cassent au bon nombre de touches"){
        int nbtouche=2;
        briqueCassable b{pbg,phg,&s,nbtouche};
        geom::vector v{0,1};
        balle bl{p1,v,1};
        for(int i=1;i<nbtouche;i++)
        {
            while(bl.getPosition().y()>p.y())
            {
                 bl.avance(hauteur,largeur);
            }
            REQUIRE_FALSE(b.casse());
            bl.setPosition(p);
            bl.setVitesse(v);
        }
        REQUIRE(b.casse());
    }
}

//On ne pourra pas tester les fonctions affiche() et efface() car ce sont des fonctions graphiques
