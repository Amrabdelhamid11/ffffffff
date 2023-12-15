#include "shell.h"

char *duplicateString(char *str)
{
	char *newString;
	int len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	/* 	while (*str != '\0')
		{
			len++;
			str++;
		} */
	while (str[len])
	{
		len++;
	}

	newString = malloc(sizeof(char) * (len + 1));
	if (newString == NULL)
	{
		return (NULL);
	}
	for (int i = 0; i <= len; i++)
	{
		newString[i] = str[i];
	}
	return (newString);
}

int compareStrings(char *str1, char *str2)
{
	int comparisonResult;

	comparisonResult = (int)*str1 - (int)*str2;
	while (*str1)
	{
		if (*str1 != *str2)
		{
			break;
		}
		str1++;
		str2++;
		comparisonResult = (int)*str1 - (int)*str2;
	}
	return (comparisonResult);
}

int stringLength(char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}

char *concatenateStrings(char *dest, char *src)
{
	char *destPtr = dest;

	while (*destPtr)
	{
		destPtr++;
	}
	while (*src)
	{
		*destPtr = *src;
		destPtr++;
		src++;
	}
	*destPtr = '\0';
	return (dest);
}

char *copyString(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
