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
    int largest = i;   // 最大値のインデックスを仮にiに設定
    int left = 2 * i + 1;  // 左の子ノードのインデックス
    int right = 2 * i + 2; // 右の子ノードのインデックス
    
    // 左の子ノードが存在し、かつ左の子ノードの値が現在の最大値より大きい場合
    if (left < n && ary[left] > ary[largest])
        largest = left;
    
    // 右の子ノードが存在し、かつ右の子ノードの値が現在の最大値より大きい場合
    if (right < n && ary[right] > ary[largest])
        largest = right;
    
    // 最大値が根ノードではない場合、値を交換し再帰的にheapifyを呼び出す
    if (largest != i) {
        swap(&ary[i], &ary[largest]);
        heapify(ary, n, largest);
    }
}

// 配列を最大ヒープに構築する関数
void buildMaxHeap(int ary[], int n) {
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

// ヒープソートを行う関数
void heapSort(int a[], int n) {
    buildMaxHeap(a, n); // 配列を最大ヒープに変換
    for (int i = n - 1; i > 0; i--) {
        // ルートと最後の要素を交換
        swap(&a[0], &a[i]);
        // ヒープのサイズを縮小し、ヒープ条件を再構築
        heapify(a, i, 0);
    }
}

int main(void) {
    FILE *fp = fopen("numbers.dat", "r"); // numbers.datファイルを開く
    if (fp == NULL) { // ファイルが開けなかった場合
        perror("ファイルを開けませんでした。");
        return EXIT_FAILURE;
    }
    
    int initialSize = 10; // 初期配列サイズ
    int *ary = (int *)malloc(initialSize * sizeof(int)); // 動的メモリ確保
    if (ary == NULL) { // メモリ確保に失敗した場合
        perror("メモリの確保に失敗しました。");
        fclose(fp);
        return EXIT_FAILURE;
    }
    
    int n = 0; // 現在の配列要素数
    int num;
    // numbers.datから10個の整数を読み込む
    while (n < initialSize && fscanf(fp, "%d", &num) == 1) {
        ary[n++] = num;
    }
    fclose(fp); // ファイルを閉じる
    
    heapSort(ary, n); // ヒープソートを実行
    
    // ソートされた配列を出力
    printArray(ary, n);
    
    free(ary); // 動的に確保したメモリを解放
    return EXIT_SUCCESS;
}
