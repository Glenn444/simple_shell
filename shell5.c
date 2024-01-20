#include "shell.h"
int main(void) {
    extern char **environ;

    while (1) {
        printf("$ ");
        char command[100];
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "env\n") == 0) {
            char** env_var = environ;
            while (*env_var != NULL) {
                printf("%s\n", *env_var);
                env_var++;
            }
        } else if (strcmp(command, "exit\n") == 0) {
            break;
        } else {
            // Execute other commands
            // ...
        }
    }

    return 0;
}
