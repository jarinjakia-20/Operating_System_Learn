#include <stdio.h>
#include <unistd.h>    // for fork, execvp
#include <sys/types.h> // for pid_t
#include <sys/wait.h>  // for wait
#include <stdlib.h>    // for exit()

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // fork failed
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process created. PID = %d\n", getpid());

        // Example: run the "ls -l" command
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        // If execvp returns, it means it failed
        perror("execvp failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent process. PID = %d, waiting for child (PID = %d)\n", getpid(), pid);

        int status;
        waitpid(pid, &status, 0);  // Wait for child to finish

        if (WIFEXITED(status)) {
            printf("Child terminated normally with exit code %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally.\n");
        }
    }

    return 0;
}
