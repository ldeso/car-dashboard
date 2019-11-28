
#A Faire

chacun crée sa classe prenom_scene qui herite de la classe commune scene_globale, qui elle même dérive de QGraphicsScene. Dans la scene_globale est déclarer :
 
 * un compteur vitesse qui contient une fonction __getValueMax__ qui retourne la vitesse max,et une fonction __setValue__ qui modifie la vitesse du compteur.
 * un compteur CompteTours qui contient une fonction __getValueMax__ qui retourne la valeur max,et une fonction __setValue__ qui modifie la valeur du compteur.
 * un voyant VoyantBatterie qui contient une fonction __setValue__, qui pour 1 affiche le voyant, et 0 l'éteint. Contient également une fonction __getValue__, qui retourne l'état du voyant.
 * un afficheur CompteurKm qui contient une fonction __setValue__, permettant d'afficher le nombre de km parcourus depuis le lancement du programme en fonction de la vitesse
 * une jauge Essence qui contient une fonction __getValueMax__ qui retourne la valeur max,et une fonction __setValue__ qui modifie la valeur du voyant.
 * un voyant Clignotant qui contient une fonction __setValue__, qui pour 1 le clignotant droit, -1 le clignotant gauche, et 0 l'éteint.
 * a completer
