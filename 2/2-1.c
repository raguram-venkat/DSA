#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
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
// Function definition goes here
float findMedian(Node *head)
{
    Node *temp = NULL;
    temp = head;
    float c;
    c = getSize(head);
    float d = 0;

    for (int i = 1; i < (c + 1); i++)
    {

        if (i == (c + 1) / 2)
        {
            return temp->data;
        }

        if (i == c / 2)
        {
            d = (float)temp->data;
            temp = temp->next;
            d += ((float)temp->data);
            return d / 2;
        }
        temp = temp->next;
    }
}

int main(void)
{
    // Function calls go here

    Node *head = readList();
    float median = findMedian(head);
    printf("%f\n", median);
    freeList(head);
    return 0;
}