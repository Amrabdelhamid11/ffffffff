#include "shell.h"

int runCommand(char **command, char **argv, int index)
{
	char *completeCommandPath;
	pid_t processID;
	int processStatus;

	completeCommandPath = path(command[0]);

	if (!completeCommandPath)
	{
		displayError(argv[0], command[0], index);
		free2DArray(command);
		return (127);
	}
	processID = fork();

	if (processID == 0)
	{
		if (execve(completeCommandPath, command, environ) == -1)
		{
			free(completeCommandPath), completeCommandPath = NULL;
			free2DArray(command);
		}
	}
	else
	{
		waitpid(processID, &processStatus, 0);
		free2DArray(command);
		free(completeCommandPath), completeCommandPath = NULL;
	}
	return (WEXITSTATUS(processStatus));
}
