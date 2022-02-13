#ifndef Dugum_hpp
#define Dugum_hpp
#include "Kisi.hpp"

using namespace std;
class Dugum
{
    public:
    Dugum(string veri);
    ~Dugum();
    string veri;
    Dugum* sonraki;
    Dugum* onceki;

};

#endif