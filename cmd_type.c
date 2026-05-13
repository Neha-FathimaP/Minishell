/*List obuiltin commands*/
#include<stdio.h>
#include"minishell.h"
#include<string.h>
	char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
			"set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
			"exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help","fg","bg","jobs", NULL};
extern char *external_commands[];
int check_command_type(char *command)
{
    //check builtin
    for(int i=0;builtins[i];i++)
    {
	if(strcmp(command,builtins[i])==0)
	{
	    return BUILTIN;
	}
    }
    for(int i=0;external_commands[i];i++)
    {
	if(strcmp(command,external_commands[i])==0)
	{
	    return EXTERNAL;
	}
    }
    return NO_COMMAND;
}

