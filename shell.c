#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT 1024
#define MAX_ARGS 64

int main() {

    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {

        printf("tsh> ");
        fflush(stdout);

        
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            perror("fgets failed");
            continue;
        }

       
        input[strcspn(input, "\n")] = '\0';

       
        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

       
        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            continue;
        }

       
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec failed");
            exit(EXIT_FAILURE);
        }

       
        else {
            wait(NULL);
        }
    }

    return 0;
}
