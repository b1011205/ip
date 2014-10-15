#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suji(char a[256]){

int i = 0;
for(i = 0; i < strlen(a); i++){


}

return a;

}

int main(void){


	char moto[256];
	char sahen[256],uhen[256];

	scanf("%s",moto);

	//*より左辺を切り取りsahenに代入
	int i = 0, asta = -1;
	for(i = 0; i < strlen(moto); i++){
		if(moto[i] != '*' && asta == -1){
			sahen[i] = moto[i];
			printf("%s\n%s\n", moto, sahen);

		}
		if(moto[i] == '*'){
			asta = i;
		}
	}
	//*より右辺を切り取りuhenに代入
	int k = 0, j = asta+1;
	for(j = asta+1; j<strlen(moto); j++ ){
		uhen[k] = moto[j];
		printf("%s\n%s\n",moto, uhen);
		k++;
	}

	int uhensu[256],sahensu[256];

	uhensu = suji(uhen);
	sahensu = suji(sahen);

	return 0;
}
