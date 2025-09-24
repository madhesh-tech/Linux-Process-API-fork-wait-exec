//C Program to execute Linux system commands using Linux API system calls exec() family
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Required for wait()

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("I am child, my PID is %d\n", getpid());
        printf("My parent PID is: %d\n", getppid());
        sleep(2);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("I am parent, my PID is %d\n", getpid());
        wait(NULL);  //  Waits for child to terminate
        printf("Child process has terminated.\n");
    }

    return 0;
}