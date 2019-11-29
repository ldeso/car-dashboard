#ifndef CLIENT_H
#define CLIENT_H

#include <stdlib.h> // free, malloc, size_t

int create_connected_socket(const char *ip, const int port);
int close_socket(const int fd);
int validate_message(const char* message);
int send_message(int sockfd, const char *message, size_t len);
int receive_message(int sockfd, char *message, size_t len);

#endif // CLIENT_H
