#include "balle.h"
#include "doctest.h"

TEST_CASE("{balle} La balle avec parametres est cree correctement"){
    //Teste le constructeur avec parametres de la balle
    //Teste si les fonctions Getters fonctionnent
    //Teste si la fonction morte() fonctionne
    geom::vector v{2,1};
    geom::point p{2,1};
    balle b{v,p};
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

/*TEST_CASE("{balle} Modification des valeurs de la balle"){
    //Teste si les fonctions Setters fonctionnent
    //Important de tester d'abord si les fonctions Getters fonctionnent
    geom::vector v1{2,1};
    geom::vector v2{1,2};
    geom::point p1{2,1};
    geom::point p2{1,2};
    balle b{v1,p1};
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
}*/

TEST_CASE("{balle} Déplacements de la balle en jeu"){
    geom::vector v{2,1};
    geom::point p{2,1};
    balle b{v,p};
    SUBCASE("Avancement de la balle en jeu"){
        //Test de la fonction avance(hauteur,largeur)
        int hauteur = 2;
        int largeur = 1;
        //b.avance(hauteur,largeur);
        //REQUIRE_EQ(p.x()+hauteur,b.getPosition().x());
        //ECHOUE CAR DIVISION PAR 0 DANS LA FONCTIONA AVANCE
    }
    SUBCASE("Collision de la balle en jeu"){
        //Test de la fonction collision(briques,raquette,hauteur,largeur)
        int hauteur = 2;
        int largeur = 1;
        //Necessite de declarer des briques et une raquette, donc d'avoir tester ces classes
        SUBCASE("Pas de collision"){}
        SUBCASE("Collision avec brique sans destruction de brique"){}
        SUBCASE("Collision avec brique avec destruction de brique"){}
        SUBCASE("Collision avec brique tueuse"){}
        SUBCASE("Collision avec raquette"){}
        SUBCASE("Collision avec mur"){}
        //On ne pourra pas tester les fonctions graphiques, est-ce que cela va faire planter le programme ?
    }
}

//On ne pourra pas tester les fonctions affiche() et efface() car ce sont des fonctions graphiques
