#include"minishell.h"
extern int status;
void n_pipe(char **cmd_with_options,int pipe_count)
{
   
    int count=0;
    int cmd_pos[pipe_count+1];
    cmd_pos[0]=0;

    for(int i=0;cmd_with_options[i];i++)
    {
        if(strcmp(cmd_with_options[i],"|")==0)
        {
            cmd_with_options[i]=NULL;
            count++;
            cmd_pos[count]=i+1;

        }
    }
    if(count==0)
    {
        printf("atleast 1 pipe needed\n");
        return;
    }
    int prev_fd=-1;

    for(int i=0;i<=count;i++)
    {
   int fd[2];

        if(i!=count)
        {
        int ret=pipe(fd);
        if(ret==-1)
        {
            printf("pipe1 failed\n");
            return;
        }
        }
        int pid=fork();
        if(pid==0)
        {
            //child1
	    if(prev_fd != -1)
            {
                dup2(prev_fd, 0);
                close(prev_fd);
            }


	    if(i!=count)
            {
            close(fd[0]);
            dup2(fd[1],1);
	    close(fd[1]);
            }
            execvp(cmd_with_options[cmd_pos[i]],&cmd_with_options[cmd_pos[i]]);
            
        }
        else
        {
	    if(prev_fd != -1)
                close(prev_fd);

            if(i!=count)
            {
		close(fd[1]);
		prev_fd=fd[0];

            }
            

        }
    }
    for(int k=0;k<=count;k++)
    {
	wait(&status);
    }

}

