# client-gui

Client graphique pour le projet car-dashboard.

## Prérequis

Le GUI nécessite la bibliothèque `clientio` pour fonctionner. Pour compiler
cette bibliothèque, se référer à ses
[instructions de compilation](../client/README.md#compilation).

Attention: si cette bibliothèque est compilée dans Qt Creator, elle doit être
compilée avec l'option "Shadow Build" désactivée (à gauche dans l'onglet
"Projets").

## Compilation

Se placer dans le dossier `client-gui` et exécuter :

    qmake client-gui.pro
    make

## Utilisation

Se placer dans le dossier `client-gui` et exécuter :

    LD_LIBRARY_PATH=../client/clientio ./client-gui

Si la bibliothèque `clientio` est installée, le client graphique peut s'exécuter
avec la commande :

    ./client-gui
