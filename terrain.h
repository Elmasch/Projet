#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <memory>
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <time.h>

#include "graphics.h"

#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include "briqueCassable.h"
#include "briqueIncassable.h"
#include "surfaceNormale.h"
#include "surfaceMolle.h"
#include "surfaceDure.h"
#include "surfaceTueuse.h"

class terrain
{
    public:
        terrain();
        terrain(const int hauteur, const int largeur);
        terrain(std::vector<std::unique_ptr<brique>>& br,int hauteur, int largeur,raquette r);

        void initialisation () ;
        bool superposition(std::unique_ptr<brique> b);
        void jouer();
        bool checkfin();

        int getHauteur() const;
        int getLargeur() const;

        void setHauteur(int hauteur);
        void setLargeur(int largeur);

        balle getBalle() const;
        const std::vector<std::unique_ptr<brique>>* getBriques() const;
        raquette getRaquette() const;

    private:
        balle d_balle;
        std::vector<std::unique_ptr<brique>> d_briques;
        int d_hauteur, d_largeur;
        raquette d_raquette;
};

#endif // TERRAIN_H
