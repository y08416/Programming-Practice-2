#include <stdio.h>

#define MAX_NUMBERS 10

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // 一つ一つの要素について最小の要素を見つけて、先頭に持ってくる
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 見つけた最小の要素を先頭の要素と交換
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    FILE *fp;
    int numbers[MAX_NUMBERS];
    int count = 0;

    fp = fopen("numbers.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開くことができませんでした。\n");
        return 1;
    }

    // ファイルから10個の整数を読み込む
    while (fscanf(fp, "%d", &numbers[count]) != EOF && count < MAX_NUMBERS) {
        count++;
    }
    fclose(fp);

    if (count != MAX_NUMBERS) {
        printf("ファイルに10個の整数が含まれていません。\n");
        return 1;
    }

    // ソート前の配列を表示
    printf("ソート前の配列: ");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 選択ソートを適用
    selectionSort(numbers, MAX_NUMBERS);

    // ソート後の配列を表示
    printf("ソート後の配列: ");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
