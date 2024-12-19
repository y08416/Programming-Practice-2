#include <stdio.h>
#define MAX 100

void print_stack_ary(char *s, int top);
void push(char c, char *s, int *top);

int main(void)
{
    char s[MAX];
    int top = 4;

    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';

    printf("push-down前:\n");
    print_stack_ary(s, top);

    push('e', s, &top);

    printf("push-down後:\n");
    print_stack_ary(s, top);

    return 0;
}

void print_stack_ary(char *s, int top)
{
    printf("<---TOP=%d\n", top);

    for (int i = top - 1; i >= 0; i--)
    {
        printf("%c\n", s[i]);
    }
}

void push(char c, char *s, int *top)
{
    if (*top < MAX)
    {
        s[*top] = c;
        (*top)++;
    }
    else
    {
        printf("オーバーブローです。\n");
    }
}
 