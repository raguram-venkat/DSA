
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
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
    printf("\n%d\n", head->data);
    return head;
}
void iprintList(Node *head)
{
    Node *temp = head;
    printf("\n%d\n", head->data);
    while (temp != NULL)
    {
        printf("%d", (temp->data));
        temp = temp->next;
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

int main()
{
    Node *head = readList(5);
    head = swapFrontIndex(head, 2);
    iprintList(head);
    printf("%d", head->data);
}