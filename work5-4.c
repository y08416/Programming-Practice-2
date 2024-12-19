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

// キューの内容を表示する関数
void print_queue_list(struct queue q) {
    struct data *current = q.top;  // キューの先頭から開始
    if (current == NULL) {  // キューが空かどうかを確認
        printf("キューは空です。\n");
        return;
    }
    while (current != NULL) {  // 現在のノードがNULLになるまでループ
        if (current == q.top) {  // 現在のノードがキューの先頭かどうかをチェック
            printf("%c<---TOP\n", current->key);
        } else if (current == q.rear) {  // 現在のノードがキューの末尾かどうかをチェック
            printf("%c<---REAR\n", current->key);
        } else {  // その他のノードのキーを表示
            printf("%c\n", current->key);
        }
        current = current->next;  // 次のノードに進む
    }
}

int main() {
    struct queue q;  // キューの宣言

    // キューの先頭要素を作成
    q.top = (struct data *)malloc(sizeof(struct data));  // メモリを確保
    if (q.top == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。\n");
        return 1;  // エラーが発生した場合は1を返す
    }
    q.top->key = 'a';  // 先頭要素のキーを設定
    q.top->next = NULL;  // 次の要素をNULLに設定
    q.rear = q.top;    // キューの末尾も先頭と同じに設定

    // キューに要素を追加
    q.rear->next = (struct data *)malloc(sizeof(struct data));  // 新しい要素のメモリを確保
    if (q.rear->next == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。\n");
        free(q.top);  // メモリ解放
        return 1;  // エラーが発生した場合は1を返す
    }
    q.rear = q.rear->next;  // 末尾を新しい要素に更新
    q.rear->key = 'b';      // 新しい要素のキーを設定
    q.rear->next = NULL;    // 新しい要素の次の要素をNULLに設定

    // もう一つ要素を追加
    q.rear->next = (struct data *)malloc(sizeof(struct data));  // 新しい要素のメモリを確保
    if (q.rear->next == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。\n");
        freeQueue(&q);  // メモリ解放
        return 1;  // エラーが発生した場合は1を返す
    }
    q.rear = q.rear->next;  // 末尾を新しい要素に更新
    q.rear->key = 'c';      // 新しい要素のキーを設定
    q.rear->next = NULL;    // 新しい要素の次の要素をNULLに設定

    // さらにもう一つ要素を追加
    q.rear->next = (struct data *)malloc(sizeof(struct data));  // 新しい要素のメモリを確保
    if (q.rear->next == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。\n");
        freeQueue(&q);  // メモリ解放
        return 1;  // エラーが発生した場合は1を返す
    }
    q.rear = q.rear->next;  // 末尾を新しい要素に更新
    q.rear->key = 'd';      // 新しい要素のキーを設定
    q.rear->next = NULL;    // 新しい要素の次の要素をNULLに設定

    // キューの中身を表示
    print_queue_list(q);

    // メモリ解放
    freeQueue(&q);

    return 0;  // 正常終了を示すために0を返す
}
