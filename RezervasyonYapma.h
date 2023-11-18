#pragma once
#include <iostream>
#include <vector>

class RezervasyonYapma {
private:

    class Masa {
    private:

        bool rezerveEdildi;
        int masaNumarasi;
    public:

       // Masa(int numara) : masaNumarasi(numara), rezerveEdildi(false) {}

        //burda ise d�ng�leri kullnararak rezerve edilme durumlar�na g�re fonksiyonlar� tek tek ele al�yoruz.
        void rezervasyonYap() {
            if (!rezerveEdildi) {
                rezerveEdildi = true;
                std::cout << "Masa " << masaNumarasi << " rezerve edildi." << std::endl;
            }
            else {
                std::cout << "Masa " << masaNumarasi << " zaten rezerve edildi." << std::endl;
            }
        }

        void rezervasyonIptal() {
            if (rezerveEdildi) {
                rezerveEdildi = false;
                std::cout << "Masa " << masaNumarasi << " rezervasyonu iptal edildi." << std::endl;
            }
            else {
                std::cout << "Bu masa zaten rezerve edilmemi�." << std::endl;
            }
        }

        bool isRezerveEdildi() const {
            return rezerveEdildi;
        }

        //set ve get kullanarak private olan fonksiyonu altta kullanmay� sa�lad�k

        void setName(const int& numara) {
            masaNumarasi = numara;
        }

        int getName() const {
            return masaNumarasi;
        }
    };

        class Restoran {
       
        private:
            std::vector<Masa> masalar;

        public:


        public:
            Restoran(int masaSayisi) {
                for (int i = 1; i <= masaSayisi; ++i) {
                    Masa masa;
                    masa.setName(i);
                    masalar.push_back(masa);
                }
            }

            void masalariGoster() const {
                for (const Masa& masa : masalar) {
                    std::cout << "Masa " << masa.getName() << ": " << (masa.isRezerveEdildi() ? "Rezerve Edildi" : "Bo�") << std::endl;
                }
            }

            void masaRezervasyonuYap(int masaNumarasi) {
                if (masaNumarasi > 0 && masaNumarasi <= masalar.size()) {
                    masalar[masaNumarasi - 1].rezervasyonYap();
                }
                else {
                    std::cout << "Ge�ersiz masa numaras�." << std::endl;
                }
            }

            void masaRezervasyonIptal(int masaNumarasi) {
                if (masaNumarasi > 0 && masaNumarasi <= masalar.size()) {
                    masalar[masaNumarasi - 1].rezervasyonIptal();
                }
                else {
                    std::cout << "Ge�ersiz masa numaras�." << std::endl;
                }
            }
        };

    public:
        int main() {
            Restoran restoran(10);  // 10 masa i�eren bir restoran olu�turarak s

            // Rezervasyonlar yapal�m
            restoran.masaRezervasyonuYap(2);
            restoran.masaRezervasyonuYap(5);

            // Rezervasyonlar� g�ster
            restoran.masalariGoster();

            // Rezervasyonlar� iptal edelim
            restoran.masaRezervasyonIptal(3);

            // �ptal sonras� rezervasyonlar� g�ster
            restoran.masalariGoster();

            return 0;
        }
    };

