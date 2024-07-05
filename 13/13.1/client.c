#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>

#define SOCK_PATH "/tmp/mysocket"

int main() {
    int sock;
    struct sockaddr_un server;
    char buf[100];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCK_PATH);
    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)) == -1) {
        perror("connect error");
        exit(1);
    }

    printf("Enter the message to send: ");
    fgets(buf, sizeof(buf), stdin);
    write(sock, buf, sizeof(buf));

    close(sock);

    return 0
}