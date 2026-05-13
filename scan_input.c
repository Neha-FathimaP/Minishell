#include<stdio.h>
#include<string.h>
#include"minishell.h"
extern int status;
int pid;
extern struct node *head;
void scan_input(char *prompt_name,char *input_string)
{
    signal(SIGINT,signal_handler);
    signal(SIGTSTP,signal_handler);
    signal(SIGCHLD,signal_handler);
    while(1)
    {
    //print prompt name
    printf("%s",prompt_name);
    //read input string
    scanf(" %[^\n]",input_string);
    int ret=strncmp(input_string,"PS1=",3);
    if(ret==0)
    {
        if(input_string[4]!=' ')
        {

            strcpy(prompt_name,input_string+4);
        memset(input_string,0,25);
        }

        else

            printf("error:invalid command\n");
    }
    else
    {
       char *cmd=get_command(input_string);
       int type=check_command_type(cmd);
       if(type==BUILTIN)
       {
	   printf("builtin cmd\n");
	   execute_internal_commands(input_string);
       }
       else if(type==EXTERNAL)
       {
	   printf("external cmd\n");
	   pid=fork();
	   if(pid==-1)
	   {
	       printf("fork failed\n");
	       return;
	   }
	   if(pid==0)
	   {
	       //child
	       signal(SIGINT,SIG_DFL);
	       signal(SIGTSTP,SIG_DFL);
	       execute_external_commands(input_string);
	   }
	   else
	   {
	       //parent

	       waitpid(pid,&status,WUNTRACED);
	     
	       
	   }
       }
       else
	   printf("no cmd\n");
       
       
    }

    }
}

