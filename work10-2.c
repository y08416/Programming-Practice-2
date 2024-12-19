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

int main(void) {
    // ファイルを読み取りモードで開く
    FILE *fp = fopen("numbers.dat", "r");
    if (fp == NULL) {
        perror("ファイルを開けませんでした。"); // ファイルオープンエラー
        return EXIT_FAILURE;
    }

    int initialSize = 10; // 初期配列サイズ
    int *ary = (int *)malloc(initialSize * sizeof(int)); // 動的メモリ確保
    if (ary == NULL) {
        perror("メモリの確保に失敗しました。"); // メモリ確保エラー
        fclose(fp);
        return EXIT_FAILURE;
    }

    int n = 0; // 現在の配列要素数
    int num;  // ファイルから読み取る数値

    // ファイルから数値を読み取り、配列に格納
    while (fscanf(fp, "%d", &num) == 1) {
        if (n >= initialSize) {
            // 配列サイズが足りなくなった場合、サイズを倍に拡張
            initialSize *= 2;
            int *temp = realloc(ary, initialSize * sizeof(int)); // メモリ再確保
            if (temp == NULL) {
                perror("メモリの再確保に失敗しました。"); // メモリ再確保エラー
                free(ary);
                fclose(fp);
                return EXIT_FAILURE;
            }
            ary = temp; // 新しいメモリブロックへのポインタを更新
        }
        ary[n++] = num; // 読み取った数値を配列に格納し、要素数を増やす
    }
    fclose(fp); // ファイルを閉じる

    buildMinHeap(ary, n); // 配列を最小ヒープに構築
    printArray(ary, n);   // ヒープの内容を出力

    // check_heap関数を呼び出してヒープ条件を満たしているか確認
    if (check_heap(ary, n)) {
        printf("ヒープ条件を満たしています。\n");
    } else {
        printf("ヒープ条件を満たしていません。\n");
    }

    free(ary); // 動的に確保したメモリを解放
    return EXIT_SUCCESS;
}
