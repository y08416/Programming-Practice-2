#include <stdio.h>
#include <stdlib.h>

// スタックのノードを表す構造体を定義
struct data {
    char key;            // ノードに格納される文字
    struct data *next;   // スタック内の次のノードへのポインタ
};

// スタック内のキーを表示する関数
void print_stack_list(struct data *top) {
    printf("<---TOP\n");
    struct data *current = top;  // currentポインタをスタックの先頭に初期化
    while (current != NULL) {    // currentがNULLになるまでスタックを反復するループ
        printf("%c\n", current->key);  // 現在のノードのキーを表示
        current = current->next;       // currentをスタック内の次のノードに更新
    }
}

void push(struct data **top, char key) {
    struct data *new_node = (struct data *)malloc(sizeof(struct data)); // 新しいノードのメモリを確保
    if (new_node == NULL) {  // メモリ確保が成功したかどうかをチェック
        printf("メモリを確保できませんでした。\n"); // メモリ確保に失敗した場合、エラーメッセージを表示
        return;
    }
    new_node->key = key;     // 新しいノードのキーを設定
    new_node->next = *top;   // 新しいノードを現在のスタックの先頭にリンク
    *top = new_node;         // スタックの先頭を新しいノードに更新
}

int main() {
    struct data *top = NULL;  // スタックの先頭をNULLに初期化

    // push関数を使用してスタックに要素を追加し、print_stack_list関数でスタックの内容を表示
    push(&top, 'a');
    print_stack_list(top);
    
    push(&top, 'b');
    print_stack_list(top);
    
    push(&top, 'c');
    print_stack_list(top);

    // スタックのメモリを解放
    while (top != NULL) {
        struct data *temp = top;  // 現在の先頭ノードを一時変数に保存
        top = top->next;          // スタックの先頭を次のノードに更新
        free(temp);               // 古い先頭ノードのメモリを解放
    }

    return 0;  
}
