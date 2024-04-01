#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<time.h>

void likidite(double*,double*);
void faaliyet();
void kaldirac();
void karlilik();
void date();

struct balance
{
	char hisse_kodu[30];
	double donen_varliklar, stoklar,kisa_vadeli_borclar,net_satislar,ticari_alacaklar,duran_varliklar,oz_kaynaklar,net_kar,nakit_ve_nakit_benzerleri;
	double uzun_vadeli_borclar,toplam_varliklar;
}hisse;


int main()
{
	setlocale(LC_ALL,"Turkish");
	
	char *dosyaisim = "Analiz Ge�mi�i";
	mkdir(dosyaisim);
	FILE *kayit;
	double carioran,asittestoran,borcoran,borcozkaynakoran;
	int choise,datachoise;
	char hissekodu[20], fullpath[60]="C:\\Users\\Ya��z\\Desktop\\Analiz Ge�mi�i\\";
	
	printf("\n===H�SSE ORAN ANAL�Z� ROBOTU===           by Ya��z Bo�a\n");
	
	printf("\nHisse Kodu: ");
	scanf("%s",&hissekodu);
	
	strcat(fullpath,hissekodu);
	strcat(fullpath,".txt");
	printf("\n1. Likidite Rasyolar�\n");
	printf("2. Faaliyet Rasyolar�\n");
	printf("3. Kald�ra� Rasyolar�\n");
	printf("4. K�rl�l�k Rasyolar�\n");
	printf("5. T�m Rasyolar\n");
	printf("\n\nL�tfen yapmak istedi�iniz i�lemi se�iniz(1-5): ");
	scanf("%d",&choise);
	
	if(choise == 1)
	{
		likidite(&carioran,&asittestoran);
		printf("\nCari Oran: %.2lf\n",carioran);
		printf("Asit Test Oran�: %.2lf\n",asittestoran);
		printf("veriler ""Hisse Verileri"" dosyas�na kaydedildi.");
		
		
		kayit = fopen(fullpath,"a");
		fprintf(kayit,"Cari Oran: %lf\nAsit Test Oran�: %lf",carioran,asittestoran);
		fclose(kayit);
		
		
	}
	else if(choise == 2)
	{
		
	}
	else if(choise == 3)
	{
		kaldirac(&borcoran,&borcozkaynakoran);
		printf("\nBor� Oran�: %.2lf\n",borcoran);
		printf("Bor�/�zkaynak Oran�: %.2lf\n",borcozkaynakoran);
		
		kayit = fopen(fullpath,"a");
		fprintf(kayit,"Bor� Oran�: %.2lf\nBor�/�zkaynak Oran�: %.2lf",borcoran,borcozkaynakoran);
		fclose(kayit);
	}
	else if(choise == 4)
	{
		
	}
	else if(choise == 5)
	{
		
	}
	else if(choise <1 || choise >5)
	{
		printf("L�tfen ge�erli bir say� girin.(1-5)");
	}
}



void likidite(double *carioran, double *asittestoran)
{
	printf("D�nen Varl�klar: ");
	scanf("%lf",&hisse.donen_varliklar);
	printf("K�sa Vadeli Bor�lar: ");
	scanf("%lf",&hisse.kisa_vadeli_borclar);
	printf("Stoklar: ");
	scanf("%lf",&hisse.stoklar);
	
	
	
	*carioran = hisse.donen_varliklar / hisse.kisa_vadeli_borclar;
	*asittestoran = (hisse.donen_varliklar - hisse.stoklar) / hisse.kisa_vadeli_borclar;
}

void kaldirac(double *borcoran,double *borcozkaynakoran)
{
	printf("K�sa Vadeli Y�k�ml�l�kler: ");
	scanf("%lf",&hisse.kisa_vadeli_borclar);
	printf("Uzun Vadeli Y�k�ml�l�kler: ");
	scanf("%lf",&hisse.uzun_vadeli_borclar);
	printf("Toplam Varl�klar: ");
	scanf("%lf",&hisse.toplam_varliklar);
	printf("�zkaynaklar: ");
	scanf("%lf",&hisse.oz_kaynaklar);
	
	*borcoran = (hisse.kisa_vadeli_borclar + hisse.uzun_vadeli_borclar) / hisse.toplam_varliklar;
	*borcozkaynakoran = (hisse.kisa_vadeli_borclar + hisse.uzun_vadeli_borclar) / hisse.oz_kaynaklar;
}
