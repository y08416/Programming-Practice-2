#include <stdio.h>
int main()
{
int a, *p; //整数型の変数a とポインタ変数p を宣言
a = 10; //aに10を代入

printf("a: %d\n", a); //aの値を表示する
printf("&a: %p\n\n", &a); //aのアドレスを表示する

p = &a; //pにaのアドレスを代入
printf("p: %p\n", p); //aのアドレスを表示
printf("*p: %d\n", *p); //aの値を表示
printf("&p: %p\n\n", &p);//pのアドレスを表示

a = 20; //aに20を代入
printf("a: %d\n", a); //aの値を表示
printf("&a: %p\n\n", &a); //aのアドレスを表示

printf("p: %p\n", p); //aのアドレスを表示
printf("*p: %d\n", *p); //aの値を表示
printf("&p: %p\n", &p); //pのアドレスを表示
return 0;
}