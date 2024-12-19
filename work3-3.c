#include <stdio.h>
#include <stdlib.h>

//構造体を設定する
typedef struct {
    char code[30]; //商品番号
    char name[30]; //商品名
    int price;     //価格
} gift_t;

int main() {
    int num; //読み込むデータ数
    char inputFileName[100], outputFileName[100]; //入力ファイル名と出力ファイル名

    //データ数の入力
    printf("データ数を入力して下さい：");
    scanf("%d", &num);

    //入力ファイル名の入力
    printf("入力ファイル名を指定して下さい：");
    scanf("%s", inputFileName);

    //出力ファイル名の入力
    printf("出力ファイル名を指定して下さい：");
    scanf("%s", outputFileName);

    //ファイルポインタを宣言して、ファイルを開く
    FILE *fp = fopen(inputFileName, "r");
    if (fp == NULL) {
        printf("ファイルを開くことができませんでした。\n");
        return 1;
    }

    //構造体へのポインタの配列を作成し、メモリを動的に確保する
    gift_t **gifts = malloc(num * sizeof(gift_t *));
    if (gifts == NULL) {
        printf("メモリ確保することができませんでした。");
        return 1;
    }

    //データの読み込みと構造体へのポインタへの格納
    for (int i = 0; i < num; i++) {
        //構造体へのポインタを動的に確保
        gifts[i] = malloc(sizeof(gift_t));
        if (gifts[i] == NULL) {
            printf("メモリ確保することができませんでした。");
            return 1;
        }
        //ファイルからデータを読み込み
        fscanf(fp, "%s %s %d", gifts[i]->code, gifts[i]->name, &gifts[i]->price);
    }

    //ファイルを閉じる
    fclose(fp);

    //新しいファイルにデータを出力
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("ファイルを開くことができませんでした。");
        return 1;
    }

    //データの書き込み
    for (int i = 0; i < num; i++) {
        fprintf(outputFile, "%s %s %d\n", gifts[i]->code, gifts[i]->name, gifts[i]->price);
    }

    //出力ファイルのクローズ
    fclose(outputFile);

    //メモリの解放
    for (int i = 0; i < num; i++) {
        free(gifts[i]);
    }
    free(gifts);

    printf("表示形式変換後ファイルに出力しました．\n");

    return 0;
}