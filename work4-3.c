#include <stdio.h>
#include <string.h>

//構造体の定義
typedef struct word_pair {
    char longer_word[10];     //長い方の文字列
    char shorter_word[10];    //短い方の文字列
    char combined_word[20];   //連結した文字列
    int longer_word_length;   //長い方の文字列の長さ
    int shorter_word_length;  //短い方の文字列の長さ
} word_pair_t;

//関数の宣言
word_pair_t create_word_pair(char *a, char *b);

int main() {
    char str1[100], str2[100];
    word_pair_t result;

    printf("2つの文字列を入力してください:");
    scanf("%s %s", str1, str2);

    //create_word_pair関数を用いて構造体を作成
    result = create_word_pair(str1, str2);

    //構造体の内容を表示
    printf("longer_word: %s\n", result.longer_word);
    printf("shorter_word: %s\n", result.shorter_word);
    printf("combined_word: %s\n", result.combined_word);
    printf("longer_word_length: %d\n", result.longer_word_length);
    printf("shorter_word_length: %d\n", result.shorter_word_length);

    return 0;
}

word_pair_t create_word_pair(char *a, char *b) {

    word_pair_t pair;

    //文字列aとbの長さを取得
    int len_a = strlen(a);
    int len_b = strlen(b);

    //長い文字列をlonger_wordに、短い文字列をshorter_wordに代入
    if (len_a > len_b) {
        strcpy(pair.longer_word, a);
        strcpy(pair.shorter_word, b);
    } else if (len_a < len_b) {
        strcpy(pair.longer_word, b);
        strcpy(pair.shorter_word, a);
    } else {
        if (strcmp(a, b) > 0) {
            strcpy(pair.longer_word, a);
            strcpy(pair.shorter_word, b);
        } else {
            strcpy(pair.longer_word, b);
            strcpy(pair.shorter_word, a);
        }
    }
 
    //combined_wordにはlonger_wordとshorter_wordをスペース区切りで結合したものを代入
    sprintf(pair.combined_word, "%s %s", pair.longer_word, pair.shorter_word);

    //文字列の長さをメンバ変数に代入
    pair.longer_word_length = strlen(pair.longer_word);
    pair.shorter_word_length = strlen(pair.shorter_word);
    
    return pair;
}
