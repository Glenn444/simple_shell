#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 100
extern char **environ;

void shell(void);
int getNumDigits(int num);
int strngcmp(const char *str1, const char *str2);
size_t strngcspn(const char *str, const char *reject);
size_t strlength(const char *str);
char *strngcpy(char *dest, const char *src);
char *strngdup(const char *str);
char **tokenize(char *command, char *delim);
char *getenv_custom(const char *name);
char *concatenate(const char *str1, const char *str2);
char *find_file(char *filename, char *path);
char *concatenateArguments(char **argv);
void freeMem(char **ag1, char *arg2, char **arg3, char *command);

#endif
