#include <stdio.h>
void swap(int *a, int *b);

int main(){
int x,y;
printf("二つの整数を入力してください:\n");
scanf("%d",&x);
scanf("%d",&y);
printf("変数xの値は%d,変数yの値は%dです。\n",x,y);
swap(&x,&y);
printf("swap()を呼び出した後の変数xの値は%d,変数yの値は%dです。\n",x,y);
return 0;

}

void swap(int *a, int *b){

int temp = *a;
*a = *b;
*b = temp;
}