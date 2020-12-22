# CasseBrique2021
Projet de Qualité de Programmation, L3 MIAGE

Lien vers le Dossier Word :
https://1drv.ms/w/s!Ai2kPxkmuv8XnRJx_nl8FNv5mmLM?e=8UphOj

Lien vers le Powerpoint :
https://1drv.ms/p/s!Ai2kPxkmuv8XnRR3yfEnFIBHo30a?e=x5gQmj


ELEMENTS A PRENDRE EN COMPTE
-balle.h :
    *Est-ce que c'est utile de stocker le rayon pour chaque balle étant donné qu'il est inchangé et qu'il n'a pas de getter ?
    *J'ai l'impression que les accélérations et décélérations de la balle sont trop brusques ...
    *Est-ce utile de conserver le constructeur sans paramètre de la balle vu qu'il n'est pas défini dans le balle.cpp ?
-brique.h :
    *Il faudrait que la taille des briques varie en fonction de la taille de la fenêtre
    *Idem pour la vitesse de déplacement de la raquette
    *Si basGauche.x() vaut 20 et que le déplacement le fait bouger de 30, il est possible que la raquette ait pour coordonnées
     de basGauche.x() = -10 ... Pose un problème pour les tests
-Ce qui se passe dans le main.cpp n'est pas testé. Pareil pour winbgi.cpp, graphics.h et doctest.h

ENCORE A FAIRE
-Collision brique et mur en même temps (balle.cpp partie collision)
-Limiter la vitesse max et min d’une balle, car si elle va trop vite on la voit pas 
-Gérer le fichier texte
-Afficher brique correctement, sans superposition
-Tests de la classe partie.h (et peut-être terrain.h)

IDEES
-Faire un cercle rempli pour la balle
-Rajouter des conditions de fin de partie s'il ne reste que des briques incasssables et/ou tueuses
-Briques qui se déplacent
-Mettre en place des niveaux avec des briques à des endroits prédéfinis 