/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

struct Node *findKthNode(struct Node *head, int k)
{
    int n = 0;
    struct Node *curr = head;

    while (curr)
    {
        curr = curr->next;
        n++;
    }

    if (n >= k)
    {

        curr = head;
        for (int i = 0; i < n - k; i++)
        {
            curr = curr->next;
        }
    }

    return curr;
}

int main(void)
{
    int n;
    cin >> n;

    int keys[n];
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }
    n = sizeof(keys) / sizeof(keys[0]);

    struct Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        push(&head, keys[i]);
    }

    int k;
    cin >> k;
    struct Node *node = findKthNode(head, k);

    if (node)
    {
        printf("k'th node from the end is %d", node->data);
    }

    return 0;
}
