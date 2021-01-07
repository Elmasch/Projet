#include <iostream>
#include "terrain.h"

terrain::terrain() : d_hauteur{0}, d_largeur{0}, d_balle{}
{}

terrain::terrain(const int hauteur, const int largeur) : d_hauteur{hauteur} , d_largeur{largeur}, d_balle{}
{}

terrain::terrain(std::vector<std::unique_ptr<brique>>& br,int hauteur, int largeur,raquette r, balle b) : d_hauteur{hauteur}, d_largeur{largeur}, d_raquette{r}, d_balle{b}
{
    for(int i=0;i<br.size();i++){
        d_briques.push_back(move(br[i]));
    }
}


terrain::terrain(std::vector<std::unique_ptr<brique>>& br,int hauteur, int largeur,raquette r) : d_hauteur{hauteur}, d_largeur{largeur}, d_raquette{r}, d_balle{}
{
    for(int i=0;i<br.size();i++){
        d_briques.push_back(move(br[i]));
    }
}

void terrain::initialisation(){
    srand(time(NULL));

    geom::point p1;
    geom::point p2;
    geom::point p3{(d_largeur/2)-(d_largeur/6) ,d_hauteur - 100};
    geom::point p4{(d_largeur/2)+(d_largeur/6),d_hauteur - 80};
    geom::point p5;

    auto sn = new surfaceNormale{};
    auto st = new surfaceTueuse{};
    auto sd = new surfaceDure{};
    auto sm = new surfaceMolle{};

    //BRIQUES BLANCHES CASSABLES EN n FOIS
    //i sera le nombre de briques
    for(int i = 0; i < 3; ++i){
        do{
            int l = rand()%(d_largeur-400);
            int h = rand()%(d_hauteur-400);
            p1 = {l,h};
            p2 = {l+d_largeur/8,h+20};
        }while(superposition(std::make_unique<briqueCassable>(p1,p2,sn,2)));
        d_briques.push_back(std::make_unique<briqueCassable>(p1,p2,sn,2));
    }

    //BRIQUES CYANS INCASSABLES
    for(int i = 0; i < 3; ++i){
        do{
            int l = rand()%(d_largeur-400);
            int h = rand()%(d_hauteur-400);
            p1 = {l,h};
            p2 = {l+d_largeur/8,h+20};
        }while(superposition(std::make_unique<briqueIncassable>(p1,p2,sd)));
        d_briques.push_back(std::make_unique<briqueIncassable>(p1,p2,sd));
    }

    //BRIQUES VERTES CASSABLES EN 1 FOIS
    for(int i = 0; i < 3; ++i){
       do{
            int l = rand()%(d_largeur-400);
            int h = rand()%(d_hauteur-400);
            p1 = {l,h};
            p2 = {l+d_largeur/8,h+20};
        }while(superposition(std::make_unique<briqueCassable>(p1,p2,sm,1)));
        d_briques.push_back(std::make_unique<briqueCassable>(p1,p2,sm,1));
    }

    d_raquette = {p3,p4,sn};
    p5 = {(d_raquette.getHautDroite().x()-d_raquette.getBasGauche().x())/2 + d_raquette.getBasGauche().x(),d_raquette.getHautDroite().y() - d_balle.getRayon()*2};
    d_balle.setPosition(p5);
}


bool terrain::superposition(std::unique_ptr<brique> b){
    for(int i=0;i<d_briques.size();i++){
        //UTILSABLE SI LA METHODE BOOLEENNE OPERATOR > DE LA CLASSE POINT FONCTIONNE
        /*if((b->getHautDroite() > d_briques[i]->getBasGauche() && d_briques[i]->getHautDroite() > b->getHautDroite()) ||
           (d_briques[i]->getHautDroite() > b->getBasGauche() && b->getHautDroite() > d_briques[i]->getHautDroite())){
            return true;
        }*/
        if((b->getHautDroite().y() > d_briques[i]->getBasGauche().y() && d_briques[i]->getHautDroite().y() > b->getHautDroite().y()) ||
           (d_briques[i]->getHautDroite().y() > b->getBasGauche().y() && b->getHautDroite().y() > d_briques[i]->getHautDroite().y())){
            if((b->getHautDroite().x() > d_briques[i]->getBasGauche().x() && d_briques[i]->getHautDroite().x() > b->getHautDroite().x()) ||
           (d_briques[i]->getHautDroite().x() > b->getBasGauche().x() && b->getHautDroite().x() > d_briques[i]->getHautDroite().x()))
            return true;
        }
    }
    return false;
}

void terrain::jouer(){
    opengraphsize(d_largeur,d_hauteur);
    setbkcolor(BLACK);
    cleardevice();
    char direction;
    while(!checkfin()){
        d_balle.collision(d_briques, d_raquette, d_hauteur, d_largeur);
        if(!checkfin()){
            setcolor(9);
            bar(0,0,5, d_hauteur);
            bar(0,0,d_largeur, 5);
            bar(d_largeur-13,0,d_largeur, d_hauteur);
            d_raquette.affiche();
            if(kbhit()){
                direction = getch();
                if(direction == 'q' || direction == 'd' || direction == 'Q' || direction == 'D')
                    d_raquette.bouge(direction, d_largeur);
            }
            Sleep(10);
        }
    }
    closegraph();
}

bool terrain::checkfin(){
    bool check = false;
    if(d_briques.size() == 0 || d_balle.morte()){
        check = true;
    }else{
        for(int i=0;i<d_briques.size();i++){
            if(d_briques[i]->cassable()){
                if(!d_briques[i]->getSurface()->getMorte())
                    check = false;
            }

        }
    }
    return check;
}

int terrain ::getHauteur() const{
    return d_hauteur;
}

int terrain ::getLargeur() const{
    return d_largeur;
}

balle terrain::getBalle(){
    return d_balle;
}

void terrain::setHauteur(int hauteur){
    d_hauteur = hauteur;
}
void terrain::setLargeur(int largeur){
    d_largeur=largeur;
}

const std::vector<std::unique_ptr<brique>>* terrain::getBriques() const{
    return &d_briques;
}

raquette terrain::getRaquette() const{
    return d_raquette;
}
