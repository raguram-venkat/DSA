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

node * readList(int n)
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

void printList(node *head)
{
    node *temp=head;
    while(temp)
    {
        printf("%d",temp->val);
        temp=temp->next;
    }
}

node *playNext(node *head,int x,node *cur)
{
    int flag=0;
    node *temp=head;
    node *xp;
    while(temp)
    {
        if(temp->val==x)
        {
            xp=temp;
            flag=1;
            break;
        }
        temp=temp->next;
    }

    if(flag==0)
    {
        xp=createNode(x);
        temp=cur->next;
        cur->next=xp;
        xp->prev=cur;
        //printf("%d",temp->val);
        if(temp!=NULL)
        {
            //printf("HI");
            xp->next=temp;
            temp->prev=xp;
        }
        return head;
    }

    else
    {
        if(xp==head)
        {
            head=head->next;
            temp=cur->next;
            cur->next=xp;
            xp->prev=cur;
            if(temp)
            {
                xp->next=temp;
                temp->prev=xp;
            }
            return head;
        }

        node *temp_prev=xp->prev;
        node *temp_next=xp->next;
        temp_prev->next=temp_next;
        if(temp_next)
        temp_next->prev=temp_prev;
        temp=cur->next;
        cur->next=xp;
        xp->prev=cur;
        if(temp)
        {
            xp->next=temp;
            temp->prev=xp;
        }
        return head;

    }
}

int main()
{
    int n;
    scanf("%d",&n);
    node *head=readList(n);
    //printList(head);
    node *temp=head;
    temp=temp->next->next;
    head=playNext(head,6,temp);
    printList(head);
}