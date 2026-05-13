#include<stdio.h>
#include<string.h>
#include"minishell.h"
char *external_commands[154];
int status;
char prompt_name[20]="minishell$ ";
    char input_string[25];
int main()
{

    system("clear");
    extract_external_commands(external_commands);
    scan_input(prompt_name,input_string);


}
     



