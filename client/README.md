# client

Client en ligne de commande pour le projet car-dashboard.

## Compilation

Se placer dans le dossier `client` et exécuter :

    qmake client.pro
    make

## Utilisation

Se placer dans le dossier `client` et exécuter :

    LD_LIBRARY_PATH=clientio ./client

## Bibliothèque

### Installation de la bibliothèque clientio

Se placer dans le dossier `client` et exécuter :

    sudo make install

Le client peut alors se lancer avec la simple commande :

    ./client

Attention, penser à réinstaller la bibliothèque en cas de mise à jour.

### Désinstallation de la bibliothèque clientio

Se placer dans le dossier `client` et exécuter :

    sudo make uninstall
