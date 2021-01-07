#include "surface.h"
#include "surfaceNormale.h"
#include "surfaceDure.h"
#include "surfaceMolle.h"
#include "surfaceTueuse.h"
#include "doctest.h"

//Constructeur non teste car aucun parametre et aucune initialisation
//Teste les Getters des classes associees qui heritent de la classe surface
//Mettre à jours les valeurs brutes si MAJ
TEST_CASE("{surface} Acces aux proprietes des differentes surfaces"){
    double vitesseN = 1;
    double vitesseD = 1.2;
    double vitesseM = 0.8;
    double vitesseT = 1;
    int couleurN = 7;
    int couleurD = 10;
    int couleurM = 8;
    int couleurT = 6;
    surfaceNormale sn{};
    surfaceDure sd{};
    surfaceMolle sm{};
    surfaceTueuse st{};
    SUBCASE("Acces aux proprietes Morte et a la vitesse de la surface NORMALE"){
        REQUIRE_EQ(vitesseN,sn.getVitesse());
        REQUIRE_FALSE(sn.getMorte());
        REQUIRE_EQ(couleurN,sn.getCouleur());
    }
    SUBCASE("Acces aux proprietes Morte et a la vitesse de la surface DURE"){
        REQUIRE_EQ(vitesseD,sd.getVitesse());
        REQUIRE_FALSE(sd.getMorte());
        REQUIRE_EQ(couleurD,sd.getCouleur());
    }
    SUBCASE("Acces aux proprietes Morte et a la vitesse de la surface MOLLE"){
        REQUIRE_EQ(vitesseM,sm.getVitesse());
        REQUIRE_FALSE(sm.getMorte());
        REQUIRE_EQ(couleurM,sm.getCouleur());
    }
    SUBCASE("Acces aux proprietes Morte et a la vitesse de la surface TUEUSE"){
        REQUIRE_EQ(vitesseT,st.getVitesse());
        REQUIRE(st.getMorte());
        REQUIRE_EQ(couleurT,st.getCouleur());
    }
}
