<<<<<<< HEAD
// Process control

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { // child
        printf("Child PID: %d\n", getpid());
        execlp("gedit", "gedit", NULL);  // replace process with gedit
    } else if (pid > 0) { // parent
        wait(NULL);  // wait for child
        printf("Parent PID: %d\n", getpid());
    } else {
        perror("fork failed");
    }

    return 0;
=======
// Process control

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { // child
        printf("Child PID: %d\n", getpid());
        execlp("gedit", "gedit", NULL);  // replace process with gedit
    } else if (pid > 0) { // parent
        wait(NULL);  // wait for child
        printf("Parent PID: %d\n", getpid());
    } else {
        perror("fork failed");
    }

    return 0;
>>>>>>> 4064283b5b0666f210144ca8911aa8d592eddd05
}