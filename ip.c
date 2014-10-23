#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dainyu(char moto[],char hen[]){
    
    int i = 0, asta = -1;
    
    for(i = 0; i < strlen(moto); i++){
        
        if(moto[i] != '*' && asta == -1){
            hen[i] = moto[i];
        }
        if(moto[i] == '*'){
            asta = i;
        }
    }
    
}
//元の配列からアスタリスクの場所を探し、先頭から何番目かを返す
int asta(char moto[]){

    int i=0, asta=0;
    
    for(i = 0; i< strlen(moto); i++){
    if(moto[i] == '*')
        asta = i;
    }
    
    return asta;
}
//文字から数字のみを取り出して代入する　と同時に、数字の次元数を返す
int suji_dainyu(char hen[],int hen_suji[]){

    int i = 0,count = 0;
    
    for(i = 1; i < strlen(hen); i++){
        
        hen_suji[count] = atoi(&hen[i]);
        while(hen[i] != ','){
            i++;
        }
        count++;
    }
    return count;
}

int main(void){
    
    char moto[256];
    char sahen[256],uhen[256];
    
    scanf("%s",moto);
    
    //*より左辺を切り取りsahenに代入
    int i=0;
    dainyu(moto, sahen);
    
    //*より右辺を切り取りuhenに代入
    int k = 0, ast = asta(moto),j;
    dainyu(&moto[ast+1], uhen);
    
    //左辺の数字のみをsahensuに格納
    int sahensu[256]={};
    int d_sahen = suji_dainyu(sahen,sahensu);
    
    //右辺の数字のみをuhensuに格納
    int uhensu[256]={};
    int d_uhen = suji_dainyu(uhen,uhensu);
    
    //要素数が同じであれば、次元数と計算結果を出す
    int kei = 0;
    if(d_sahen == d_uhen ){
        for(i = 0; i < sizeof(sahensu)/sizeof(sahensu[0]); i++){
            kei = kei +(sahensu[i] * uhensu[i]);
        }
        printf("D=%d,I=%d\n", d_uhen, kei);
    }else{
        printf("Error\n");
    }	
    
    return 0;
}
