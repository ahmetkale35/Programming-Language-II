#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kitleindeks(float,float);

int main(){
	int deger;
	float boy,kilo;
	printf("Boy giriniz :");
	scanf("%f" ,&boy);
	
	printf("Kilo Giriniz :");
	scanf("%f" ,kilo);
	
	deger = kitleindeks(boy,kilo);
	
	switch(deger){
	case 1:
		printf("Zayif");
	case 2:
		printf("Normal");
	case 3:
		printf("Kilolu");
	case 4:
		printf("Obez");
		break;
	}
	
	return 0;
}
	int kitleindeks(float b, float k){
		float bki;
		bki = k / (b * b);
		if(bki <= 18)
			return 1;
		else if(bki<=25)	
			return 2;
		else if(bki<=30)	
			return 3;
		else 
			return 4;
			
	}
	
	
