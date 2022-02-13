/**
* We apply operations to the node structure we have available, according to the lines
* we read from the file. If S reads, we update the node by deleting, if E reads adding.
*/
#include <iostream>
#include<fstream>
#include "BagliListe.hpp"
using namespace std;



int main()
{
    BagliListe* p=new BagliListe();
    
    p->IlkEkle("ahmet");
    p->IlkEkle("mehmet");
    p->IlkEkle("seval");
    p->IlkEkle("murat");
    p->IlkEkle("mehdi");
    p->IlkEkle("gokhan");
    p->IlkEkle("yakup");
    p->IlkEkle("hasan");
    p->IlkEkle("burak");
    p->IlkEkle("kemal");
    p->IlkEkle("hayrettin");


    

    p->Yazdir();
    
    
    
    
    ifstream dosyaoku("veri.txt");
    string str;
    if(dosyaoku.is_open())
    {
        
        for(int i=0;getline(dosyaoku,str);i++)
        {   
            if(str[0]=='E'||str[0]=='e')
            {
            string delimiter = "#";
            string delimiter2= ")";
            
			string indis = str.substr(2, str.find(delimiter)-2);
            str.erase(str.find(delimiter2));
            string name  = str.substr(str.find(delimiter)+1, str.find(delimiter2));
            
            
            p->Ekle(name,stoi(indis));
                
            }
            if(str[0]=='S'||str[0]=='s')
            {
            string delimiter = ")";
            
			string indis = str.substr(2, str.find(delimiter)-2);
            

            p->Sil(stoi(indis));
            
                
            }

        }
        
    }
    
    
    
    p->Yazdir();
   
    
    
}