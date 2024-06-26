#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "simple_shell "

int _printenv(void);
int cmd_read(char *s, size_t __attribute__((unused)) file_stream, char *name);
char *pathfinder(char *cmd);
void print_not_found(char *cmd, char *name);
int call_command(char *cmd_arr[], char *name);
char *_getenv(char *var);
int execute_command(char *cmd_arr[], char *name);

#endif /* SIMPLE_SHELL_H */
