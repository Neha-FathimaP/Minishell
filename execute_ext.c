
#include<stdio.h>
#include"minishell.h"
void execute_external_commands(char *input_string)
{
    //convert 1d array i/p into 2d array i/p
    int len=strlen(input_string);
    char *cmd_with_options[len];
    char buffer[30];
    int i=0;
    int j=0;
    int k=0;
    while(input_string[i])
    {
	if(input_string[i]!=' ')
	{
	    buffer[j]=input_string[i];
	    i++;
	    j++;
	}
	else
	{
	    buffer[j]='\0';
	    cmd_with_options[k]=calloc(strlen(input_string),sizeof(char));
	    strcpy(cmd_with_options[k],buffer);
	    k++;
	    j=0;
	    i++;

	}
    }
    buffer[j]='\0';
    cmd_with_options[k]=calloc(strlen(input_string),sizeof(char));
    strcpy(cmd_with_options[k],buffer);
    k++;
    cmd_with_options[k]=NULL;
    int pcount=pipe_count(input_string);
    if(pcount>0)
	n_pipe(cmd_with_options,pcount);
    else
    {
	//execute single cmd
	
	    execvp(cmd_with_options[0],cmd_with_options);
    }
	
}


    
    int pipe_count(char *input_string)
    {
	int count=0;
	for(int i=0;input_string[i];i++)
	{
	    if(input_string[i]=='|')
		count++;
	}
	return count;

    }
