#include"minishell.h"
extern int status;
extern struct node *head;
extern int pid;

void execute_internal_commands(char *input_string)
{
    //if->input_stirng is 'exit'
    //call exit fn
    if(strcmp(input_string,"exit")==0)
    {
	exit(0);
    }
    else if(strcmp(input_string,"pwd")==0)
    {
	//if input_stirng is 'pwd'
	char path[50];
	getcwd(path,sizeof(path));
	printf("%s\\n",path);
    }
    else if(strncmp(input_string,"cd",2)==0)
    {
	//if->input_string is 'cd'
	chdir(input_string+3);
    }
    else if(strcmp(input_string,"echo $$")==0)
    {
	//if i/p string is 'echo $$'
	printf("%d\\n",getpid());
    }
    else if(strcmp(input_string,"echo $?")==0)
    {
	//if i.p is 'echo $?'
	if(WIFEXITED(status))
	    printf("%d\\n",WEXITSTATUS(status));
    }
    else if(strcmp(input_string,"echo $SHELL")==0)
    {
	//if->'echo $SHELL'
	printf("%s\\n",getenv("SHELL"));
    }
    else if(strcmp(input_string,"jobs")==0)
    {
	if(head==NULL)
	{
	    printf("no jobs\n");
	    return;
	}
	print_list(head);
    }
    else if(strcmp(input_string,"fg")==0)
    {
	if(head==NULL)
	{
	    printf("no jobs\n");
	    return;
	}
	printf("%s\n",head->cmd_name);

	kill(head->child_pid,SIGCONT);
	waitpid(head->child_pid,&status,0);

	    delete_first(&head);

    }
    else if(strcmp(input_string,"bg")==0)
    {
	if(head == NULL)
	{
	    printf("No jobs\n");
	    return;
	}
	printf("[%d]+ Running %s &\n",1,head->cmd_name);
	kill(head->child_pid,SIGCONT);
    }

    else
	printf("invalid builtin cmd\\n");




}

