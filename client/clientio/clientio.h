#ifndef CLIENTIO_H
#define CLIENTIO_H

#include <stdlib.h> // free, malloc, size_t

extern int create_connected_socket(const char *ip, const int port);
extern int close_socket(const int fd);
extern int validate_message(const char* message);
extern int send_message(int sockfd, const char *message, size_t len);
extern int receive_message(int sockfd, char *message, size_t len);

#endif // CLIENTIO_H
