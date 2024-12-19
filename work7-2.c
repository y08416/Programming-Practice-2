#include <stdio.h>
#define MAX 100
void print_queue_ary(char *q, int top, int rear);
void enqueue(char c, char *q, int *top, int *rear);

int main()
{
    char q[MAX];
    int top = 3, rear = 7;
    q[3] = 'a';
    q[4] = 'b';
    q[5] = 'c';
    q[6] = 'd';

    printf("enqueue前:\n");
    print_queue_ary(q, top, rear);

    enqueue('e', q, &top, &rear);

    printf("enqueue後:\n");
    print_queue_ary(q, top, rear);

    return 0;
}

void print_queue_ary(char *q, int top, int rear)
{
    printf("%c<---TOP=%d\n", q[top], top);
    for (int i = top + 1; i <= rear-1; i++)
    {
        printf("%c\n", q[i]);
    }
    printf("%c<---REAR=%d\n", q[rear],rear);
}

void enqueue(char c, char *q, int *top, int *rear){
    q[*rear] = c;
    (*rear)++;

}