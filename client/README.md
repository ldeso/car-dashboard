# client

## Compilation

Se placer dans le dossier `client` et exécuter :

    qmake client.pro
    make

## Utilisation

Se placer dans le dossier `client` et exécuter :

    LD_LIBRARY_PATH=clientio ./client

## Bibliothèque

### Installation

Se placer dans le dossier `client` et exécuter :

    sudo make install

Le client peut alors se lancer avec la simple commande :

    ./client

Attention, penser à réinstaller la bibliothèque en cas de mise à jour.

## Désinstallation

Se placer dans le dossier `client` et exécuter :

    sudo make uninstall
