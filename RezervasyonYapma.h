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

        //burda ise döngüleri kullnararak rezerve edilme durumlarýna göre fonksiyonlarý tek tek ele alýyoruz.
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
                std::cout << "Bu masa zaten rezerve edilmemiþ." << std::endl;
            }
        }

        bool isRezerveEdildi() const {
            return rezerveEdildi;
        }

        //set ve get kullanarak private olan fonksiyonu altta kullanmayý saðladýk

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
                    std::cout << "Masa " << masa.getName() << ": " << (masa.isRezerveEdildi() ? "Rezerve Edildi" : "Boþ") << std::endl;
                }
            }

            void masaRezervasyonuYap(int masaNumarasi) {
                if (masaNumarasi > 0 && masaNumarasi <= masalar.size()) {
                    masalar[masaNumarasi - 1].rezervasyonYap();
                }
                else {
                    std::cout << "Geçersiz masa numarasý." << std::endl;
                }
            }

            void masaRezervasyonIptal(int masaNumarasi) {
                if (masaNumarasi > 0 && masaNumarasi <= masalar.size()) {
                    masalar[masaNumarasi - 1].rezervasyonIptal();
                }
                else {
                    std::cout << "Geçersiz masa numarasý." << std::endl;
                }
            }
        };

    public:
        int main() {
            Restoran restoran(10);  // 10 masa içeren bir restoran oluþturarak s

            // Rezervasyonlar yapalým
            restoran.masaRezervasyonuYap(2);
            restoran.masaRezervasyonuYap(5);

            // Rezervasyonlarý göster
            restoran.masalariGoster();

            // Rezervasyonlarý iptal edelim
            restoran.masaRezervasyonIptal(3);

            // Ýptal sonrasý rezervasyonlarý göster
            restoran.masalariGoster();

            return 0;
        }
    };

