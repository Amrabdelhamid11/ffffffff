#include "shell.h"

void free2DArray(char **array)
{
	int i;

	if (!array)
	{
		return;
	}
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}

void displayError(char *name, char *parsedCommand, int index)
{
	char *index, errorMessage[] = ": not found\n";

	index = integer_to_string(index);

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, parsedCommand, strlen(parsedCommand));
	write(STDERR_FILENO, errorMessage, strlen(errorMessage));

	free(index);
}

char *integer_to_string(int number)
{
	char numBuffer[20];
	int i = 0;

	if (number == 0)
	{
		numBuffer[i++] = '0';
	}
	else
	{
		while (number > 0)
		{
			numBuffer[i++] = (number % 10) + '0';
			number /= 10;
		}
	}

	numBuffer[i] = '\0';

	reverseStr(numBuffer, i);
	return (strdup(numBuffer));
}

void reverseStr(char *str, int length)
{
	char tempChar;
	int startIndex = 0;
	int endIndex = length - 1;
	while (startIndex < endIndex)
	{
		tempChar = str[startIndex];
		str[startIndex] = str[endIndex];
		str[endIndex] = tempChar;
		startIndex++;
		endIndex--;
	}
}

int st_to_int(char *str)
{
	int num = 0;

	for (int i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

int is_numeric_string(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}