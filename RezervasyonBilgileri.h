#pragma once
#include <iostream>
#include <string>

using namespace std;

class RezervasyonBilgileri {
private:
	string rezervSaati, rezervTarihi, rezervMasaNo;
	int kisiSayisi;
public:
	RezervasyonBilgileri() = default;
	RezervasyonBilgileri(string, string, string, int);
	void ekranaYaz();

	friend class MusteriBilgileri;
};
RezervasyonBilgileri::RezervasyonBilgileri(string saat, string tarih, string masa, int kisi) {
	rezervSaati = saat;
	rezervTarihi = tarih;
	rezervMasaNo = masa;
	kisiSayisi = kisi;
}
void RezervasyonBilgileri::ekranaYaz() {
	cout << "Rezervasyon Bigileri :" << endl << rezervSaati << endl << rezervTarihi << endl << rezervMasaNo << endl << kisiSayisi << endl;
}
