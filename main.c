#include <stdio.h>
#include "path_handler.h"
#include "command_executer.h"

/**
 * main - Entry point of the program
 *
 * Contains the main loop of the shell, user handling, and invoking functions
 * from other files based on user commands
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char command[256];

	printf("Enter a command:");
	fgets(command, sizeof(command), stdin);

	handle_path(command);

	return (0);
}
