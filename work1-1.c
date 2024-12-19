#include <stdio.h>

int main(void){

    // 変数の宣言
    FILE *fp;
    char num[100],name[100]; //商品名を格納するための配列
    int price;
     
    // ファイルを開く
    fp=fopen("gifts.dat","r");

    if(fp == NULL){
        printf("ファイルを開くことができませんでした。\n");
        return 1; // プログラム終了

    }

    
    //　fscanfを使用してデータを読み込んでデータを出力する
    while (fscanf(fp, "%s %s %d", num, name, &price) != EOF) {
        printf("商品コード: %s, 商品名: %s, 価格: %d\n", num, name, price);
    }

    //　ファイルを閉じる
    fclose(fp);

    return 0;
    
}
