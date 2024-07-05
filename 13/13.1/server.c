#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCK_PATH "/tmp/mysocket"

int main() {
    int serv_sock, cl_sock;
    socklen_t len;
    struct sockaddr_un server, client;
    char buf[100];

    serv_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCK_PATH);
    unlink(server.sun_path);
    bind(serv_sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));
    listen(serv_sock, 5);

    len = sizeof(struct sockaddr_un);
    cl_sock = accept(serv_sock, (struct sockaddr *) &client, &len);

    read(cl_sock, buf, sizeof(buf));
    printf("Received: %sn", buf);

    close(cl_sock);
    close(serv_sock);

    return 0;
}