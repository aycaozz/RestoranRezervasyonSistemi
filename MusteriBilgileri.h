#include <iostream>
#include <string>
#include "RezervasyonBilgileri.h"

class MusteriBilgileri {
private:
	std::string ad;
	std::string soyad;
	std::string numara;

public:
	RezervasyonBilgileri rezervasyon; //nesne oluþtururuz rezervasyonBilgileri sýnýfýndan
	string MusteriIsmi;
	string MusteriNumarasi;

	MusteriBilgileri(string, string);
	void ekranaYaz();//ekrana yaz fonksiyonunu kullanýrýz
};
 
MusteriBilgileri::MusteriBilgileri(string isim, string numara) {

	MusteriIsmi = isim;
	MusteriNumarasi = numara;
	
}void MusteriBilgileri::ekranaYaz() {
	rezervasyon.ekranaYaz();
	cout << "Musteri Bilgileri: " << endl << MusteriIsmi << endl << MusteriNumarasi << endl;

}