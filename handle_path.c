#include "shell.h"

/**
 * path - Gets the path of a command
 * Return: The path
 * --------------------------
 * Prototype: char *path(char *command);
 * --------------------------
 * @command: The command
 * --------------------------
 */
char *path(char *command){

	char *pathEnvironment, *completeCommandPath, *directory;


	struct stat fileStat;




	for (int i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &fileStat) == 0)
			{
				return (strdup(command));
			}
			return (NULL);
		}
	}



	pathEnvironment = matchedEnv("PATH");

	if (!pathEnvironment){
		return (NULL);
	}


	directory = strtok(pathEnvironment, ":");
	while (directory){

		completeCommandPath = malloc(strlen(directory) + strlen(command) + 2);
		if (completeCommandPath)
		{
			strcpy(completeCommandPath, directory);

			concatenateStrings(completeCommandPath, "/");

			concatenateStrings(completeCommandPath, command);

			if (stat(completeCommandPath, &fileStat) == 0){
				
				free(pathEnvironment);
				return (completeCommandPath);
			}

			free(completeCommandPath);
			completeCommandPath = NULL;

			directory = strtok(NULL, ":");
		}
	}


	free(pathEnvironment);
	return (NULL);
}
