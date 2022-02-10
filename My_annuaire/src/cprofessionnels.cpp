#include "headers/cprofessionnels.h"

CProfessionnels::CProfessionnels(string nomE, string mail, Adress addr, int id, string nom, string prenom, char genre) :
Contact(id, nom, prenom, genre)
{
    this->setAddr(&addr);
    this->setMail(mail);
    this->setNomE(nomE);
}

string CProfessionnels::getNomE() const
{
    return nomE;
}

void CProfessionnels::setNomE(const string &value)
{
    nomE = value;
}

string CProfessionnels::getMail() const
{
    return mail;
}

void CProfessionnels::setMail(const string &value)
{
    mail = value;
}

Adress *CProfessionnels::getAddr() const
{
    return addr;
}

void CProfessionnels::setAddr(Adress *value)
{
   addr = value;
}
