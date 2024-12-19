#include <stdio.h>
void swap(int x, int y);

int main(){
int x,y;
x = 2; y = 5;
printf("x=%d, y=%d\n", x, y) ;
swap(x,y);
printf("x=%d, y=%d\n", x, y);
return 0;
}

void swap(int x, int y){
int temp = x;
x = y;
y = temp;
}

//xとyの値を入れ替えても引数は値渡しとなるためmain関数内のxとyには影響がない
//x,yの値を変えるにはポインターを使う必要がある
