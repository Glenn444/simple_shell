#include "shell.h"
/**
* Executes the given command.
* @param command the command to execute
* @return 0 if the command was executed successfully, 1 otherwise
*/
int execute_command(char *command)
{
char *args[2];  /* maximum two arguments: the command and NULL*/
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
args[0] = command;
args[1] = NULL;
execvp(args[0], args);
perror("execvp");  /* handle executable not found*/
return (1);
}
else
{
wait(NULL);  /* wait for child process to exit*/
}

return (0);
}
