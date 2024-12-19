#include <stdio.h>
int main()
{
    char *p1, *p2;
    p2 = "Winter";
    p1 = p2;

    while (*p1 != '\0')
    {
        p1++; // 文字列の最後を検索
    }

    while (p1 != p2)
    { // アドレスを比較
        p1--;
        putchar(*p1); // アドレスを制御して文字を１つずつ出力
    }

    putchar('\n');
    return 0;
}
