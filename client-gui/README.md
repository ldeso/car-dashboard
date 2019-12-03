# client-gui

Client graphique pour le projet car-dashboard.

## Prérequis

Le GUI nécessite la librarie `clientui` pour fonctionner. Pour compiler cette librairie, se référer à ses [instructions de compilation](../client/README.md#compilation).

## Compilation

Se placer dans le dossier `client-gui` et exécuter :

    qmake client-gui.pro
    make

## Utilisation

Se placer dans le dossier `client-gui` et exécuter :

    LD_LIBRARY_PATH=../client/clientio ./client-gui

Si la bibliothèque `clientio` est installée, le client graphique peut s'exécuter avec la commande :

    ./client-gui
