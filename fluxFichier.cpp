#include "fluxFichier.h"

partie fluxFichier::fluxLecture(const string &nom){
    partie p{};
    if(fichierExiste(nom)){
        ifstream fichierLecture("sauvegardes/"+nom+".txt");
        if(fichierLecture){
            string poubelle;
            int hauteur, largeur;
            int x1, x2, y1, y2;
            /*double vitesse;
            bool tueuse;
            int couleur;*/
            int nombreCasse;
            std::vector<std::unique_ptr<brique>> briques;

            //1ere ligne avec date du jour
            getline(fichierLecture,poubelle);
            fichierLecture.ignore();

            //Ligne taille fenetre
            fichierLecture>>poubelle>>hauteur>>poubelle>>largeur;

            //Initialisation position balle
            fichierLecture>>poubelle>>x1>>poubelle>>y1;
            geom::point position{x1,y1};
            //Initialisation vitesse balle
            fichierLecture>>poubelle>>x2>>poubelle>>y2>>poubelle;
            geom::vector vitesse{x2,y2};
            //Initialisation balle
            balle ba{vitesse,position,7};

            //Initialisation point basGauche raquette
            fichierLecture>>poubelle>>x1>>poubelle>>y1;
            geom::point rBG{x1,y1};
            //Initialisation point hautDroite raquette
            fichierLecture>>poubelle>>x2>>poubelle>>y2>>poubelle;
            geom::point rHD{x2,y2};
            //Initialisation raquette
            surfaceNormale s{};
            raquette r{rBG,rHD,&s};

            //Initialisation des briques
            while(fichierLecture>>poubelle>>x1>>poubelle>>y1>>poubelle>>x2>>poubelle>>y2>>poubelle>>/*vitesse>>poubelle>>tueuse>>poubelle>>couleur>>poubelle>>*/nombreCasse>>poubelle){
                //Initialisation point basGauche brique
                rBG = geom::point{x1,y1};
                //Initialisation point hautDroite brique
                rHD = geom::point{x2,y2};
                //Initialisation surface A MODIFIER
                surfaceNormale s{};

                //Initialisation brique
                if(nombreCasse == 0)
                    briques.push_back(std::make_unique<briqueIncassable>(rBG,rHD,&s));
                else
                    briques.push_back(std::make_unique<briqueCassable>(rBG,rHD,&s,nombreCasse));
            }
            partie p{ba,briques,hauteur,largeur,r};
        }
    }else
        cout<<"Le fichier ne peut etre lu car il est inexistant"<<endl;
    return p;
}

bool fluxFichier::fluxEcriture(const string &nom, const partie & p){
    if(fichierExiste(nom)){
        char c;
        do{
            cout<<"Le fichier existe deja, voulez vous ecraser son contenu ? (o/n) : ";
            cin>>c;
        }while(c != 'o' && c != 'n');
        if(c == 'n')
            return false;
    }
    ofstream fichierEcriture("sauvegardes/"+nom+".txt");
    if(fichierEcriture){
        time_t tmm = time(0);
        char* dt = ctime(&tmm);
        fichierEcriture<<"Date sauvegarde : "<<dt<<endl;
        fichierEcriture<<"Fenetre: "<<p.getHauteur()<<" / "<<p.getLargeur()<<endl;
        fichierEcriture<<"Balle:position[ "<<p.getBalle().getPosition().x()<<" , "<<p.getBalle().getPosition().y()<<" ],vitesse[ "<<p.getBalle().getVitesse().x()<<" , "<<p.getBalle().getVitesse().y()<<" ]"<<endl;
        fichierEcriture<<"Raquette:dimensions[( "<<p.getRaquette().getBasGauche().x()<<" , "<<p.getRaquette().getBasGauche().y()<<" ),( "<<p.getRaquette().getHautDroite().x()<<" , "<<p.getRaquette().getHautDroite().y()<<" )]"<<endl;
        for(int i=0;i<p.getBriques().size();i++){
            fichierEcriture<<"Brique"<<i+1<<":dimensions[( "<<p.getBriques()[i]->getBasGauche().x()<<" , "<<p.getBriques()[i]->getBasGauche().y()<<" ),( "<<p.getBriques()[i]->getHautDroite().x()<<" , "<<p.getBriques()[i]->getHautDroite().y()<<" )]";
            //fichierEcriture<<",surface:VITESSE( "<<p.getBriques()[i}->getSurface()->getVitesse()<<" ),TUEUSE( "<<p.getBriques()[i}->getSurface()->getMorte()<<" ),COULEUR( "<<p.getBriques()[i}->getSurface()->getCouleur()<<" )";
            if(p.getBriques()[i]->cassable())
                fichierEcriture<<",CASSABLE( "<<p.getBriques()[i]->getNombre()<<" )";
            else
                fichierEcriture<<",CASSABLE( 0 )";
            fichierEcriture<<endl;
        }
        fichierEcriture.close();
        return true;
    }else
        cout<<"Impossible de creer le fichier "<<nom<<".txt"<<endl;
    return false;
}

bool fluxFichier::fichierExiste(const string &nom){
    ifstream fichierLecture("sauvegardes/"+nom+".txt");
    if(!fichierLecture)
        return false;
    if(fichierLecture.is_open()){
        fichierLecture.close();
        return true;
    }
    return false;
}
