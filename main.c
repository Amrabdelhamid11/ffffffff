#include "shell.h"

int main(int argc, char **argv)
{

	char *userInput = NULL;
	char **parsedCommand = NULL;
	int executionStatus= 0, i = 0;

	(void)argc;

	while (1)
	{
		userInput = getline();

		if (!userInput)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (stats);
		}
		i++;

		parsedCommand = splitStringIntoTokens(userInput);

		if (!parsedCommand)
		{
			continue;
		}
		if (CheckTheGivenCommandIsBuiltIn(parsedCommand[0]))
		{
			ProcessTheGivenInputFromTheUser(parsedCommand, argv, &stats, i);
		}
		else
		{
			executionStatus= runCommand(parsedCommand, argv, i);
		}
	}
}
