#include <stdio.h>
#include <stdlib.h>

// データ要素の構造体
struct data {
    char key;           // キーとして使う文字
    struct data *next;  // 次のデータへのポインタ
};

// キューの構造体
struct queue {
    struct data *top;   // 先頭データを指すポインタ
    struct data *rear;  // 末尾データを指すポインタ
};

// キューのメモリを解放する関数
void freeQueue(struct queue *q) {
    struct data *current = q->top;  // キューの先頭から開始
    while (current != NULL) {
        struct data *temp = current;  // 現在のノードを一時変数に保存
        current = current->next;      // 次のノードに進む
        free(temp);                   // 現在のノードのメモリを解放
    }
    // キューを空にする
    q->top = NULL;
    q->rear = NULL;
}

int main() {
    struct queue q;  // キューの宣言

    // キューの先頭要素を作成
    q.top = (struct data *)malloc(sizeof(struct data));
    if (q.top == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。");
        return 1;  // エラーが発生した場合は1を返す
    }
    q.top->key = 'a';  // 先頭要素のキーを設定
    q.top->next = NULL;
    q.rear = q.top;    // キューの末尾も先頭と同じに設定

    // キューに要素を追加
    q.rear->next = (struct data *)malloc(sizeof(struct data));
    if (q.rear->next == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。");
        free(q.top);  // メモリ解放
        return 1;  // エラーが発生した場合は1を返す
    }
    q.rear = q.rear->next;  // 末尾を新しい要素に更新
    q.rear->key = 'b';      // 新しい要素のキーを設定
    q.rear->next = NULL;

    // もう一つ要素を追加
    q.rear->next = (struct data *)malloc(sizeof(struct data));
    if (q.rear->next == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。");
        freeQueue(&q);  // メモリ解放
        return 1;  // エラーが発生した場合は1を返す
    }
    q.rear = q.rear->next;  // 末尾を新しい要素に更新
    q.rear->key = 'c';      // 新しい要素のキーを設定
    q.rear->next = NULL;

    // キューの中身を表示
    printf("%c\n", q.top->key);        // 先頭要素のキーを表示
    printf("%c\n", q.top->next->key);  // 二番目の要素のキーを表示
    printf("%c\n", q.rear->key);       // 末尾要素のキーを表示

    // メモリ解放
    freeQueue(&q);

    return 0;  
}