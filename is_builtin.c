#include "shell.h"

int CheckTheGivenCommandIsBuiltIn(char *command)
{
	
	char *builtinCommands[] = {"exit", "matchedEnv", "setenv", "cd", NULL};

	for (int i = 0; builtinCommands[i]; i++)
	{
		if (strcmp(command, builtinCommands[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

void executeBuiltinCommand(char **command, char **argv, int *processStatus, int index)
{

	if (strcmp(command[0], "exit") == 0)
	{
		terminateShell(command, argv, processStatus, index);
	}
	else if (strcmp(command[0], "matchedEnv") == 0)
	{
		displayEnvironmentVariables(command, processStatus);
	}
}

void terminateShell(char **command, char **argv, int *processStatus, int index)
{
	int exitStatus = (*processStatus);

	char errorMessage[] = ": exit: Illegal number: ";

	char *index;


	if (command[1])
	{
		if (is_numeric_string(command[1]))
		{
			exitStatus = st_to_int(command[1]);
		}
		else
		{
			index = integer_to_string(index);

			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, strlen(index));
			write(STDERR_FILENO, errorMessage, strlen(errorMessage));
			write(STDERR_FILENO, command[1], strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2DArray(command);
			(*processStatus) = 2;
			return;
		}
	}

	free2DArray(command);
	exit(exitStatus);
}

void displayEnvironmentVariables(char **command, int *processStatus)
{

	for (int i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));

		write(STDOUT_FILENO, "\n", 1);

	}

	free2DArray(command);

	(*processStatus) = 0;
}
