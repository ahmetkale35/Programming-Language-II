#include <stdio.h>
#include <stdlib.h>

int hesapla (int, int);
int main (){
	
	int ogrsayisi;
	int gecmenotu;
	int kalan;
	
	printf("Ogrenci Sayisi Giriniz :");
	scanf("%d" ,&ogrsayisi);
	
	printf("Gecme notunu giriniz :");
	scanf("%d" ,&gecmenotu);
	
	kalan = hesapla(ogrsayisi,gecmenotu);
	printf("Gecen Ogrenci Sayisi : %d\n" ,ogrsayisi-kalan);
	printf("Kalan Ogrenci Sayisi : %d\n" ,kalan);

	return 0;
}

int hesapla(int os, int gn){
		int notlar[100];
		int kalan;
		int toplam=0,i;
		
		for (i=0; i<os; i++){
			printf("%d. ogrencinin notu : " ,i+1);
			scanf("%d" ,&notlar[i]);
			
			if (notlar[i] < gn){
				kalan++;
			}
			toplam+=notlar[i];
		}
		printf("Not Ortalamasi : %d\n" ,toplam/os);
		return kalan;
}
