 #include <stdio.h>

#define MAX_NUMBERS 10

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // key より大きい要素を一つ後ろに移動
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // 挿入ソートを適用
    insertionSort(numbers, MAX_NUMBERS);

    // ソート後の配列を表示
    printf("ソート後の配列: ");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
