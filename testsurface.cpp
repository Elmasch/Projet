#include "surface.h"
#include "surfaceNormale.h"
#include "surfaceDure.h"
#include "surfaceMolle.h"
#include "surfaceTueuse.h"
#include "doctest.h"

//Constructeur non teste car aucun parametre et aucune initialisation

TEST_CASE("{surface} Acces aux proprietes des differentes surfaces"){
    //Teste les Getters des classes associees qui heritent de la classe surface
    surfaceNormale sn{};
    surfaceDure sd{};
    surfaceMolle sm{};
    surfaceTueuse st{};
    SUBCASE("Acces a la vitesse de la surface"){
        REQUIRE_EQ(1,sn.getVitesse());
        REQUIRE_EQ(1.2,sd.getVitesse());
        REQUIRE_EQ(0.8,sm.getVitesse());
        REQUIRE_EQ(1,st.getVitesse());
    }
    SUBCASE("Acces a la propriete qui decide si la balle doit mourir au contact"){
        REQUIRE_FALSE(sn.getMorte());
        REQUIRE_FALSE(sd.getMorte());
        REQUIRE_FALSE(sm.getMorte());
        REQUIRE(st.getMorte());
    }
    //Judicieux de tester getCouleur() qui renvoie la couleur de chaque surface ??...
}
