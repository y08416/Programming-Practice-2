#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *str; //char型のポインタを宣言
    int size; //文字列の最大長を格納する変数を宣言

    printf("文字列の最大長を入力してください:"); 
    scanf("%d", &size); //最大長を読み取る

    str = (char *)malloc(sizeof(char) * (size + 1)); // 文字列用のメモリを確保

    if (str == NULL) //メモリを確保できなかった時の動作
    {
        printf("メモリ確保ができませんでした。\n"); 
        return 1; 
    }

    printf("文字列を入力してください:"); 
    scanf("%s", str); //文字列を読み取る

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]); //文字を大文字に変換
    }

    for(int i = size - 1; i >= 0; i--) { //逆順で表示
        printf("%c", str[i]);
    }

    free(str); //メモリを解放
    return 0; //正常終了でプログラムを終了
}
