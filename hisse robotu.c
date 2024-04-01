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
	
	char *dosyaisim = "Analiz Geçmiþi";
	mkdir(dosyaisim);
	FILE *kayit;
	double carioran,asittestoran,borcoran,borcozkaynakoran;
	int choise,datachoise;
	char hissekodu[20], fullpath[60]="C:\\Users\\Yaðýz\\Desktop\\Analiz Geçmiþi\\";
	
	printf("\n===HÝSSE ORAN ANALÝZÝ ROBOTU===           by Yaðýz Boða\n");
	
	printf("\nHisse Kodu: ");
	scanf("%s",&hissekodu);
	
	strcat(fullpath,hissekodu);
	strcat(fullpath,".txt");
	printf("\n1. Likidite Rasyolarý\n");
	printf("2. Faaliyet Rasyolarý\n");
	printf("3. Kaldýraç Rasyolarý\n");
	printf("4. Kârlýlýk Rasyolarý\n");
	printf("5. Tüm Rasyolar\n");
	printf("\n\nLütfen yapmak istediðiniz iþlemi seçiniz(1-5): ");
	scanf("%d",&choise);
	
	if(choise == 1)
	{
		likidite(&carioran,&asittestoran);
		printf("\nCari Oran: %.2lf\n",carioran);
		printf("Asit Test Oraný: %.2lf\n",asittestoran);
		printf("veriler ""Hisse Verileri"" dosyasýna kaydedildi.");
		
		
		kayit = fopen(fullpath,"a");
		fprintf(kayit,"Cari Oran: %lf\nAsit Test Oraný: %lf",carioran,asittestoran);
		fclose(kayit);
		
		
	}
	else if(choise == 2)
	{
		
	}
	else if(choise == 3)
	{
		kaldirac(&borcoran,&borcozkaynakoran);
		printf("\nBorç Oraný: %.2lf\n",borcoran);
		printf("Borç/Özkaynak Oraný: %.2lf\n",borcozkaynakoran);
		
		kayit = fopen(fullpath,"a");
		fprintf(kayit,"Borç Oraný: %.2lf\nBorç/Özkaynak Oraný: %.2lf",borcoran,borcozkaynakoran);
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
		printf("Lütfen geçerli bir sayý girin.(1-5)");
	}
}



void likidite(double *carioran, double *asittestoran)
{
	printf("Dönen Varlýklar: ");
	scanf("%lf",&hisse.donen_varliklar);
	printf("Kýsa Vadeli Borçlar: ");
	scanf("%lf",&hisse.kisa_vadeli_borclar);
	printf("Stoklar: ");
	scanf("%lf",&hisse.stoklar);
	
	
	
	*carioran = hisse.donen_varliklar / hisse.kisa_vadeli_borclar;
	*asittestoran = (hisse.donen_varliklar - hisse.stoklar) / hisse.kisa_vadeli_borclar;
}

void kaldirac(double *borcoran,double *borcozkaynakoran)
{
	printf("Kýsa Vadeli Yükümlülükler: ");
	scanf("%lf",&hisse.kisa_vadeli_borclar);
	printf("Uzun Vadeli Yükümlülükler: ");
	scanf("%lf",&hisse.uzun_vadeli_borclar);
	printf("Toplam Varlýklar: ");
	scanf("%lf",&hisse.toplam_varliklar);
	printf("Özkaynaklar: ");
	scanf("%lf",&hisse.oz_kaynaklar);
	
	*borcoran = (hisse.kisa_vadeli_borclar + hisse.uzun_vadeli_borclar) / hisse.toplam_varliklar;
	*borcozkaynakoran = (hisse.kisa_vadeli_borclar + hisse.uzun_vadeli_borclar) / hisse.oz_kaynaklar;
}
