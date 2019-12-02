#Projet dashboard
Ce document a pour but de clarifier l'ensemble des opérations nécéssaires afin d'intégrer au programme un dashboard ou une fonctionnalité, de lister l'ensemble des fonctionnalités/objets disponibles, et de répertorier les éventuels bugs apparus lors de l'utilisation du programme.

##Intégrer son projet au serveur
Cette section explique en détails la manière d'intégrer son dashboard au serveur.
Le but premier du serveur est de permettre un changement dynamiqueme de dashboard à la suite d'un simple message du client. Il est également important d'harmoniser le nommage des différents objets ainsi que de de leur fonction, et ce afin que le programme soi fonctionnel pour l'ensemble des dashboards. Ainsi, il est nécéssaire de suivre les étapes suivantes avant d'intégrer son projet au serveur.

* Une classe scene\_globale, dérivant de QGraphicsScene a été créée. Elle permet de pouvoir passer dynamiquement d'un dashboard à un autre. Votre classe scène, que vous pouvez nommer prénom_scene et qui contient l'ensemble de vos éléments graphiques, doit donc elle même hériter de scene\_globale. 
* De même, une classe objet_virtuel contenant 3 méthodes (setValue, setValueMax,getValue) a été créée. Toutes vos classes compteur, voyant, jauge, etc... doivent hériter de cette classe, afin de rendre tous les objets fonctionnels. 
* Une fois l'ensemble de ces opérations effectuées, votre projet devrait être en mesure d'intégrer le serveur. On objet scene_globale *dashboard a déjà été intégré à "mainwindow.h". Il vous suffit donc de rajouter un #include "prénom_scene" dans le "mainwindow.h". Ensuite, dans la fonction MainWindow::reception() de "mainwindow.cpp", vous pouvez définir votre dashboard dans la partie correspondant au message "CANN DASHBOARD":
    - delete dashboard; --> permet de supprimer le dashboard défini au préalable.
     - dashboard = new prénom_scene;--> définit l'objet dashboard avec votre classe dérivant de scene_globale.
    - ui->graphicsView->setScene(dashboard);-->attribut votre scène au QgraphicsView.
    
   Une fois votre scène intégrée au serveur, il est alors possible d'y intégrer de nouveaux objets et fonctionnalités. Vous pouvez tester la réussite de l'intégration de votre dashboard en envoyant le message CANN DASHBOARD prénom à partir du client.
##Intégration d'un nouvel objet au client et au serveur
L'ensemble des objets accessibles pour tous les dashboards sont définis en tant que objet_virtuel dans "scene_globale.h". Ceci implique qu'un dashboard ne doit pas obligatoirement posséder in situ l'ensemble des objets et fonctionnalités définis dans "scene_globale.h". Il est en revanche bien évidemment déconseillé de lancer à partir du client des messages CANN concernant des fonctionnalités non inclues dans votre dashboard. Suivez ces différentes étapes pour ajouter un objet au programme:

* Déclarez votre objet en tant que objet_virtuel dans "scene_globale.h". Il sera ensuite défini de la façon qu'il vous plaira dans votre prénom_scene. 
* Dans le fichier "main.c" du client, dans la partie concernant la commande HELP, ajoutez votre message CANN, ainsi qu'une brève déscription de ce dernier.
* Dans la foncion MainWindow::reception() de"mainwindow.cpp", rajoutez une condition correspondant à votre message CANN, ainsi que l'algorithme fonctionnel. Ce dernier ne doit utiliser que les fonctions getValue,setValue et getValueMax définies dans la classe objet_virtuel. N'hésitez pas à rajouter des messages d'erreur en cas de variables non compatibles en provenance du client.
* Dans le fichier "README.md", dans la partie Liste des messages CANN, rajoutez une descriptif de votre fonctionnalité.

##Liste des messages CANN

|Nom de l'bjet|Description|Message CANN|	Valeurs|
|:---------|	:-------------------:|	:-------------------------:|	------------:|
|Vitesse|Compteur vitesse|CANN SPEED X|X=vitesse|
|CompteTours| Compteur tour/min moteur|CANN RPM X|X=rpm|
|VoyantBatterie|Voyant indiquant changement de batterie|CANN BATTERY_LIGHT|0 éteint,1 allumé|
|Essence|Jauge essence|CANN GAZ X|X=%d'essence restant|
|position|Feux de position|CANN LIGHT X|0=éteint, 1=allumé|
|croisement|Feux de croisement|CANN LIGHT X|0=éteint, 2=allumé|
|route|Feux de route|CANN LIGHT X|0=éteint, 3=allumé|
|Clignotant|Allume les clignotants gauche ou droit|CANN TURN X|1=clignotant droit,-1=clignotant gauche, 0=éteint
|Warning| Allume le warning et met la valeur des clignotants à 2|CANN WARNING X|0=éteint, 1=allumé|
|AdaptiveSuspensionDampers|Voyant indiquant Voyant indiquant que ASD est utilisé |CANN ASD X|0 éteint, 1 allumé|
|AutomaticTransmissionMode| **indicate the current transmition mode in use**| CANN MODE  X|1=P, 2=R, 3=N, 4=D |
|FrontAntifog | feux de brume avants |CANN FRONT_FOG X|0=éteint, 1=allumé|
|RearAntifog | feux de brume arrières |CANN REAR_FOG X|0=éteint, 1=allumé|

##Bugs répertoriés

#A Faire

chacun crée sa classe prenom_scene qui herite de la classe commune scene_globale, qui elle même dérive de QGraphicsScene. Dans la scene_globale sont déclarés tout les items ci-dessous qui doivent hériter de objet_virtuel. A partir du client, possibilité de changer de Dashboard par la commande CANN DASHBOARD prenom.


 
 * un compteur Vitesse, pour value la vitesse.
 * un compteur CompteTours pour value les tours par minute.
 * un voyant VoyantBatterie pour value 0/1 pour éteint/allumé
 * un afficheur CompteurKm, permettant d'afficher le nombre de km parcourus depuis le lancement du programme en fonction de la vitesse.
 * une jauge Essence 
 * un voyant Clignotant avec pour value 1 le clignotant droit, -1 le clignotant gauche, et 0 éteint.
 * trois voyants pour les phares : position, croisement, route. value client : 0 eteint, 1 position, 2 croisement, 3 route. Serveur : trois voyants différents.
 * Warning avec pour valeur 0 eteint et 1 allumer. Met la valeur des clignotants à 2 ce qui fait que les deux clignotants s'allument.
 * a completer
