#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"minishell.h"
extern int pid;
extern char input_string[25];
struct node *head=NULL;
int insert_first(struct node **head)
{
    struct node *new=malloc(sizeof(struct node));
    if(new==NULL)
    {
	printf("failed to create list\n");
	return 1;
    }
    new->child_pid=pid;
    strcpy(new->cmd_name,input_string);
    new->link=*head;
    *head=new;
    return 0;

}
int delete_first(struct node **head)
{
    struct node *temp=*head;
    if(*head==NULL)
    {
	printf("list is empty\n");
	return 1;
    }
    *head=temp->link;
    free(temp);
    return 0;
}
void print_list(struct node *head)
{
    struct node *temp=head;
    int job_no=1;
    int status;
    while(temp!=NULL)
    {
	printf("[%d] Stopped %s [%d]\n",job_no, temp->cmd_name,temp->child_pid);
        
    temp=temp->link;
    job_no++;
    }
}

