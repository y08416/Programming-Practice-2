#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 構造体を設定する
typedef struct {
    char code[100]; //商品番号
    char name[100]; ///商品名
    int price; //価格
}gift_t;


int main(){
    //ファイルポインタを宣言して、ファイルを開く
    FILE *fp=fopen("gifts.dat","r");

    if(fp == NULL){
        printf("ファイルを開くことができませんでした。\n");
        return 1;
    }

     // gift_t型の変数を宣言
    gift_t gift;

      //　fscanfを使用してデータを読み込んでデータを出力する
    while (fscanf(fp, "%s %s %d", gift.code, gift.name, &gift.price) != EOF) {
        printf("商品コード: %s\n商品名: %s\n価格: %d\n\n", gift.code, gift.name, gift.price);
    }

    
    // ファイルを閉じる
    fclose(fp);

    return 0;
    
} 