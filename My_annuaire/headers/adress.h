#ifndef ADRESS_H
#define ADRESS_H

#include<iostream>

using namespace std;

class Adress
{

private:
    int addr_num;
    string libel;
    string Comp;
    string ville;
    string cp;
public:
    Adress();
    ~Adress();

    int getAddr_num() const;
    void setAddr_num(int value);
    string getLibel() const;
    void setLibel(const string &value);
    string getComp() const;
    void setComp(const string &value);
    string getVille() const;
    void setVille(const string &value);
    string getCp() const;
    void setCp(const string &value);
};

#endif // ADRESS_H
