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

// キューに要素を追加する関数
void enqueue(struct queue *q, char key) {
    struct data *new_data = (struct data *)malloc(sizeof(struct data));  // 新しい要素のメモリを確保
    if (new_data == NULL) {  // メモリ確保が成功したかを確認
        printf("メモリを確保できませんでした。\n");
        return;
    }
    new_data->key = key;  // 新しい要素のキーを設定
    new_data->next = NULL;  // 新しい要素の次の要素をNULLに設定
    
    if (q->rear == NULL) {  // キューが空の場合
        q->top = new_data;  // 新しい要素を先頭に設定
        q->rear = new_data;  // 新しい要素を末尾に設定
    } else {
        q->rear->next = new_data;  // 末尾の次の要素を新しい要素に設定
        q->rear = new_data;  // 末尾を新しい要素に更新
    }
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
    q.top = NULL;    // キューの先頭をNULLに初期化
    q.rear = NULL;   // キューの末尾をNULLに初期化

    // enqueue 関数のテスト
    enqueue(&q, 'a');
    print_queue_list(q);

    enqueue(&q, 'b');
    print_queue_list(q);

    enqueue(&q, 'c');
    print_queue_list(q);

    // メモリ解放
    freeQueue(&q);

    return 0;  // 正常終了を示すために0を返す
}
