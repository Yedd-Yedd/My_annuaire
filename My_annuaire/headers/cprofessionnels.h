#ifndef CPROFESSIONNELS_H
#define CPROFESSIONNELS_H

#include "adress.h"
#include "headers/contact.h"
#include <regex>
#include <QDebug>
#include <sstream>

class CProfessionnels : public Contact
{
private:
    string nomE;
    string mail;
    Adress *addr;
public:
    CProfessionnels(string, string, Adress*, int, string, string, char);
    //~CProfessionnels();
    string getNomE() const;
    void setNomE(const string &value);
    string getMail() const;
    void setMail(const string &value);
    Adress *getAddr() const;
    void setAddr(Adress *value);

    string toString();
};

#endif // CPROFESSIONNELS_H
