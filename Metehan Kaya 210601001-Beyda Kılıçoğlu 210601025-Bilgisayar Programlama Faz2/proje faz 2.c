#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* ders kayýt otomasyonu */

	int secim;
	char harf;
	int i=1,j;
	int a=0,b=0,c=0;
	int aranan_numara;
	int ogrenciNumarasiYedek[40];
	char ders_adi[100];

	struct ogrenci_bilgi{
		char bolum[50][40];
		int  no[40];
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
	
	dosya=fopen("ogrenci.txt","a");
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
	dosya= fopen("ogrenci.txt","r");
		while(feof(dosya)==0){
	
			fscanf(dosya,"%s	%s	  %s	%d",ogr.ad,ogr.soyad,ogr.bolum,&ogr.no);
			printf("Ogrenci %d: \n",i);
			printf("Adi:%s\nSoyadi:%s\nBolumu:%s\nNo:%d\n\n\n",ogr.ad,ogr.soyad,ogr.bolum,ogr.no);
			i++;
		}
		
			fclose(dosya);
}


	
void ogrenci_ara(FILE *dosya){
		dosya=fopen("ogrenci.txt","r+");
	while(feof(dosya)==0){
	
		fscanf(dosya,"%s	%s	  %s	%d",ogr.ad,ogr.soyad,ogr.bolum,&ogr.no[b]);
		ogrenciNumarasiYedek[a]=ogr.no[b];
		a++;
	}
	printf("Aramak istediginiz ogrencinin numarasini giriniz: ");
		scanf("%d",&aranan_numara);
	
	for(j=0;j<a+1;j++)
	{
		if(aranan_numara==ogrenciNumarasiYedek[j])
		{
			printf("Aradiginiz ogrenci bulundu!\nOgrencinin kayit sirasi : %d\n",j+1);
		}
		
	}
		if(j==a)
		{
			printf("Hicbiriyle eslesmedi! ");
		}
	fclose(dosya);
}


	
void dersBilgisiKayit(FILE *dersBilgisi){
	
	printf("Kayit edeceginiz dersin adini girin: ");
		scanf("%s",&drs.ad);
	printf("Dersin kodunu giriniz: ");
		scanf("%d",&drs.ders_kodu);
	printf("Dersin hangi bolume ait oldugunu giriniz: ");
		scanf("%s",&drs.bolum);
	printf("Dersin kredi bilgisini giriniz: ");
		scanf("%d",&drs.kredi_bilgi);
	printf("Dersin AKTS bilgisini giriniz: ");
		scanf("%d",&drs.akts);
	
	dersBilgisi=fopen("dersBilgi.txt","a+");
		fprintf(dersBilgisi,"%s	%d	%s	%d	%d",drs.ad,drs.ders_kodu,drs.bolum,drs.kredi_bilgi,drs.akts);
	fclose(dersBilgisi);	
}



void dersBilgisiListeleme(FILE *dersBilgisi){
	
	dersBilgisi=fopen("dersBilgisi.txt","r+");
		while(feof(dersBilgisi)==0)
		{
			fscanf(dersBilgisi,"%s	%d	%s	%d	%d",drs.ad,&drs.ders_kodu,drs.bolum,&drs.kredi_bilgi,&drs.akts);
			printf("Ders Kayit %d\n",i);
			printf("Ders Adi: %s\nDers Kodu: %d\nDersin ait oldugu bolum: %s\nDers Kredisi: %d\nDers AKTS: %d\n",drs.ad,drs.ders_kodu,drs.bolum,drs.kredi_bilgi,drs.akts);
		}
	fclose(dersBilgisi);
}


	
void ogrenciAdinaDersKayit(FILE *ogrenci,FILE *dersBilgisi,FILE *ogrencininDersleri){
	
	ogrenci=fopen("ogrenci.txt","r+");
		while(feof(ogrenci)==0)
		{		
			fscanf(ogrenci,"%s	%s	  %s	%d",ogr.ad[a],ogr.soyad[a],ogr.bolum[a],&dkt.ogrenci_no[a]);
			a++;
		}	
	fclose(ogrenci);
		printf("Hangi ogrenciye kayit yapacaksaniz numarasini tuslayiniz: ");
			scanf("%d",aranan_numara);
		for(i=0;i<a+1;i++)
		{
			if(dkt.ogrenci_no[a]!=aranan_numara)
			{
				printf("Sistemimize bu numara ile kayitli bir ogrenci bulunmamaktadir."); exit(1);
			}
		}
	
	
	ogrencininDersleri=fopen("ogrencininDersleri.txt","a+");
	printf("Hangi dersi kaydetmek istersiniz?: ");
		gets(ders_adi);
	printf("Ders hangi ogretim yilina ait?: ");
		scanf("%s",&dkt.yil);
	printf("Ders hangi donemde?: ");
		scanf("%s",&dkt.donem);
	fprintf(ogrencininDersleri,"%d	%s	%s	%s",aranan_numara,ders_adi,dkt.yil,dkt.donem);	
}


	
void anamenu(FILE *ogrenci,FILE *dersBilgisi,FILE *ogrencininDersleri){
	printf("Menu: \n");
	printf("1-Ogrenci Kayit Etme\n");
	printf("2-Ogrenci Kayitlarini Listeleme\n");
	printf("3-Ogrenci Arama\n");
	printf("4-Ders Bilgisi Kaydetme\n");
	printf("5-Ders Bilgisini Listeleme\n");
	printf("6-Ogrenci Adina Ders Kaydetme\n");
	
	printf("Lutfen Hangi Islemi Yapacaginizi Tuslayin! :");
	scanf("%d",&secim);
	
	
		switch(secim){
		
		case 1: printf("Ogrenci Kayit Secenegini Sectiniz! \n\n\n");
		ogrenci_kayit_olustur(ogrenci); break;
		
		case 2: printf("Ogrenci Kayitlarini Listele Secenegini Sectiniz! \n\n\n");
		ogrencileri_listele(ogrenci); break;
		
		case 3: printf("Ogrenci Arama Secenegini Sectiniz! \n\n\n");
		ogrenci_ara(ogrenci); break;
		
		case 4: printf("Ders Bilgisi Kaydetme Secenegini Sectiniz!\n\n\n");
		dersBilgisiKayit(dersBilgisi); break;
		
		case 5: printf("Ders Bilgilerini Listeleme Secenegini Sectiniz!\n\n\n");
		dersBilgisiListeleme(dersBilgisi); break;
		
		case 6: printf("Ogrenci Adina Ders Kaydetme Secenegini Sectiniz!\n\n\n");
		ogrenciAdinaDersKayit(ogrenci,dersBilgisi,ogrencininDersleri); break;
				
		default: printf("Gecerli Bir Sayi Tuslamadiniz! "); 
		break;
		}
	
	printf("Baska Bir Islem Gerceklestirmek Icin 'A' Harfini Tuslayin \n");
	harf=getch();
		if(harf=='A'|| harf=='a')
		{
			printf("Tekrar Hosgeldiniz !!\n");
			anamenu(ogrenci,dersBilgisi,ogrencininDersleri);
		}
		else
		{
			printf("Program Kapaniyor! ");
		}
}



int main(int argc, char *argv[]) {
	
	FILE *ogrenci;
	FILE *dersBilgisi;
	FILE *ogrencininDersleri;
	
	ogrenci=fopen("ogrenci.txt","a");
	fclose(ogrenci);
	
		
	printf("-----------------Bakircay Universitesi Ogrenci Ders Kayit Islemine Hos Geldiniz!-------------------\n");
	anamenu(ogrenci,dersBilgisi,ogrencininDersleri);
	
	return 0;
}
