#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_t
{
    int data;
    struct node_t *prev;
    struct node_t *next;
} node;

node *createNode(int val)
{
    node *new = malloc(sizeof(node));
    assert(new != NULL);
    new->data = val;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

node *addToList(node *head, int val)
{
    node *new = createNode(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    new->next = NULL;

    return head;
}

void printCurrentNode(node *t)
{
    printf("%d", t->data);
}

node *printNextNode(node *t)
{
    if (t->next == NULL)
    {
        printf("Sorry, we have reached the end. The value of last node is\n");
        printf(" %d  ", t->data);
    }
    else
    {
        t = t->next;
        printf("%d  ", t->data);
    }
    return t;
}

node *printPrevNode(node *t)
{
    if (t->prev == NULL)
    {
        printf("Sorry, we have reached the beginning. The value of first node is");
        printf(" %d  \n", t->data);
    }
    else
    {
        t = t->prev;
        printf("%d  ", t->data);
    }
    return t;
}

node *readList(int c)
{
    int x = 0;
    printf("Enter values\n");
    node *head = NULL;
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &x);
        if (head == NULL)
        {
            head = createNode(x);
        }
        else
        {
            addToList(head, x);
        }
    }

    return head;
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int getSize(node *head)
{
    int k = 0;
    node *temp = head;
    while (temp != NULL)
    {
        k += 1;
        temp = temp->next;
    }
    return k;
}

node *playNext(node *head, node *t)
{
    int val = 0;
    printf("Enter value to be searched");
    scanf("%d", &val);
    node *temp = head;
    node *a;
    node *b;
    node *c;
    int k = 0;
    while (temp != NULL)
    {
        k += 1;
        if (temp->data == val)
            break;
        temp = temp->next;
    }
    if (k == getSize(head))
    {
        node *add = createNode(val);
        a = t->next;

        t->next = add;
        add->prev = t;
        if (a != NULL)
        {
            add->next = a;
            a->prev = add;
        }
        else
        {
            add->next = a;
        }
    }
    else
    {
        a = t->next;
        b = temp->next;
        c = temp->prev;

        t->next = temp;
        temp->prev = t;
        temp->next = a;

        if (b == NULL)
        {
            a->prev = temp;
            c->next = b;
        }

        else if (c == NULL)
        {
            head = b;
            a->prev = temp;
            b->prev = c;
        }
        else if (a == NULL)
        {
            c->next = b;
            b->prev = c;
        }
        else
        {
            a->prev = temp;
            c->next = b;
            b->prev = c;
        }
    }
    return t;
}

int *twoSides(node *head, int *l)
{
    node *tail = head;
    node *temph = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *tempt = tail;

    int a = 0;
    int as = 0;
    int b = 0;
    int bs = 0;
    int flag = 0;

    while ((a + b) <= getSize(head))
    {
        if (as <= bs)
        {
            if (flag == 0)
            {
                a += 1;
                as += temph->data;
                temph = temph->next;
                flag = 1;
            }

            else if (flag == 1)
            {
                if (as != bs)
                {

                    a += 1;
                    as += temph->data;
                    temph = temph->next;
                }

                if (as == bs)
                {
                    l[0] = a;
                    l[1] = b;
                    break;
                }
            }
        }

        else
        {
            b += 1;
            bs += tempt->data;
            tempt = tempt->prev;
        }
    }
    return l;
}

int *target(node *head, int *l, int x)
{
    node *tail = head;
    node *temph = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *tempt = tail;

    int a = 1;
    int as = head->data;
    int b = 1;
    int bs = tail->data;

    while ((a + b) <= getSize(head))
    {
        if ((as + bs) <= x)
        {
            if ((as + bs) != x)
            {
                a += 1;
                temph = temph->next;
                as = temph->data;
            }

            if ((as + bs) == x)
            {
                l[0] = a;
                l[1] = (getSize(head) - b + 1);
                break;
            }
        }

        else
        {
            b += 1;
            tempt = tempt->prev;
            bs = tempt->data;
        }
    }
    return l;
}

node *rotate(node *head, int c)
{
    if (c == 0)
    {
        return head;
    }
    else
    {
        node *tail = head;
        node *temph = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        node *a = tail->prev;
        a->next = NULL;
        tail->next = head;
        head->prev = tail;
        tail->prev = NULL;
        head = tail;

        rotate(head, c - 1);
    }
}

node *moveforward(node *t, int c)
{
    for (int i = 0; i < c; i++)
    {
        t = t->next;
    }
    return t;
}

node *moveforward(node *t, int c)
{
    for (int i = 0; i < c; i++)
    {
        t = t->prev;
    }
    return t;
}
node *getTail(node *head)
{
    node *temph = head;
    while (temph->next != NULL)
    {
        temph = temph->next;
    }
    node *tail = temph;
    return tail;
}

int main()
{
    int x = 0;
    node *t;
    int *l = (int *)calloc(2, sizeof(int));
    printf("Enter the number of values to be entered\n");
    scanf("%d", &x);
    node *head = readList(x);
    t = head;
    // printList(head);
    // t = printNextNode(t);
    // t = printNextNode(t);
    // t = printNextNode(t);
    // t = printPrevNode(t);
    // printCurrentNode(t);
    // playNext(head, t);
    // printList(head);
    // playNext(head, t);
    // printList(head);
    head = rotate(head, 3);
    // l[1] = twoSides(head)[1];
    printList(head);
    // printf("%d ", l[0]);
    // printf("%d", l[1]);
}