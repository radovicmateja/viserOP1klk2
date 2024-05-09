//
// Created by mateja on 5/7/24.
//
#include <iostream>
#include <bitset>
#pragma once


class Brod {
    const char *naziv;
    float cena;
    static int brojProizvedenih;
public:
    Brod();
    Brod(const char* naziv);
    Brod(const char* naziv, float cena);

    const char * getNaziv() volatile;

    float* UzmiCenu();
    float getCena() volatile;

    void IspisiPodatke() volatile;

    static int GetBrojProizvedenihBrodovaULukama();
    void IspisiBinarnoObjekat();
    static int IzracunajBrojSetovanihBitaObjekata(Brod* luka);
    static void IspisiKriptovano(const char* tekst);
};
