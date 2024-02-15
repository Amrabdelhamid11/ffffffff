#ifndef MAIN_H
#define MAIN_H

// #include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>



char *read_user_input (void);
void free2DArray(char **array);
int runCommand(char **command, char **argv, int index);
char **splitStringIntoTokens(char *line);
char *matchedEnv (char *variable);
char *path(char *command);
void displayError(char *name, char *parsedCommand, int index);
char *integer_to_string(int number);
void reverseStr(char *str, int length);
int CheckTheGivenCommandIsBuiltIn(char *command);

void ProcessTheGivenInputFromTheUser(char **command, char **argv, int *processStatus, int index);
void terminateShell(char **command, char **argv, int *processStatus, int index);
void displayEnvironmentVariables(char **command, int *processStatus);
int st_to_int(char *str);
int is_numeric_string(char *str);

#define DELIM " \t\n"


extern char **environ;




int count_currentTokens(char *line);
char **allocate_currentTokens_array(int count);
void populate_currentTokens_array(char **command, char *line);


#endif
