/**
* @file BagliListe 
*/
#include <iostream>
#include "BagliListe.hpp"
#include "Kisi.hpp"
#include<iomanip>
#include<string>
using namespace std;


BagliListe::BagliListe()
{
    ilk=0;
    uzunluk=0;
    
}
BagliListe::~BagliListe()
{
    Dugum* gec=ilk;

    while (gec!=0)
    {
        Dugum* sil=gec;
        gec=gec->sonraki;
        delete sil;

    }
}
void BagliListe::Sil(int index)
{   
    
    if(index>uzunluk)
    {//sonuncu elemanı silecek
        if(ilk==0) return;
        if(ilk->sonraki==0)//tek eleman ise
        {
            delete ilk;
            ilk=0;
        }
        else// 3 4 5
        {   
            
            Dugum* gec=ilk;
            
            while (gec->sonraki->sonraki!=0)
            {   
                
                gec=gec->sonraki;
               
            }
            delete gec->sonraki;
            gec->sonraki=0;
            uzunluk--;
        }
    }
    else
    {//indisteki elemanı silecek
        if(ilk==0) return;
        if(ilk->sonraki==0)//tek eleman ise
        {
            delete ilk;
            ilk=0;
        }
        else
        {
            Dugum* gec=ilk;

            while (gec->sonraki!=0)
            {
                gec=gec->sonraki;
            }

            Dugum* gec2=gec;

        
            for(int i=0;i<(uzunluk-index-2);i++)
            {   
                
                gec2=gec2->onceki;
            }
            
            
            for(int i=0;i<(uzunluk-index-1);i++)
            {   
                gec2->onceki->veri=gec2->veri;
                gec2=gec2->sonraki;
                
            }
            
            Dugum* gec3=ilk;
            
            while (gec3->sonraki->sonraki!=0)
            {
                gec3=gec3->sonraki;
            }
            delete gec3->sonraki;
            gec3->sonraki=0;   
            uzunluk--;
        }


    }
    
    
}
void BagliListe::Yazdir()
{  
    Dugum* gec=ilk;
    
    while (gec!=0)
    {   
        cout<<gec->veri<<"<-->";
        gec=gec->sonraki;
        
    }
    
}
void BagliListe::Ekle(string isim,int index)
{
    Dugum* yeni= new Dugum(isim);
    if(index>uzunluk)
    {//sona ekle çalışacak
        SonaEkle(isim);      
    }
    else
    {//araya ekle çalışacak    
        Dugum* gec=ilk;
        ArayaEkle(index,isim); 
    }

}
void BagliListe::SonaEkle(string isim)
{
    Dugum* yeni= new Dugum(isim);

        if(ilk==0)
        {
        ilk=yeni;
        yeni->onceki=NULL;
        yeni->sonraki=NULL;
        
        }
        else
        {
            Dugum* gec=ilk;
        
            while (gec->sonraki!=0)
            {

                gec=gec->sonraki;

            }
            gec->sonraki=yeni;
            yeni->onceki=gec;
            yeni->sonraki=0;
 
        }
        uzunluk++;
        
}
void BagliListe::IlkEkle(string isim)
{
    Dugum* yeni= new Dugum(isim);

    if(ilk==0)
    {
    ilk=yeni;
    yeni->onceki=NULL;
    yeni->sonraki=NULL;
    
    }
    else
    {
        Dugum* gec=ilk;
        
        while (gec->sonraki!=0)
        {

            gec=gec->sonraki;

        }
        gec->sonraki=yeni;
        yeni->onceki=gec;
        yeni->sonraki=0;
        
    }
    uzunluk++;
    
}
void BagliListe::ArayaEkle(int index,string isim)
{   
    Dugum* yeni= new Dugum("");

    if(ilk==0)
    {
        ilk=yeni;
        yeni->onceki=NULL;
        yeni->sonraki=NULL;
    }
    else
    {
        Dugum* gec=ilk;

        while (gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }
        gec->sonraki=yeni;
        yeni->onceki=gec;
        yeni->sonraki=0;
        
        Dugum* gec2=yeni;
  
        for(int i=0;i<(uzunluk-index);i++)
        {
            gec2->veri=gec2->onceki->veri;
            gec2=gec2->onceki;
        }
        gec2->veri=isim;
        uzunluk++;
    }

}