#include<stdio.h>
int hesapla(int,int);
int ogrenciNot[100];

int main(){
	
	int ogrenciSayisi, gecmeNotu, kalan;
	
	printf("Ogrenci sayisi giriniz: ");
	scanf("%d", &ogrenciSayisi);
	printf("Gecme notu giriniz: ");
	scanf("%d", &gecmeNotu);
	
	kalan = hesapla( gecmeNotu , ogrenciSayisi );
	printf("Kalan ogrenci sayisi: %d\n", kalan);
	
	return 0;
}

int hesapla(int gecmeNotu, int ogrenciS){
	
	int i, kalanOgrenci=0, toplam=0;
	
	for(i=0 ; i<ogrenciS ; i++){
		printf("%d.Ogrenci: ", i+1);
		scanf("%d", &ogrenciNot[i]);
		toplam += ogrenciNot[i];
		
		if( ogrenciNot[i] < gecmeNotu )	
			kalanOgrenci++;
	}
	
	printf("\nOrtalama: %d\n", toplam/ogrenciS);
	
	return kalanOgrenci;
}
