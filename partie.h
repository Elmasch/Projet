#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <memory>
#include "brique.h"
#include "balle.h"
#include <windows.h>

class partie
{
    public:
        partie(std::vector<std::unique_ptr<brique>> &b, balle &ba, int hauteur, int largeur);
        void jouer();
    private:
        balle d_balle;
        std::vector<std::unique_ptr<brique>> d_briques;
        int d_hauteur, d_largeur;
};

#endif // PARTIE_H
