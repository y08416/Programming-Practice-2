#include <stdio.h>
#include <stdlib.h>

// 構造体を設定する
typedef struct {
    char code[30]; //商品番号
    char name[30]; ///商品名
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

    //ファイルから内容を読み取る
    fscanf(fp, "%s %s %d", gift.code, gift.name, &gift.price);
    
    // ファイルを閉じる
    fclose(fp);
    
    //画面に出力
    printf("code: %s\n", gift.code);
    printf("name: %s\n", gift.name);
    printf("price: %d\n", gift.price); 

    return 0;
    
} 