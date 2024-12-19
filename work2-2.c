#include <stdio.h>
int main()
{
char c, *p; //char型の変数cとポインタ変数pを宣言
char s[12] = "Ritsumeikan"; //char型の要素数12の配列sを宣言しRitsumeikanを代入

c = 'A'; //cにAを代入
p = &c; //pにcのアドレスを代入

printf("c: %c\n", c); //cの値を表示
printf("&c: %p\n\n", &c); //cのアドレスを表示
printf("p: %p\n", p); //cのアドレスを表示
printf("*p: %c\n\n", *p); //cの値を表示

*p = 'B'; //cの値にBを代入
printf("c: %c\n", c); //cの値を表示
printf("&c: %p\n\n", &c); //cのアドレスを表示
printf("p: %p\n", p); //cのアドレスを表示
printf("*p: %c\n\n", *p); //cの値を表示

printf("s: %s\n", s); //配列s全体を表示
printf("s[0]: %c\n", s[0]); //配列sの一文字目を表示
printf("s[1]: %c\n", s[1]); //配列sの二文字目を表示
printf("s: %p\n", s); //配列sの一文字目のアドレスを表示
printf("&s[0]: %p\n", &s[0]); //配列sの一文字目のアドレスを表示

printf("*s: %c\n", *s); //配列sの一文字目を表示
printf("*(s+1): %c\n\n", *(s+1)); ///配列sの二文字目を表示 
*(s+2) = 'T'; //配列sの3文字目にTを代入
printf("s: %s\n", s); //配列s全体を表示
return 0;
}