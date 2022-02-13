#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"

using namespace std;
class  BagliListe
{
public:
BagliListe();
~BagliListe();


void Yazdir();
void Sil(int index);
void Ekle(string isim,int index);
void IlkEkle(string isim);
void SonaEkle(string isim);
void ArayaEkle(int index,string isim);
private:
Dugum* ilk;
int uzunluk;


};


#endif