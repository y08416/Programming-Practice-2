#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *name[5]; // 文字列用のポインタ配列を宣言
    char input[64];
    int count = 0;

    printf("名前を最大5人分入力してください:\n"); 

    while (count < 5 && scanf("%s", input) != EOF) {
        name[count] = malloc(strlen(input) + 1); // 名前用のメモリを確保
        if (name[count] == NULL) { //メモリを確保できなかった時の動作
            fprintf(stderr, "メモリの確保に失敗しました。\n"); 
            return 1;
        }
        strcpy(name[count], input); //入力された名前をメモリにコピー
        count++;
    }

    printf("\n入力された名前の情報:\n"); // 入力された名前の情報を表示
    for (int i = 0; i < count; i++) {
        printf("アドレス: %p, 名前: %s\n", (void *)name[i], name[i]); //アドレスと名前を表示
        free(name[i]); //メモリを解放
    }

    return 0;
}

