#include <stdio.h>
#include <stdlib.h>

// 2つの整数の値を交換する関数
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// ヒープ構造を維持するための関数
void heapify(int ary[], int n, int i) {
    int smallest = i;   // 最小値のインデックスを仮にiに設定
    int left = 2 * i + 1;  // 左の子ノードのインデックス
    int right = 2 * i + 2; // 右の子ノードのインデックス
    
    // 左の子ノードが存在し、かつ左の子ノードの値が現在の最小値より小さい場合
    if (left < n && ary[left] < ary[smallest])
        smallest = left;

    // 右の子ノードが存在し、かつ右の子ノードの値が現在の最小値より小さい場合
    if (right < n && ary[right] < ary[smallest])
        smallest = right;

    // 最小値が根ノードではない場合、値を交換し再帰的にheapifyを呼び出す
    if (smallest != i) {
        swap(&ary[i], &ary[smallest]);
        heapify(ary, n, smallest);
    }
}

// 配列をヒープに構築する関数
void buildMinHeap(int ary[], int n) {
    // 最後の非葉ノードからheapifyを呼び出す
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(ary, n, i);
    }
}

// 配列の内容を出力する関数
void printArray(int ary[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}

// ヒープ条件を満たしているか確認する関数
int check_heap(int a[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2 * i + 1 < n && a[i] > a[2 * i + 1]) // 左の子ノードがヒープ条件を満たしているか
            return 0;
        if (2 * i + 2 < n && a[i] > a[2 * i + 2]) // 右の子ノードがヒープ条件を満たしているか
            return 0;
    }
    return 1;
}

// ヒープに新たなデータを挿入する関数
void insert(int val, int a[], int *n) {
    a[*n] = val; // 新しい値を配列の末尾に追加
    int i = *n;
    (*n)++;

    // 親ノードと比較しながらヒープ条件を満たすように調整
    while (i != 0 && a[(i - 1) / 2] > a[i]) {
        swap(&a[i], &a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main(void) {
    int initialSize = 10; // 初期配列サイズ
    int *ary = (int *)malloc(initialSize * sizeof(int)); // 動的メモリ確保
    if (ary == NULL) {
        perror("メモリの確保に失敗しました。"); // メモリ確保エラー
        return EXIT_FAILURE;
    }

    int n = 0; // 現在の配列要素数

    // ヒープにデータを挿入
    insert(3, ary, &n);
    insert(1, ary, &n);
    insert(6, ary, &n);
    insert(5, ary, &n);
    insert(2, ary, &n);
    insert(4, ary, &n);

    printArray(ary, n); // ヒープの内容を出力

    // check_heap関数を呼び出してヒープ条件を満たしているか確認
    if (check_heap(ary, n)) {
        printf("ヒープ条件を満たしています。\n");
    } else {
        printf("ヒープ条件を満たしていません。\n");
    }

    free(ary); // 動的に確保したメモリを解放
    return EXIT_SUCCESS;
}