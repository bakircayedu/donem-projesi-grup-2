#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int secim;
	char harf;
	int i=1,j;
	int a=0;
	int aranan_numara;
	int ogrenci_no_2[40];

struct ogrenci_bilgi{
	char bolum[50][40];
	int  no;
	char ad[20][40];
	char soyad[20][40];
	
}ogr;

 struct ders_bilgi{
	char bolum[50][40];
	int  ders_kodu[40];
	char ad[20][40];
	int  kredi_bilgi[40];
	int akts[40];
}drs;

 struct ders_kayit {
	char yil[10][40];
	char donem[10][40];
	int ogrenci_no[40];
	int ders_kodu[40];
	int basari_notu[40];
}dkt;


	void ogrenci_kayit_olustur(FILE *dosya){
	
	dosya=fopen("guzelanne.txt","a");
		printf("Ogrencinin adini girin: ");
			scanf("%s",ogr.ad);
		printf("Ogrencinin soyadini girin: ");
			scanf("%s",ogr.soyad);
		printf("Ogrencinin bolumunu girin: ");
			scanf("%s",ogr.bolum);
		printf("Ogrencinin numarasini girin: ");
			scanf("%d",&ogr.no);
			
		fprintf(dosya,"%s	%s	%s	%d\n",ogr.ad,ogr.soyad,ogr.bolum,ogr.no);
	fclose(dosya);
	
	}

	void ogrencileri_listele(FILE *dosya){
	dosya= fopen("guzelanne.txt","r");
		do{
	
			fscanf(dosya,"%s	%s	  %s	%d",ogr.ad,ogr.soyad,ogr.bolum,&ogr.no);
			printf("Ogrenci %d: \n",i);
			printf("Adi:%s\nSoyadi:%s\nBolumu:%s\nNo:%d\n\n\n",ogr.ad,ogr.soyad,ogr.bolum,ogr.no);
			i++;
		}	while(feof(dosya)==0);
		
			fclose(dosya);
		}
	void ogrenci_ara(FILE *dosya){
		dosya=fopen("guzelanne.txt","r+");
	while(feof(dosya)==0){
	
		fscanf(dosya,"%s	%s	  %s	%d",ogr.ad,ogr.soyad,ogr.bolum,&ogr.no);
		ogrenci_no_2[a]=ogr.no;
		a++;
	}
	printf("Aramak istediginiz ogrencinin numarasini giriniz: ");
	scanf("%d",&aranan_numara);
	
	for(j=0;j<a+1;j++)
	{
		if(aranan_numara==ogrenci_no_2[j])
		{
			printf("Aradiginiz ogrenci bulundu!\nOgrencinin numarasi: %d\n",j+1);
		}
		
	}
		if(j==a)
		{
			printf("Hicbiriyle eslesmedi! ");
		}
	fclose(dosya);
	}
	
	void anamenu(FILE *ogrenci){
	printf("Menu: \n");
	printf("1-Ogrenci Kayit Etme\n");
	printf("2-Ogrenci Kayitlarini Listeleme\n");
	printf("Lutfen Hangi Islemi Yapacaginizi Tuslayin! :");
	scanf("%d",&secim);
	
	
		switch(secim){
		
		case 1: printf("Ogrenci Kayit Secenegini Sectiniz! \n\n\n");
		ogrenci_kayit_olustur(ogrenci); break;
		
		case 2: printf("Ogrenci Kayitlarini Listele Secenegini Sectiniz! \n\n\n");
		ogrencileri_listele(ogrenci); break;
		
		case 3: printf("Ogrenci Arama Secenegini Sectiniz! \n\n\n");
		ogrenci_ara(ogrenci); break;
		
		default: printf("Gecerli Bir Sayi Tuslamadiniz! "); 
		break;
		
		}
	
	
	printf("Baska Bir Islem Gerceklestirmek Icin 'A' Harfini Tuslayin \n");
	harf=getch();
		if(harf=='A'|| harf=='a')
		{
			printf("Tekrar Hosgeldiniz !!\n");
			anamenu(ogrenci);
		}
		else
		{
			printf("Program Kapaniyor! ");
		}
		
	}
int main(int argc, char *argv[]) {
	
	FILE *ogrenci;
	
	
	
	
	printf("-----------------Bakircay Universitesi Ogrenci Ders Kayit Islemine Hos Geldiniz!-------------------\n");
	anamenu(ogrenci);
	printf("%d",ogrenci_no_2[0]);
	return 0;
}
