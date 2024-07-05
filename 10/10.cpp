#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent process is runningn");
        sleep(10);
    } else if (pid == 0) {
        printf("Child process is runningn");
        exit(0);
    } else {
        perror("fork");
        exit(1);
    }

    return(0);
}