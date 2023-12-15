#include "shell.h"

char **splitStringIntoTokens(char *line)
{
	char *currentToken= NULL, *tempLine = NULL;
	char **command = NULL;
	int currentTokenCount= 0, i = 0;

	if (!line)
	{
		return (NULL);
	}
	tempLine = strdup(line);
	currentToken= strtok(tempLine, DELIM);
	if (currentToken== NULL)
	{
		free(line), line = NULL;

		free(tempLine), tempLine = NULL;

		return (NULL);
	}
	while (currentToken)
	{
		currentTokenCount++;

		currentToken= strtok(NULL, DELIM);

	}
	free(tempLine), tempLine = NULL;

	command = malloc(sizeof(char *) * (currentTokenCount+ 1));

	if (!command)
	{
		free(line);

		return (NULL);

	}

	currentToken= strtok(line, DELIM);

	while (currentToken)
	{

		command[i] = strdup(currentToken);


		currentToken= strtok(NULL, DELIM);


		i++;
	}
	free(line), line = NULL;

	command[i] = NULL;
	
	return (command);
}
