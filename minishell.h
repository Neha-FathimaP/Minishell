#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
 

#define BUILTIN		1
#define EXTERNAL	2
#define NO_COMMAND  3

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct node
{
    int child_pid;
    char cmd_name[20];
    struct node *link;
};
extern int pid;
extern int status;
extern struct node *head;
void scan_input(char *prompt_name, char *input_string);
char *get_command(char *input_string);
int check_command_type(char *command);
void execute_internal_commands(char *input_string);
void execute_external_commands(char *input_string);
void extract_external_commands(char **external_commands);
int pipe_count(char *input_string);
void n_pipe(char **cmd_with_options,int pipe_count);
int insert_first(struct node **head);
void print_list(struct node *head);
int delete_first(struct node **head);
//void copy_change(char *prompt, char *input_string);

//void echo(char *input_string, int status);
void signal_handler(int sig_num);

#endif
