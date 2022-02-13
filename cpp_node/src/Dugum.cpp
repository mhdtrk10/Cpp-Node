/**
* @file Dugum
*/
#include "Dugum.hpp"
#include<iostream>
using namespace std;
Dugum::Dugum(string veri)
{
    this->veri=veri;
    this->sonraki=0;
    this->onceki=0;
}
Dugum::~Dugum()
{
    //cout<<veri<<": dugumu silindi!"<<endl;
    cout<<endl;
}