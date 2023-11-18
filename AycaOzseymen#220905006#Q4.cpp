#include <iostream>
#include <string>
#include "RezervasyonBilgileri.h"

//Restoran rezervasyon sistemi konusunu seçtim ve 3 ayrı class oluşturdum(Rezervasyon bilgileri, Müsteri bilgileri ve Rezervasyon yapma)
using namespace std;

class MusteriBilgileri {
private:
	std::string ad;
	std::string soyad;
	std::string numara;

public:
	RezervasyonBilgileri rezervasyon; //nesne oluştururuz rezervasyonBilgileri sınıfından
	string MusteriIsmi;
	string MusteriNumarasi;

	MusteriBilgileri(string, string);
	void ekranaYaz();//ekrana yaz fonksiyonunu kullanırız
};

MusteriBilgileri::MusteriBilgileri(string isim, string numara) {

	MusteriIsmi = isim;
	MusteriNumarasi = numara;

}void MusteriBilgileri::ekranaYaz() {
	rezervasyon.ekranaYaz();
	cout << "Musteri Bilgileri: " << endl << MusteriIsmi << endl << MusteriNumarasi << endl;

}

int main() {
	RezervasyonBilgileri  rezervasyon("20:00", "20.10.2023", "no:15", 6);
	rezervasyon.ekranaYaz();

	return 0;
}
