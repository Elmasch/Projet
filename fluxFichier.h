#ifndef FLUXFICHIER_H
#define FLUXFICHIER_H

#include <iostream>
#include <fstream>
#include "partie.h"

using namespace std;

class fluxFichier
{
public:
    partie fluxLecture(const string &nom);
    bool fluxEcriture(const string &nom, const partie &p);
    bool fichierExiste(const string &nom);
};

#endif // FLUXFICHIER_H
