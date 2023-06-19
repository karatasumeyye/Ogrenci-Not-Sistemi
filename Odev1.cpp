



/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI : 1
**				ÖĞRENCİ ADI : SÜMEYYE KARATAŞ
**				ÖĞRENCİ NUMARASI: B221210005
**				DERS GRUBU…………: 1.ÖĞRETİM B
****************************************************************************/



#include <iostream>
#include <locale>
#include <iomanip>
#include<time.h>
#include<stdlib.h>
#include<cmath>

using namespace std;




struct Ogrenci
{
	string adi, soyadi;
	int  no, kisaSinav1, kisaSinav2, ödev1, ödev2, proje, vize, final;
	float yil_ici_not, basari_notu;

};

struct Tarih
{
	int gun, ay, yıl;
};




// Fonksiyon Prototipleri

void Random_Islem();
void Kullanicidan_Isteme();
int Max_Bulma();
int Min_Bulma();
float Sinif_Ortalama();
void Ogrenci_Listeleme();
float Standart_Sapma();
void Belirli_Deger_Arasindaki_Ogrenci(int x,int y);
void Belli_Degerin_Altindaki_Ogrenci(int x);
void Belli_Degerin_Ustundeki_Ogrenci(int x);
void Harf_Notu(int puan);
void Not_Kontrol(float x);


Ogrenci ogr[100];  // Global ogr[] dizisi
Tarih dogum_gunu[100];  //Global dogum_gunu[] dizisi 

int ogr_sayisi;  



int main()
{
	setlocale(LC_ALL, "Turkish");

	cout << "Yapacağınız işlemi seçiniz." << endl << "1.Seçenek : Öğrenci bilgilerini rastgele atama." << endl << "2.Seçenek : Öğrneci bilgilerini kullanıcıdan isteme.\n\n";
	cout << "Seçiminizi 1 ya da 2 şeklinde belirtiniz.";
	int secim;
	cin >> secim;
	char devam = 'e';


	switch (secim)        // switch case ile kullanıcı yapmak istediği işlemi (1 ve 2) seçecek.
	{
	case 1:
		Random_Islem(); break;

	case 2:
		Kullanicidan_Isteme(); break;

	default:
		cout << "Geçerli seçeneği giriniz.";
		break;
	}
	cout << endl;

	// Do while döngüsü ile birlikte kullanıcı istediği kadar menüden istediği işlemi yapabilecek.
	do
	{
		cout << "\n\n";
		cout << "Menüden çıkmak istediğinizde 0 'a basın .\n\n ";
		cout << "MENü\n\n";
		cout << "1) Sınıf listesi yazdırılsın." << endl;
		cout << "2) Sınıfın en yüksek notunu bul." << endl;
		cout << "3) Sınıfın en düşük notunu bul." << endl;
		cout << "4) Sınıfın ortalamasını hesapla." << endl;
		cout << "5) sınıfın standart sapmasını hesapla." << endl;
		cout << "6) Başarı notu belirli bir aralıkta olanlar listelensin." << endl;
		cout << "7) Başarı notu belirtilen bir değerin altında olan öğrencilerin listesi" << endl;
		cout << "8) Başarı notu belirtilen bir değerin üstünde olan öğrencilerin listesi \n\n";

		cout << "\n\n";
	
		int secim1;
		cout << "Menüden gerçekleştirmek istediğiniz işlemi seçiniz.(1 ve 8 arası) :";
		cin >> secim1;

		// Kullaıcının istediği işlemleri if/else if yapılarıyla sorgulattım ve işlemler için tanımladığım fonksiyonları çağırdım.

		if (secim1 == 1)
		{
			cout << "Öğrenci no " << setw(5) << "Öğrenci adı ve soyadı\n\n";
			Ogrenci_Listeleme();
		}
		else if (secim1 == 2)
			cout << " max değer :" << Max_Bulma();
		else if (secim1 == 3)
			cout << "min değer :" << Min_Bulma();
		else if (secim1 == 4)
			cout << " ortalama :" << Sinif_Ortalama();
		else if (secim1 == 5)
			cout << " Standart sapma :" << Standart_Sapma();
		else if (secim1 == 6)
		{
			cout << "İstediğiniz değer aralığını giriniz." << endl;
			int ilk_sayi, ikinci_sayi;
			cout << "İlk sayı :" << endl; cin >> ilk_sayi;
			cout << "İkinci sayı :" << endl; cin >> ikinci_sayi;

			cout << "İstediğiniz değer aralığındaki öğrenciler :" << endl;
			Belirli_Deger_Arasindaki_Ogrenci(ilk_sayi, ikinci_sayi);

		}

		else if (secim1 == 7)
		{
			cout << "Notu belli değer altındaki öğrencileri görmek için değer giriniz." << endl;
			int deger;
			cin >> deger;

			Belli_Degerin_Altindaki_Ogrenci(deger);

		}
		else if (secim1 == 8)
		{
			cout << "Notu belli değer üstündeki öğrencileri görmek için değer giriniz." << endl;
			int deger1;
			cin >> deger1;
			Belli_Degerin_Ustundeki_Ogrenci(deger1);

		}
		cout << endl;
		cout << "Devam etmek istiyorsanız (e/E) tuşa basınız." << endl;
		cin >> devam;
		system("cls");
	
	} while (devam=='E'|| devam =='e');   // Kullanıcı sıfıra bastığında döngüden çıkacak.

	





}



// Öğrenci verilerinin random belirlenmesi için oluşturduğum fonksiyon.
void Random_Islem()
{
	
	string isim[30] = { "Ali","Ayşe","Ada","Ahu","Alya","Arzu","Ayça","Beril","Cana","Su","Ateş","Sude","Esma","Ufuk","Jale","Yusuf","İzzet","Seda","Sema","Dila","Doğa","Ece","Ela","Elif","Eva","Işıl","İlke","Eylül","Sümeyye","Ahmet" };
	string soyisim[30] = { "Karatas","Ozturk","Kaya","Tahtacı","Yılmaz","Sen","Sezer","Yaman","Kılıc","Yıldız","Koc","Yıldırım","Demir","Sarı","Akar","Koroğlu","Firat","Simsek","Ak","Toprak","Ates","Su","Irmak","Duman","Altıntas","Karakaya",
			"Bakırcı","Kartal","Keskin","Ulusoy" };


	 ogr_sayisi = 100;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)   // 1 'den 100'e kadar öğrencilere random isim ve soyisim atanıyor.
	{
		int a = rand() % 30;
		int b = rand() % 30;
		ogr[i].adi = isim[a];
		ogr[i].soyadi = soyisim[b];

		if (0 <= i && i < 10)          //  Öğrencilerin %10'una  0 ile 40 arasında random not almasını sağlıyor.
		{

			ogr[i].kisaSinav1 = rand() % 41;
			ogr[i].kisaSinav2 = rand() % 41;
			ogr[i].ödev1 = rand() % 41;
			ogr[i].ödev2 = rand() % 41;
			ogr[i].proje = rand() % 41;
			ogr[i].vize = rand() % 41;
		
			ogr[i].final = rand() % 41;
		}
		else if (10 <= i && i < 60)   // Öğrencilerin %50'sine 40 ile 70 arasında random not almasını sağlıyor.
		{

			ogr[i].kisaSinav1 = rand() % 31 + 40;
			ogr[i].kisaSinav2 = rand() % 31 + 40;
			ogr[i].ödev1 = rand() % 31 + 40;
			ogr[i].ödev2 = rand() % 31 + 40;
			ogr[i].proje = rand() % 31 + 40;
			ogr[i].vize = rand() % 31 + 40;
			ogr[i].final = rand() % 31 + 40;

		}

		else if (60 <= i && i < 75)      // Öğrencilerin %15'ine 70 ile 80 arasında random not almasını sağlıyor.
		{

			ogr[i].kisaSinav1 = 70 + rand() % 11;
			ogr[i].kisaSinav2 = 70 + rand() % 11;
			ogr[i].ödev1 = 70 + rand() % 11;
			ogr[i].ödev2 = 70 + rand() % 11;
			ogr[i].proje = 70 + rand() % 11;
			ogr[i].vize = 70 + rand() % 11;
			ogr[i].final = 70 + rand() % 11;


		}

		else if (75 <= i && i < 100)     // Öğrencilerin %25'inin 80 ile 100 arasında random not almasını sağlıyor.
		{

			ogr[i].kisaSinav1 = 80 + rand() % 21;
			ogr[i].kisaSinav2 = 80 + rand() % 21;
			ogr[i].ödev1 = 80 + rand() % 21;
			ogr[i].ödev2 = 80 + rand() % 21;
			ogr[i].proje = 80 + rand() % 21;
			ogr[i].vize = 80 + rand() % 21;
			ogr[i].final = 80 + rand() % 21;

		}
		//  For döngüsünden çıkmadan başarı ve yıl içi notları hesaplanıyor.

		ogr[i].yil_ici_not = ogr[i].kisaSinav1 * 0.07 + ogr[i].kisaSinav2 * 0.07 + ogr[i].ödev1 * 0.10 + ogr[i].ödev2 * 0.10 + ogr[i].proje * 0.16 + ogr[i].vize * 0.50;
		ogr[i].basari_notu = ogr[i].yil_ici_not * 0.55 + ogr[i].final * 0.45;

		ogr[i].no = rand() % 101;    // Öğrenci numaraları 0 ile 100 arasında random olarak atanıyor.

		// Döngüden çıkmadan doğum tarihleri random olarak atanıyor.
		dogum_gunu[i].gun =1+ rand() % 31;
		dogum_gunu[i].ay =1+ rand() % 13;
		dogum_gunu[i].yıl = 1990 + rand() % 33;

	}
}

// Verileri kullanıcının gireceği seçenek için oluşturulan fonksiyon. Kullanıcı istediği kadar öğrencinin verilerini  girecek.

void Kullanicidan_Isteme()

{

	
	cout << "Kaç öğrenci için işlem yapacaksınız ?";
	cin >> ogr_sayisi;
	
	
		for (int j = 0; j < ogr_sayisi; j++)     // Belirlenen öğrenci sayısına göre çalışan ve verileri kullanıcının girmesini sağlayan for döngüsü.
		{

			cout << "Öğrencinin adını giriniz: "; cin >> ogr[j].adi;
			cout << "Öğrencinin soyadını giriniz: "; cin >> ogr[j].soyadi;
			cout << "Öğrencinin numarasını giriniz: "; cin >> ogr[j].no;
			cout << "Öğrencinin kısa sınav 1 notu için geçerli bir not giriniz"; cin >> ogr[j].kisaSinav1; Not_Kontrol(ogr[j].kisaSinav1);
			cout << "Öğrencinin kısa sınav 2 notu için geçerli bir not giriniz"; cin >> ogr[j].kisaSinav2; Not_Kontrol(ogr[j].kisaSinav2);
		    cout << "Öğrencinin ödev 1 notu için geçerli bir not giriniz";cin>> ogr[j].ödev1; Not_Kontrol(ogr[j].ödev1);
			cout << "Öğrencinin ödev 2 notu için geçerli bir not giriniz",cin>> ogr[j].ödev2; Not_Kontrol(ogr[j].ödev2);
			cout << "Öğrencinin proje notu için geçerli bir not giriniz"; cin>>ogr[j].proje; Not_Kontrol(ogr[j].proje);
			cout << "Öğrencinin vize notu için geçerli bir not giriniz"; cin >> ogr[j].vize; Not_Kontrol(ogr[j].vize);
			cout << "Öğrencinin final notu için geçerli bir not giriniz"; cin >> ogr[j].final; Not_Kontrol(ogr[j].final);
			cout << "Öğrencinin doğum yılını giriniz :";
			cout << "Gün :"; cin >> dogum_gunu[j].gun;
			cout << "Ay :";  cin >> dogum_gunu[j].ay; 
			cout << "Yıl :"; cin >> dogum_gunu[j].yıl;
			cout << endl;

			// Döngüden çıkmadan yıl içi notu ve başarı notu hesaplanır.
			ogr[j].yil_ici_not = ogr[j].kisaSinav1 * 0.07 + ogr[j].kisaSinav2 * 0.07 + ogr[j].ödev1 * 0.10 + ogr[j].ödev2 * 0.10 + ogr[j].proje * 0.16 + ogr[j].vize * 0.50;
			ogr[j].basari_notu = ogr[j].yil_ici_not * 0.55 + ogr[j].final * 0.45;

			system("cls");

		}
}

// Öğrencilerin liste şeklinde yazdırılmasını sağlayan fonksiyon.
void Ogrenci_Listeleme()
{
	for (int i =1; i <=ogr_sayisi; i++)          //   Öğrenci isimlerininin,numaralarının doğum yıllarının ve harf notlarının yirmişer yirmişer yazdırılmasını sağlıyor.
	{

		cout << "Öğrenci no: "<<setw(5)<<ogr[i].no << setw(15) << "Doğum yılı :" << dogum_gunu[i].gun << "." << dogum_gunu[i].ay << "." << dogum_gunu[i].yıl << setw(10) << ogr[i].adi << setw(6) << ogr[i].soyadi << setw(20); Harf_Notu(ogr[i].basari_notu);

		if (i % 20 == 0)
		{
			system("pause");
			system("cls");
		}

	}

}
// Max başarı notunu bulan fonksiyon
int Max_Bulma ()
{
	float max = 0;

	for (int i = 0; i < ogr_sayisi; i++)  // Öğrencilerin başarı notlarını karşılaştırır ve max bulur.
	{
		if (ogr[i].basari_notu > max)   
			max = ogr[i].basari_notu;
	}

	return max;

}

//Min başarı notunu bulan fonksiyon
int Min_Bulma()
{
	float min = 100000;
	for (int i = 0; i < ogr_sayisi; i++)         // Öğrencilerin başarı notlarını karşılaştırır ve min bulur.
	{
		if (ogr[i].basari_notu < min)
			min = ogr[i].basari_notu;
	}

	return min;
}

//Sınıf ortalamasını bulan fonksiyon
float Sinif_Ortalama()
{
	int toplam = 0;
	float ortalama;
	for (int i = 0; i < ogr_sayisi; i++)     // Öğrencilerin başarı notlarını toplam değişkeninde toplar ve  toplamı öğrenci sayısına böler.
	{
		toplam += ogr[i].basari_notu;
	
	}
	ortalama = toplam / ogr_sayisi;

	return ortalama;
}

// Satandart sapmayı bulan fonksiyon
float Standart_Sapma()
{
	float standart = 0;
	float ortalama= Sinif_Ortalama();
	// Standart değişkeninde standart sapmayı bulmak için işlemler yapar.
	for (int i = 0; i < ogr_sayisi; i++)    
	{
		
		standart += pow(ogr[i].basari_notu - ortalama, 2);

	}
	standart = standart / (100 - 1);
	standart = sqrt(standart);
	return standart;
}


// Notu ,girilen iki değer arasındaki öğrencilerin isimlerini ve notlarını yazdıran fonksiyon
void Belirli_Deger_Arasindaki_Ogrenci(int x,int y)
{
	// Öğrenci notlarının girilen iki değer arasında olup olmadığını kontrol eder ve iki değer arasında olanları yazdırır.
	for (int i = 0; i < ogr_sayisi; i++)       
	{
		if (x <= ogr[i].basari_notu && ogr[i].basari_notu<=y || x >= ogr[i].basari_notu && ogr[i].basari_notu >=y)
		{
			
			cout << ogr[i].adi << setw(6) << ogr[i].soyadi<< setw(10) << ogr[i].basari_notu << endl;

		}
	}
}

// Notu ,girilen değerin altındaki öğrencilerin isimlerini ve notlarını yazdıran fonksiyon.
void Belli_Degerin_Altindaki_Ogrenci(int x)
{
	//Girilen değerden küçük nota sahip öğrenciler bulunur ve yazdırılır.
	for (int i = 0; i < ogr_sayisi; i++)    
	{
		if(ogr[i].basari_notu<x)
			cout << ogr[i].adi<<setw(6)<<ogr[i].soyadi<< setw(10) << ogr[i].basari_notu << endl;

	}

}

// Notu, girilen değerin üstünde olan öğrencilerin isimlerini ve notlarını yazdıran fonksiyon.
void Belli_Degerin_Ustundeki_Ogrenci(int x)
{

	for (int i = 0; i < ogr_sayisi; i++)
	{
		if(ogr[i].basari_notu>x)
			cout<< ogr[i].adi << setw(6) << ogr[i].soyadi << setw(10) << ogr[i].basari_notu << endl;

	}


}
// Sayısal notu harf notuna çeviren fonksiyon.
void Harf_Notu(int puan)
{

	if (puan <= 100 && puan >= 90)
	{
		cout << "Harf notu : AA" << endl;
	}
	else if (puan < 90 && puan >= 85)
	{
		cout << "Harf notu : BA" << endl;
	}
	else if (puan < 85 && puan >= 80)
	{
		cout << "Harf notu : BB" << endl;
	}
	else if (puan < 80 && puan >= 75)
	{
		cout << "Harf notu : CB" << endl;
	}
	else if (puan < 75 && puan >= 65)
	{
		cout << "Harf notu : CC" << endl;
	}
	else if (puan < 65 && puan >= 60)
	{
		cout << "Harf notu : DC" << endl;
	}
	else if (puan < 60 && puan >= 55)
	{
		cout << "Harf notun : DD" << endl;
	}
	else if (puan < 55 && puan >= 50)
	{
		cout << "Harf notu : FD" << endl;
	}
	else if (puan < 50 && puan >= 0)
	{
		cout << "Harf notu : FF" << endl;
	}

}
// Girilen notun 0 ile 100 arasında olup olmadığını kontrol eden fonksiyon.
 void Not_Kontrol( float x)
{
	// Not 0 ile 100 arasında değilse geçerli not girilene kadar dönen döngü.
	 while (!(x >= 0 && x <= 100))
	 {
		 cout << " Geçerli bir değer giriniz.";
		 cin >> x;
	  }
	 
	
}