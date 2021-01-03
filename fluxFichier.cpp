#include "fluxFichier.h"

terrain fluxFichier::fluxLecture(const string &nom){
    terrain t{};
    if(fichierExiste(nom)){
        ifstream fichierLecture("sauvegardes/"+nom+".txt");
        if(fichierLecture){
            string poubelle;
            int hauteur, largeur;
            int x1, x2, y1, y2;
            double vitesse;
            int tueuse;
            int nombreCasse;
            std::vector<std::unique_ptr<brique>> briques;

            //1ere ligne avec date du jour
            getline(fichierLecture,poubelle);
            fichierLecture.ignore();

            //Ligne taille fenetre
            fichierLecture>>poubelle>>hauteur>>poubelle>>largeur;

            //Initialisations surfaces
            surfaceNormale sn{};
            surfaceTueuse st{};
            surfaceMolle sm{};
            surfaceDure sd{};

            //Initialisation point basGauche raquette
            fichierLecture>>poubelle>>x1>>poubelle>>y1;
            geom::point rBG{x1,y1};
            //Initialisation point hautDroite raquette
            fichierLecture>>poubelle>>x2>>poubelle>>y2>>poubelle;
            geom::point rHD{x2,y2};
            //Initialisation raquette
            raquette r{rBG,rHD,&sn};

            //Initialisation des briques
            char type;
            while(fichierLecture>>poubelle>>x1>>poubelle>>y1>>poubelle>>x2>>poubelle>>y2>>poubelle>>vitesse>>poubelle>>tueuse>>poubelle>>nombreCasse>>poubelle){
                //Initialisation point basGauche brique
                rBG = geom::point{x1,y1};
                //Initialisation point hautDroite brique
                rHD = geom::point{x2,y2};
                //Initialisation surface
                if(vitesse == 1){
                    if(tueuse == 1)
                        type='t';
                    else
                        type='n';
                }else{
                    if(vitesse == 0.8)
                        type='m';
                    else
                        type='d';
                }

                //Initialisation brique
                if(nombreCasse == 0){
                    if(type == 't'){
                        briques.push_back(std::make_unique<briqueIncassable>(rBG,rHD,&st));
                    }else if(type == 'n'){
                        briques.push_back(std::make_unique<briqueIncassable>(rBG,rHD,&sn));
                    }else if(type == 'm'){
                        briques.push_back(std::make_unique<briqueIncassable>(rBG,rHD,&sm));
                    }else if(type == 'd'){
                        briques.push_back(std::make_unique<briqueIncassable>(rBG,rHD,&sd));
                    }

                }else{
                    if(type == 't'){
                        briques.push_back(std::make_unique<briqueCassable>(rBG,rHD,&st,nombreCasse));
                    }else if(type == 'n'){
                        briques.push_back(std::make_unique<briqueCassable>(rBG,rHD,&sn,nombreCasse));
                    }else if(type == 'm'){
                        briques.push_back(std::make_unique<briqueCassable>(rBG,rHD,&sm,nombreCasse));
                    }else if(type == 'd'){
                        briques.push_back(std::make_unique<briqueCassable>(rBG,rHD,&sd,nombreCasse));
                    }
                }
            }
            terrain t{briques,hauteur,largeur,r};
        }
    }else
        cout<<"Le fichier ne peut etre lu car il est inexistant"<<endl;
    return t;
}

bool fluxFichier::fluxEcriture(const string &nom, const terrain & t){
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
        fichierEcriture<<"Fenetre: "<<t.getHauteur()<<" / "<<t.getLargeur()<<endl;
        fichierEcriture<<"Raquette:dimensions[( "<<t.getRaquette().getBasGauche().x()<<" , "<<t.getRaquette().getBasGauche().y()<<" ),( "<<t.getRaquette().getHautDroite().x()<<" , "<<t.getRaquette().getHautDroite().y()<<" )]"<<endl;
        for(int i=0;i<t.getBriques().size();i++){
            fichierEcriture<<"Brique"<<i+1<<":dimensions[( "<<t.getBriques()[i]->getBasGauche().x()<<" , "<<t.getBriques()[i]->getBasGauche().y()<<" ),( "<<t.getBriques()[i]->getHautDroite().x()<<" , "<<t.getBriques()[i]->getHautDroite().y()<<" )]";
            //fichierEcriture<<",surface:VITESSE( "<<p.getBriques()[i]->getSurface()->getVitesse()<<" ),TUEUSE( "<<p.getBriques()[i]->getSurface()->getMorte()<<" )";
            if(t.getBriques()[i]->cassable())
                fichierEcriture<<",CASSABLE( "<<t.getBriques()[i]->getNombre()<<" )";
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
