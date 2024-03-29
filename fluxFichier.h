#ifndef FLUXFICHIER_H
#define FLUXFICHIER_H

#include <iostream>
#include <fstream>
#include "terrain.h"

using namespace std;

class fluxFichier
{
public:
    void fluxLecture(const string &nom, terrain* &t);
    bool fluxEcriture(const string &nom, const terrain &t);
    bool fichierExiste(const string &nom);
};

#endif // FLUXFICHIER_H
