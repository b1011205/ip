#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){


	char moto[256];
	char sahen[256],uhen[256];

	scanf("%s",moto);

	//*より左辺を切り取りsahenに代入
	int i = 0, asta = -1;
	for(i = 0; i < strlen(moto); i++){
		if(moto[i] != '*' && asta == -1){
			sahen[i] = moto[i];
		}
		if(moto[i] == '*'){
			asta = i;
		}
	}
	//*より右辺を切り取りuhenに代入
	int k = 0, j = asta+1;
	for(j = asta+1; j<strlen(moto); j++ ){
		uhen[k] = moto[j];
		k++;
	}
	int sahensu[256]={}, count = 0;
	//左辺の数字のみをsahensuに格納
	for(i = 1; i < strlen(sahen); i++){

		sahensu[count] = atoi(&sahen[i]);
		while(sahen[i] != ','){
			i++;
		}
		count++;

	}
	int uhensu[256]={};
	int d_sahen = count;
	count = 0;
	//右辺の数字のみをuhensuに格納
	for(j = 1; j < strlen(uhen); j++){
		uhensu[count] = atoi(&uhen[j]);
		while(uhen[j] != ','){
			j++;
		}

		count++;	
	}
	int d_uhen = count;
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
