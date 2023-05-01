#include<stdio.h>
#include<stdlib.h>

typedef struct Node_t
{
    int val;
    struct Node_t *prev;
    struct Node_t *next;
}node;

node *createNode(int a)
{
    node *new=(node *)malloc(sizeof(node));
    new->prev=NULL;
    new->next=NULL;
    new->val=a;
    return new;
}

void readList(int n)
{
    int x;
    scanf("%d",&x);
    node *temp=createNode(x);
    node* head=temp;

    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);
        node *new=createNode(x);
        temp->next=new;
        new->prev=temp;
        temp=temp->next;
    }

    return head;

}

int main()
{
    int n;
    scanf("%d",&n);
    node *head=readList(n);
}