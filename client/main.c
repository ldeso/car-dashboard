#include <stdlib.h> /* Pour exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/socket.h> /* Pour socket */
#include <arpa/inet.h> /* Pour IPPROTO_TCP */
#include <stdio.h> /* Pour perror */
#include <unistd.h> /* Pour close */
#include <string.h> /* Pour memset */
/**
 * @brief upperCase
 * @param toUp
 * @details met en majuscule un char *
 */
void upperCase(char* toUp){
    int size = strlen(toUp);
    for(int i = 0; i < size; i++){
        if(toUp[i] >= 'a' && toUp[i] <= 'z')
            toUp[i] -= 32;
    }
}

/**
 * @brief viderBuffer
 * @details vide le buffer après un fgets
 */
void viderBuffer(){
    int c = 0;
    while (c != '\n')
    {
        c = getchar();
    }
}

/**
 * @brief main
 * @return EXIT_SUCCESS si le programme se termine normalement
 * sinon EXIT_FAILURE avec affichage d'une erreur dans le terminal
 * @details saisie des commandes en deux temps : d abord le nom de la commande puis après la valeur
 * todo : ajouter les commandes CANN pour les differents elements du dashboard.
 * Les messages seront du format CANN TYPEDECANN VALUE
 */
int main() {
    int fd;
    char * message;
    char * recep;
    char * ptr = (char*) malloc(sizeof(char)*10);
    char * tmp = (char*) malloc(sizeof(char)*50);
    int valeur;
    int valide = 0;
    struct sockaddr_in adresse;
    // creation de la socket
    if ((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Erreur lors de la creation de la socket ");
        exit(EXIT_FAILURE);
    }


    // Remplissage de la structure
    memset( & adresse, 0, sizeof(struct sockaddr_in));
    adresse.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", & adresse.sin_addr.s_addr);

    adresse.sin_port = htons(2222);

    // Connexion au serveur
    if (connect(fd, (struct sockaddr * ) & adresse, sizeof(adresse)) == -1) {
        perror("Erreur lors de la connexion ");
        exit(EXIT_FAILURE);
    }
    printf("connexion au serveur\n");

    //allocation du char* message
    if ((message = (char * ) malloc(sizeof(char)*50)) == NULL) {
        perror("Erreur lors de l'allocation memoire pour le message ");
        exit(EXIT_FAILURE);
    }

    if ((recep = (char * ) malloc(sizeof(char)*50)) == NULL) {
        perror("Erreur lors de l'allocation memoire pour le message ");
        exit(EXIT_FAILURE);
    }
    //boucle permettant l'envoi de message au serveur avec saisie utilisateur
    //TO DO : ajouter les differents test
    do{
        printf("Veuillez saisir une commande à envoyer \n");
        printf("Veuillez saisir HELP pour avoir  la liste de commande \n");
        //boucle qui se termine si l'utilisateur ecrit une commande correcte.
        valide = 0;
        while(valide == 0){
            if(fgets(message, 50, stdin)== NULL){
                perror("erreur lors du fgets");
                exit(EXIT_FAILURE);
            }
            //supprimer le \n du char*
            message[strlen(message)-1] = '\0';
            upperCase(message);
            //compare la commande saisie avec l'une des commandes existantes
            // TO DO ajouter les differentes commandes à la section HELP avec des printf
            if(strcasecmp(message,"HELP")== 0){
                //printf("Veuillez d abord saisir une commande, valider, puis saisir une valeur\n");
                printf("Liste des commandes valides : \n");
                printf("CANN SPEED X avec X compris entre 0 et 400\n");
                printf("CANN RPM X avec X compris entre 0 et 15000\n");
                printf("CANN BATTERY_LIGHT X avec X = 0 ou 1\n");
                printf("CANN GAZ x avec x compris entre 0 et 100\n");
                printf("CANN TURN x avec -1 gauche, 0 rien, 1 droite\n");
                valide = 1;
            }
            else{
                strcpy(tmp,message);
                char * cann;
                char * typeCann;
                char * charValue;
                cann = strtok_r(tmp," ", &ptr);
                tmp = ptr;
                typeCann = strtok_r(tmp," ", &ptr);
                tmp = ptr;
                charValue = strtok_r(tmp," ", &ptr);

                if(strcasecmp(cann,"CANN")== 0 && strcasecmp(typeCann, "SPEED") == 0){
                    if (send(fd, message, sizeof(char)*80, 0) < 0) {
                        perror("send()");
                        exit(EXIT_FAILURE);
                    }
                    if(recv(fd, recep, sizeof(char)*50, 0) < 0)
                    {
                        perror("recv()");
                        exit(EXIT_FAILURE);
                    }
                    printf("%s\n", recep);

                }
                else if(strcasecmp(cann,"CANN")== 0 && strcasecmp(typeCann, "RPM") == 0){
                    if (send(fd, message, sizeof(char)*80, 0) < 0) {
                        perror("send()");
                        exit(EXIT_FAILURE);
                    }
                    if(recv(fd, recep, sizeof(char)*50, 0) < 0)
                    {
                        perror("recv()");
                        exit(EXIT_FAILURE);
                    }
                    printf("%s\n", recep);

                }
                else if(strcasecmp(cann,"CANN")== 0 && strcasecmp(typeCann, "BATTERY_LIGHT") == 0){
                    if (send(fd, message, sizeof(char)*80, 0) < 0) {
                        perror("send()");
                        exit(EXIT_FAILURE);
                    }
                    if(recv(fd, recep, sizeof(char)*50, 0) < 0)
                    {
                        perror("recv()");
                        exit(EXIT_FAILURE);
                    }
                    printf("%s\n", recep);

                }
                else if(strcasecmp(cann,"CANN")== 0 && strcasecmp(typeCann, "GAZ") == 0){
                    if (send(fd, message, sizeof(char)*80, 0) < 0) {
                        perror("send()");
                        exit(EXIT_FAILURE);
                    }
                    if(recv(fd, recep, sizeof(char)*50, 0) < 0)
                    {
                        perror("recv()");
                        exit(EXIT_FAILURE);
                    }
                    printf("%s\n", recep);

                }
                else if(strcasecmp(cann,"CANN")== 0 && strcasecmp(typeCann, "TURN") == 0){
                    if (send(fd, message, sizeof(char)*80, 0) < 0) {
                        perror("send()");
                        exit(EXIT_FAILURE);
                    }
                    if(recv(fd, recep, sizeof(char)*50, 0) < 0)
                    {
                        perror("recv()");
                        exit(EXIT_FAILURE);
                    }
                    printf("%s\n", recep);

                }
                //else if(){} NE PAS SUPPRIMER CE COMMENTAIRE
                //TO DO Ajouter les conditions pour les messages
                else{
                    printf("Commande invalide, Veuillez saisir une commande valide : \n");
                }


            }

        }


    }while(message != "end");

    /* Fermeture de la socket */
    if (close(fd) == -1) {
        perror("Erreur lors de la fermeture de la socket ");
        exit(EXIT_FAILURE);
    }
    free(tmp);
    free(ptr);
    free(message);
    free(recep);
    return EXIT_SUCCESS;
}
