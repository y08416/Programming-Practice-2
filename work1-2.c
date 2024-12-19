#include <stdio.h>
int main(){
    // 変数の宣言
    FILE *fpout;
    

    if((fpout=fopen("helloworld.txt","w")) == NULL){
        printf("ファイルを開くことができませんでした。");
        return 1;
    }
    
    // ファイルへの出力
    fprintf(fpout,"Hello World!!\nWhen I woke up this morning, I found many people in my room.\nWhat's up?? : -0\n");

    // ファイルを閉じる
    fclose(fpout);
    return 0;

}
