#include "headers/adress.h"

string Adress::getLibel() const
{
    return libel;
}

void Adress::setLibel(const string &value)
{
    libel = value;
}

string Adress::getComp() const
{
    return Comp;
}

void Adress::setComp(const string &value)
{
    Comp = value;
}

string Adress::getVille() const
{
    return ville;
}

void Adress::setVille(const string &value)
{
    ville = value;
}

string Adress::getCp() const
{
    return cp;
}

void Adress::setCp(const string &value)
{
    cp = value;
}

Adress::Adress()
{

}

int Adress::getAddr_num() const
{
    return addr_num;
}

void Adress::setAddr_num(int value)
{
    addr_num = value;
}
