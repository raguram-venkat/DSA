#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

Node *createNode(int value)
{
    Node *head = (Node *)malloc(sizeof(Node));
    assert(head != NULL);
    head->data = value;
    head->next = NULL;
    return head;
}

Node *addToList(Node *head, int value)
{
    Node *temp = head;
    while ((temp->next) != NULL)
    {
        temp = temp->next;
    }
    Node *new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = value;
    new->next = NULL;
    temp->next = new;
    return head;
}
void iprintList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", (temp->data));
        temp = temp->next;
    }
}
void sprintList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        puts(temp->data);
        temp = temp->next;
    }
}

int getSize(Node *head)
{
    int c = 0;
    Node *temp = NULL;
    temp = head;
    while ((temp) != NULL)
    {
        temp = temp->next;
        c += 1;
    }
    return c;
}

Node *readList(int c)
{
    int x;
    printf("Enter values");
    scanf("%d", &x);
    Node *head = createNode(x);
    for (int i = 0; i < c - 1; i++)
    {
        scanf("%d", &x);
        addToList(head, x);
    }
    return head;
}

void freeList(Node *head)
{
    Node *cur = head;
    Node *temp;
    while ((cur) != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
}
Node *swapFrontIndex(Node *head, int i)
{
    int n = 0;
    Node *temp;
    Node *a;
    Node *b;
    temp = head;
    for (int k = 0; k < i - 1; k++)
    {
        temp = temp->next;
    }
    a = temp->next;
    temp->next = a->next;
    b = a->next;
    a->next = (b->next);
    b = (temp->next);
    (b->next) = a;
    return head;
}
Node *swapBackIndex(Node *head, int i)
{
    Node *temp = swapFrontIndex(head, i - 1);
    return temp;
}
int main()
{
    Node *head = readList(5);
    head = swapFrontIndex(head, 2);
    iprintList(head);
}