#include <stdio.h>
#define MAX 100

void print_stack_ary(char *s, int top);
void push(char c, char *s, int *top);
char pop(char *s, int *top);

int main(void)
{
    char s[MAX];
    int top = 4;

    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';

    printf("push前:\n");
    print_stack_ary(s, top);

    printf("push後:\n");
    push('e', s, &top);
    push('f', s, &top);
    push('g', s, &top);
    print_stack_ary(s, top);

    char popped;
    printf("pop後:\n");
    popped = pop(s, &top);
    printf("popした文字: %c\n", popped);
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
        printf("オーバーフローです。\n");
    }
}

char pop(char *s, int *top)
{
    if (*top > 0)
    {
        char popped = s[--(*top)];
        return popped;
    }
    else
    {
        printf("アンダーフローです。\n");
        return '\0'; // 空のスタックの場合
    }
}
