#include <stdio.h>
#define MAX 100

void print_queue_ary(char *q, int top, int rear);
void enqueue(char c, char *q, int *top, int *rear);
char dequeue(char *q, int *top, int *rear);

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

    printf("enqueue後:\n");
    enqueue('e', q, &top, &rear);
    enqueue('f', q, &top, &rear);
    enqueue('g', q, &top, &rear);
    print_queue_ary(q, top, rear);

    char dequed;
    printf("dequeue後:\n");
    dequed = dequeue(q, &top,  &rear);
    printf("dequeueした文字: %c\n", dequed);
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
    printf("%c<---REAR=%d\n", q[rear], rear);
}

void enqueue(char c, char *q, int *top, int *rear)
{
    if (*rear == MAX) {
        printf("キューが満杯です\n");
        return;
    }
    q[*rear] = c;
    (*rear)++;
}

char dequeue(char *q, int *top, int *rear)
{
    if (*top == *rear) {
        printf("キューは空です\n");
        return '\0'; // キューが空の場合はヌル文字を返す
    }
    char dequed = q[*top];
    (*top)++;
    return dequed;
}
