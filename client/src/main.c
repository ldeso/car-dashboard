#include <ctype.h> // toupper
#include <stdio.h> // fgets, fprintf, getchar, printf, puts
#include <string.h> // strncmp

#include "clientio.h"

/**
 * @brief die
 * @details arrêt du programme avec un message d'erreur dans le terminal
 */
void __attribute__((noreturn)) die(const char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(EXIT_FAILURE);
}

/**
 * @brief enter_message
 * @details saisie d'un message par l'utilisateur
 */
void enter_message(char *message, const size_t len)
{
    fgets(message, (int) len, stdin);
    size_t newline_span = strcspn(message, "\n");
    while (message[newline_span] != '\n') {
        printf("Message trop long (max = %zu). Réessayer : ", len-2);
        while (getchar() != '\n');
        fgets(message, (int) len, stdin);
        newline_span = strcspn(message, "\n");
    }
    message[newline_span] = '\0';
}

/**
 * @brief uppercase
 * @details met en majuscule un char *
 */
void uppercase(char *message)
{
    char *ptr = message;
    while (*ptr) {
        *ptr = (char) toupper((unsigned char) *ptr);
        ptr++;
    }
}

/**
 * @brief main
 * @return EXIT_SUCCESS si le programme se termine normalement
 * sinon EXIT_FAILURE avec affichage d'une erreur dans le terminal
 * @details saisie des commandes en deux temps : d'abord le nom de la commande puis après la valeur
 * todo : ajouter les différents tests.
 * todo : ajouter les commandes CANN pour les differents elements du dashboard.
 * Les messages seront du format CANN TYPEDECANN VALUE
 */
int main()
{
    char *sent;
    char *received;
    size_t len = 50;
    int sockfd;
    if ((sent = malloc(len)) == NULL)
        die("Erreur lors de l'allocation mémoire pour le message émis.");
    if ((received = malloc(len)) == NULL)
        die("Erreur lors de l'allocation mémoire pour le message reçu.");
    if ((sockfd = create_connected_socket("127.0.0.1", 2222)) == -1)
        die("Erreur lors de la connexion au serveur.");
    int end = 0;
    while (!end) {
        puts("Veuillez saisir une commande à envoyer.");
        puts("Veuillez saisir HELP pour afficher la liste de commande.");
        enter_message(sent, len);
        uppercase(sent);
        if (strncmp(sent, "HELP", len) == 0) {
            puts("Liste des commandes valides :");
            puts("CANN BATTERY_LIGHT x avec x = 0 ou 1");
            puts("CANN DASHBOARD x où x est le prénom");
            puts("CANN GAZ x avec x compris entre 0 et 100");
            puts("CANN LIGHT x avec x = 0 éteint, 1 position, 2 croisement, 3 route");
            puts("CANN RPM x avec x compris entre 0 et 15000");
            puts("CANN SPEED x avec x compris entre 0 et 400");
            puts("CANN SPEED_LIMIT x où x est la limitation de vitesse en km/h");
            puts("CANN TURN x avec x = -1 gauche, 0 rien, 1 droite");
            puts("CANN WARNING x avec x = 0 eteint et 1 allumé");
            puts("CANN ASD x avec x = 0 eteint et 1 allumé");
            puts("CANN MODE X avec x= 1 Park, 2 Reverse, 3 Neutral, 4 Drive");
            puts("CANN FRONT_FOG x avec x = 0 eteint et 1 allumé");
            puts("CANN REAR_FOG x avec x = 0 eteint et 1 allumé");
            puts("CANN SEAT_BELT x avec x = 0 eteint et 1 allumé");
            puts("CANN RW_HEAT x avec x = 0 eteint et 1 allumé");
            puts("CANN CHECK_ENGINE x avec x = 0 eteint et 1 allumé");
            puts("CANN OPEN_DOOR_DRIVER x = 0 eteint et 1 allumé" );
            puts("CANN OPEN_DOOR_FRONT_PASSENGER x = 0 eteint et 1 allumé" );
            puts("CANN OPEN_DOOR_BACK_L_PASSENGER x = 0 eteint et 1 allumé" );
            puts("CANN OPEN_DOOR_BACK_R_PASSENGER x = 0 eteint et 1 allumé" );

        } else if (strncmp(sent, "END", len) == 0) {
            end = 1;
        } else {
            if (validate_message(sent) == -1) {
                puts("Commande invalide.");
            } else {
                if ((send_message(sockfd, sent, len)) == -1)
                    die("Erreur lors de l'envoi du message.");
                if ((receive_message(sockfd, received, len)) == -1)
                    die("Erreur lors de la réception du message.");
                puts(received);
            }
        }
    }
    if (close_socket(sockfd) == -1)
        die("Erreur lors de la fermeture de la connexion.");
    free(sent);
    free(received);
    return EXIT_SUCCESS;
}
