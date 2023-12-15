#include "shell.h"

char *matchedEnv (char *variable)
{
	char *tempLine, *envKey, *value, *matchedEnv;

	for (int i = 0; environ[i]; i++)
	{
		tempLine = strdup(environ[i]);

		envKey = strtok(tempLine, "=");

		if (strcmp(envKey, variable) == 0)
		{
			envValue= strtok(NULL, "\n");

			matchedEnv = strdup(value);

			free(tempLine);

			return (matchedEnv);

		}
		free(tempLine);

		tempLine = NULL;
		
	}
	return (NULL);
}
