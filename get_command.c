#include<stdio.h>
#include"minishell.h"
char *get_command(char *input_string)
{
    int len=strlen(input_string);
    char *command=calloc(len+1,sizeof(char));
    if(command==NULL)
    {
        printf("failed\n");
        return NULL;
    }
    int i=0;
    while(input_string[i]!=' ' && input_string[i]!='\0')
    {
        command[i]=input_string[i];
        i++;
    }
    command[i]='\0';
    return command;
}
