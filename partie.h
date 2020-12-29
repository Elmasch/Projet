#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <memory>
#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include <windows.h>

class partie
{
    public:
        partie(std::vector<std::unique_ptr<brique>> &b, balle &ba, int hauteur, int largeur, raquette &r);
        void jouer();
        std::vector<std::unique_ptr<brique>> &getBrique();
    private:
        balle d_balle;
        std::vector<std::unique_ptr<brique>> d_briques;
        int d_hauteur, d_largeur;
        raquette d_raquette;
};

#endif // PARTIE_H
