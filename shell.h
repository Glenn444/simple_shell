#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int execute_command(char *command);

#endif
