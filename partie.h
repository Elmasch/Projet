#ifndef PARTIE_H
#define PARTIE_H

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

class partie
{
    public:
        partie(const int hauteur, const int largeur);
        void jouer();
    private:
        balle d_balle;
        std::vector<std::unique_ptr<brique>> d_briques;
        int d_hauteur, d_largeur;
        raquette d_raquette;
};

#endif // PARTIE_H
