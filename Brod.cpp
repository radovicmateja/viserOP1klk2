//
// Created by mateja on 5/7/24.
//

#include <cstring>
#include "Brod.h"

int Brod::brojProizvedenih = 0;

Brod::Brod() {
    naziv = "NONAME";
    cena = 0.0;
}

Brod::Brod(const char *nazivliteral) {
    naziv = nazivliteral;
    cena = 0.0;
    brojProizvedenih++;
}

Brod::Brod(const char* naziv, float cena) : naziv(naziv), cena(cena) {
    brojProizvedenih++;
}

const char * Brod::getNaziv() volatile {
    return naziv;
}

float* Brod::UzmiCenu(){
    return &cena;
}

float Brod::getCena() volatile {
    return cena;
}


void Brod::IspisiPodatke() volatile {
    std::cout << "(" << getNaziv() << ", " << getCena() << ")" << std::endl;

}

int Brod::GetBrojProizvedenihBrodovaULukama() {
    return brojProizvedenih;
}

void Brod::IspisiBinarnoObjekat(){
    //prvo naziv
    std::cout << "Objekat binarno: " << std::endl;
    for (int i = 0; i < strlen(naziv); ++i) {
        std::cout << std::bitset<8>(naziv[i]) << " ";
        if((i+1) % 4 == 0) std::cout << std::endl;
    }
    //cena
    auto* ptr = reinterpret_cast<unsigned char*>(&cena);

    for (int i = 3; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (ptr[i] & (1 << j)) {
                std::cout << "1";
                //brojSetovanihBita++;
            }
            else
                std::cout << "0";
            if (j == 0) std::cout << " ";
        }
        if (i == 2) std::cout << std::endl;
    }
}

int Brod::IzracunajBrojSetovanihBitaObjekata(Brod * luka) {
    int brojac = 0;
    auto novaCena = luka->cena;
    auto *ptr = reinterpret_cast<unsigned char *>(&novaCena);
    for (int i = 3; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (ptr[i] & (1 << j)) {
                brojac++;
            }
        }
    }
    return brojac;
}

void Brod::IspisiKriptovano(const char *tekst) {
    int bj = 0;
    // slovo je kriptovano xor brojem koji odgovara broju 1-ica njegove binarne predstave
    for (int i = 0; i <= (strlen(tekst)-1); i++) {
        for (int j = 7; j >= 0; j--) {
            if (tekst[i] & (1 << j))
                bj++;
        }
        auto kriptovan = std::bitset<8>(tekst[i]) ^ std::bitset<8>(bj);
        bj = 0;
        char slovo = kriptovan.to_ulong();
        std::cout << slovo;
    }

}
