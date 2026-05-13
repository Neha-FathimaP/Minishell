#include"minishell.h"
extern char prompt_name[20];
extern int pid;
extern struct node *head;
extern int status;
void signal_handler(int signum)
{
    if(signum==SIGINT)
    {
	if(pid==0)
	{
	printf("\n%s",prompt_name);
	fflush(stdout);
	}
	else if(pid!=0)
	{
	    kill(pid,SIGINT);
	}
    }
    else if(signum == SIGTSTP)
    {
	if(pid==0)
	{
        printf("\n%s", prompt_name);
	fflush(stdout);
	    
	}
	else
	{
	    
        insert_first(&head);  

        printf("\n[%d]+ Stopped %s\n", 1, head->cmd_name);
//	printf("%s", prompt_name);
        fflush(stdout);
	}
    }
   
    else if(signum==SIGCHLD)
{
    while(waitpid(-1, &status, WNOHANG) > 0);
}

}


