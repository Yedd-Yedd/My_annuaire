#include "headers/adress.h"

#include <QDebug>

Adress::Adress(int num, string libel, string cp, string ville, string comp)
{
    this->setAddr_num(num);
    this->setCp(cp);
    this->setLibel(libel);
    this->setVille(ville);
    this->setComp(comp);
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
    qDebug()<<value.length();
    if(value.length()==5){
        cp = value;
    }
    else{
        throw "Erreur dans le cp";
    }
}

int Adress::getAddr_num() const
{
    return addr_num;
}

void Adress::setAddr_num(int value)
{
    addr_num = value;
}

string Adress::getLibel() const
{
    return libel;
}

string Adress::toString()
{
    ostringstream oss;
    oss<<"Adresse : "<<this->getAddr_num()<<" "<<this->getLibel()<<" "<<getComp()<<endl;
    oss<<"Code postal : "<<this->getCp();
    oss<<"Ville : "<<this->getVille();
    return oss.str();
}
