#include "balle.h"
#include "doctest.h"
#include "brique.h"
#include "briqueCassable.h"
#include "briqueIncassable.h"
#include "raquette.h"
#include "surfaceNormale.h"

TEST_CASE("{balle} La balle avec parametres est cree correctement"){
    //Teste le constructeur avec parametres de la balle
    //Teste si les fonctions Getters fonctionnent
    //Teste si la fonction morte() fonctionne
    geom::vector v{2,1};
    geom::point p{2,1};
    balle b{v,p,4};
    SUBCASE("Le vecteur vitesse est cree correctement"){
        REQUIRE_EQ(v.x(), b.getVitesse().x());
        REQUIRE_EQ(v.y(), b.getVitesse().y());
    }
    SUBCASE("Le point position est cree correctement"){
        REQUIRE_EQ(p.x(), b.getPosition().x());
        REQUIRE_EQ(p.y(), b.getPosition().y());
    }
    SUBCASE("La balle est intialisee non morte"){
        REQUIRE_FALSE(b.morte());
    }
    //Tests du destructeur et du constructeur sans parametres possibles/necessaires ?...
    //Actuellement on ne peut pas tester la valeur d_rayon car elle n'a pas de Getter ni de Setter
}

TEST_CASE("{balle} Modification des valeurs de la balle"){
    //Teste si les fonctions Setters fonctionnent
    //Important de tester d'abord si les fonctions Getters fonctionnent
    geom::vector v1{2,1};
    geom::vector v2{1,2};
    geom::point p1{2,1};
    geom::point p2{1,2};
    balle b{v1,p1,4};
    SUBCASE("Modification de la vitesse de la balle"){
        b.setVitesse(v2);
        REQUIRE_EQ(v2.x(), b.getVitesse().x());
        REQUIRE_EQ(v2.y(), b.getVitesse().y());
    }
    SUBCASE("Modification de la position de la balle"){
        b.setPosition(p2);
        REQUIRE_EQ(p2.x(), b.getPosition().x());
        REQUIRE_EQ(p2.y(), b.getPosition().y());
    }
}

TEST_CASE("{balle} Déplacements de la balle en jeu"){
    geom::vector v{2,1};
    geom::point p{2,1};
    balle b{v,p,4};
    SUBCASE("Avancement de la balle en jeu"){
        //Test de la fonction avance(hauteur,largeur)
        int hauteur = 2;
        int largeur = 1;
        //b.avance(hauteur,largeur);
        //REQUIRE_EQ(p.x()+hauteur,b.getPosition().x());
    }
    SUBCASE("Collision de la balle en jeu"){
        //Test de la fonction collision(briques,raquette,hauteur,largeur)
        //Dans cette serie de tests on regarde la position de la balle après un certain temps pour voir si effectivement une collisoin a eu lieu ou pas
        //Necessite de declarer des briques et une raquette, donc d'avoir tester ces classes
        geom::vector v{0,1};
        geom::point p{4,1};
        balle b{v,p,1};
        int hauteur = 2;
        int largeur = 3;
        geom::point arr{4,8}; //Point d'arrivée sans collision de la brique test
        geom::point pbg{2,4}; //Point Bas gauche de la brique test
        geom::point phd{6,5}; //Point Haut Droit de la brique test
        surfaceNormale s{}; //Surface Normale d'une brique
        surfaceTueuse st{}; //Surface tueuse d'une brique

        SUBCASE("Pas de collision xy")
        {
            while(p.y()<=arr.y()&&p.x()<=arr.x())
            {
                b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition(),arr);
        }

        SUBCASE("Collision avec brique sans destruction de brique")
        {
            briqueIncassable bi{pbg, phd, &s};
            while(b.getPosition().y()<=arr.y()&& b.getPosition().y()>=p.y())/
            {
                 b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition,p); // Possibilité d'ajouter une marge
            REQUIRE_FALSE(b.getPosition(),arr);// Avec cette collision le point doit revenir au départ
            REQUIRE_EQ(b.casse(),false);
        }

        SUBCASE("Collision avec brique avec destruction de brique")
        {
            briqueCassable bi{pbg, phd, &s, 1};
            while(b.getPosition().y()<=arr.y()&& b.getPosition().y()>=p.y())
            {
                 b.avance(hauteur,largeur); //A vec cette collision le point doit revenir au départ
            }
            REQUIRE_EQ(b.getPosition,p); //Marge ?
            REQUIRE_FALSE(b.getPosition(),arr); //
            REQUIRE_EQ(bi.casse(),true);
        }

        SUBCASE("Collision avec brique tueuse")
        {
            briqueIncassable bi{pbg, phd, &st};
            while(b.getPosition().y()=<arr.y()&& b.getPosition().y()>=p.y())
            {
                 b.avance(hauteur,largeur); //Avec cette collision le point doit revenir au départ
            }
            REQUIRE_EQ(b.getPosition(),p);
            REQUIRE_FALSE(b.getPosition(),arr);
            REQUIRE_EQ(b.morte,true);
        }

        SUBCASE("Collision avec raquette")
        {
            raquette ra{pbg, phd, &s};
            while(b.getPosition().y()=<arr.y()&& b.getPosition().y()>=p.y())
            {
                 b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition(),p);
            REQUIRE_FALSE(b.getPosition(),arr);
        }

        SUBCASE("Collision avec mur")
        {

            while(b.getPosition().y()=<arr.y()&& b.getPosition().y()>=p.y())
            {
                 b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition(),p);
            REQUIRE_FALSE(b.getPosition(),arr);
        }

        /*SUBCASE("Pas de collision x")
        {
            int hauteur = 0;
            int largeur = 1;
            geom::point arr{2,10};
            while(p.x()<arr.x())
            {
                b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition,arr);
        }
        SUBCASE("Pas de collision y")
        {
            int hauteur = 2;
            int largeur = 0;
            geom::point arr{10,2};
            while(p.y()<arr.y()||p.)
            {
                b.avance(hauteur,largeur);
            }
            REQUIRE_EQ(b.getPosition,arr);
        }*/
        //On ne pourra pas tester les fonctions graphiques, est-ce que cela va faire planter le programme ?
    }
    //ECHOUE CAR DIVISION PAR 0 DANS LA FONCTION AVANCE
}

//On ne pourra pas tester les fonctions affiche() et efface() car ce sont des fonctions graphiques
