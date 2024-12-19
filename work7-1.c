#include <stdio.h>
#define MAX 100
void print_queue_ary(char *q, int top, int rear);

int main()
{
    char q[MAX];
    int top = 3, rear = 7;
    q[3] = 'a';
    q[4] = 'b';
    q[5] = 'c';
    q[6] = 'd';

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