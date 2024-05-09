// Postavka zadatka. Ne menjati main.

#include <iostream>
#include "Brod.h"
using namespace std;
#define BROJ 3

int main() {

    // a)
    volatile Brod brodV("SEASUN", 15000.0); //naziv i cena
    brodV.IspisiPodatke(); cout << endl; //ispis u obliku (SEASUN, 15000)

    // b)
    Brod* luka_1 = new Brod[BROJ]; //naziv i cena su inicijalno "NONAME" i 0.0
    *luka_1[0].UzmiCenu() = 2000.0;
    for (int i = 0; i < BROJ; ++i) {
        luka_1[i].IspisiPodatke();
    }
    cout << endl;

    // c)
    Brod luka_2[2] = { "KANU" , "KATAMARAN" };
    for (auto i = 0; i < sizeof(luka_2) / sizeof(Brod); ++i){
        luka_2[i].IspisiPodatke();
        cout << endl;
    }
    cout << "Ukupno proizvedenih brodova u lukama: " << Brod::GetBrojProizvedenihBrodovaULukama() << endl << endl;


    // d)
    luka_1[0].IspisiBinarnoObjekat(); //32 bita po jednom redu, razmak iza svakog osmog bita
    cout << endl << Brod::IzracunajBrojSetovanihBitaObjekata(&luka_1[0]) << endl;

    // e)
    // slovo je kriptovano xor brojem koji odgovara broju 1-ica njegove binarne predstave
    Brod::IspisiKriptovano("ABCDE"); cout << endl;


    delete[] luka_1;
    return 0;
}
