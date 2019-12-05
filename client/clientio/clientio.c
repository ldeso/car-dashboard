#include <arpa/inet.h> // connect, htons, inet_pton, send, socket, recv
#include <string.h> // memset, strncpy, strlen, strncmp, strtok
#include <unistd.h> // close

#include "clientio.h"

int create_connected_socket(const char *ip, const int port)
{
    int fd;
    if ((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        return -1;
    struct sockaddr_in address;
    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);
    address.sin_port = htons((uint16_t) port);
    if (connect(fd, (struct sockaddr *) &address, sizeof(address)) == -1)
        return -1;
    return fd;
}

int close_socket(const int fd)
{
    return close(fd);
}

int validate_message(const char* message)
{
    size_t len = strlen(message) + 1;
    char *buf = malloc(len);
    strncpy(buf, message, len);
    char *commands[] = {
        "BATTERY_LIGHT",
        "DASHBOARD",
        "GAZ",
        "LIGHT",
        "RPM",
        "SPEED",
        "SPEED_LIMIT",
        "TURN",
        "WARNING",
        "ASD",
        "MODE",
        "FRONT_FOG",
        "REAR_FOG",
        "SEAT_BELT",
        "RW_HEAT",
        "CHECK_ENGINE",
        "ACCELERATION",
        "OPEN_DOOR_DRIVER",
        "OPEN_DOOR_FRONT_PASSENGER",
        "OPEN_DOOR_BACK_L_PASSENGER",
        "OPEN_DOOR_BACK_R_PASSENGER",
        "ADAPT_CRUISE_CONTROL",
        "AIRBAG_ON",
        "BONNET_OPEN",
        "BOOT_OPEN",
        "CRUISE_CONTROL_ON",
        "ENGINE_T",
        "OIL_T",
        "OIL_L",
        "SIM"
    };
    size_t ncommands = sizeof(commands) / sizeof(*commands);
    int result = -1;
    char *first, *second;
    if ((first = strtok(buf, " ")) != NULL)
        if ((second = strtok(NULL, " ")) != NULL)
            if (strncmp(first, "CANN", len) == 0)
                for (size_t i = 0; i < ncommands; ++i)
                    if (strncmp(second, commands[i], len) == 0)
                        result = 0;
    free(buf);
    return result;
}

int send_message(int sockfd, const char *message, size_t len)
{
    return (int) send(sockfd, message, len, 0);
}

int receive_message(int sockfd, char *message, size_t len)
{
    return (int) recv(sockfd, message, len, 0);
}
