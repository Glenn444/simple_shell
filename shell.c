#include "shell.h"
/**
* main: Takes void and returns 0
* Return: returns 0
*/
int main(void)
{
char buffer[256];

while (1)
{
printf("$ ");  /* display the prompt */
fflush(stdout);

if (fgets(buffer, sizeof(buffer), stdin) == NULL)
{
printf("\n");  /* handle Ctrl+D*/
exit(0);
}

if (buffer[0] == '\n')
continue;  /* empty command, prompt again*/

buffer[strcspn(buffer, "\n")] = '\0';  /* remove newline character*/

if (execute_command(buffer) != 0)
{
fprintf(stderr, "Failed to execute command: %s\n", buffer);
}
}

return (0);
}
