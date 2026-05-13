#include<stdio.h>
#include<string.h>
#include"minishell.h"
void extract_external_commands(char **external_commands)
{
    int fd=open("ext_cmd.txt",O_RDONLY);
    if(fd==-1)
    {
        printf("open failed\n");
        return;
    }
    char cmd[20];
    char ch;
    int i=0;
    int ret;
    int row=0;
    //read char  by char upto newline and store in cmd array
    
    while((ret=read(fd,&ch,1))!=0)
    {
	if(ch!='\n')
	{
	    cmd[i]=ch;
	    i++;
	}
	else
	{
	    cmd[i]='\0';
	   
	    external_commands[row] = malloc((strlen(cmd)+1)*sizeof(char));
	    strcpy(external_commands[row], cmd);
	   // printf("Loaded command: %s\n", external_commands[row]);
	    row++;
	    i=0;
	}


    }
if(i > 0)
{
    cmd[i] = '\0';
    external_commands[row] = malloc(strlen(cmd)+1);
    strcpy(external_commands[row], cmd);
    row++;
}
    external_commands[row] = NULL; 
   //printf("Total commands loaded: %d\n", row);
    close(fd);


}
