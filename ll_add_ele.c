#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head, *prev_node = NULL, *last = NULL;

struct Node *create_node(int num)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node -> data = num;
    new_node -> next = NULL;
    if(prev_node == NULL)
    {
        prev_node = (struct Node *) malloc(sizeof(struct Node));
        prev_node = new_node;
    }
    else
    {
        prev_node -> next = new_node;
        prev_node = prev_node -> next;
    }
    return new_node;
}

void show_ll(struct Node *head)
{
    struct Node *x;
    x = head; 
    printf("existing LL - ");
    while (x != NULL)
    {
        printf("%d  \n", x -> data);
        x = x->next;
    }
    
}

int main()
{
    int n, i, ele, pos;
    struct Node *x, *temp, *pre_cur = NULL, *cur, *cur_next;
    printf("enter no of nodes");
    scanf("%d", &n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d", &ele);
        x = create_node(ele);
        if(i==0)
        head = x;
    }
    show_ll(head);
// insert in bw
    // printf("enter position and element");
    // scanf("%d %d", &pos, &ele);
    // x= head;
    // for(i=0;i<pos-1;i++)
    //     x = x ->next;

    // temp = (struct Node *) malloc(sizeof(struct Node));
    // temp ->data = ele;
    // temp ->next = x ->next;
    // x ->next = temp;

    // show_ll(head);
// reverse ll
    
    cur = head;
    while (cur->next != NULL)
    {
        cur_next = cur ->next;
        cur -> next = pre_cur;
        pre_cur = cur;
        cur = cur_next;
    }
    head = cur;
    head ->next = pre_cur;
    
    show_ll(head);
    return 0;
}