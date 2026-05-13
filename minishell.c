#include<stdio.h>
#include<string.h>
#include"minishell.h"
char *external_commands[154];
int status;
char prompt_name[20]="minishell$ ";
    char input_string[25];
int main()
{
    /*
       1.clear the screen
       2.display prompt name
       3.initialize input
       4.read input using function call
       */
    system("clear");
    extract_external_commands(external_commands);
    scan_input(prompt_name,input_string);


}
     



