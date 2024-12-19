#include <stdio.h>
#include <stdlib.h>

struct data
{
    char key;
    struct data *next;
};

int main()
{
    // リンクリストの先頭ポインタを初期化
    struct data *top = NULL;

    // メモリを確保して先頭ノードを作成
    top = (struct data *)malloc(sizeof(struct data));
    if (top == NULL)
    {
        printf("メモリを確保できませんでした。");
        return 1;
    }
    top->key = 'a';
    top->next = NULL;

    // 次のノードを作成
    top->next = (struct data *)malloc(sizeof(struct data));
    if (top->next == NULL)
    {
        printf("メモリを確保できませんでした。");
        return 1;
    }
    top->next->key = 'b';
    top->next->next = NULL;

    // さらに次のノードを作成
    top->next->next = (struct data *)malloc(sizeof(struct data));
    if (top->next->next == NULL)
    {
        printf("メモリを確保できませんでした。");
        return 1;
    }
    top->next->next->key = 'c';
    top->next->next->next = NULL;

    // リンクリストの各ノードの key 値を出力
    printf("%c\n", top->key);
    printf("%c\n", top->next->key);
    printf("%c\n", top->next->next->key);

    // メモリを解放してリソースを解放
    free(top->next->next);
    free(top->next);
    free(top);

    return 0;
}
