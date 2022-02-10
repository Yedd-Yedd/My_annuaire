#include "cprofessionnels.h"

CProfessionnels::CProfessionnels()
{

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

Adress CProfessionnels::getAddr() const
{
    return addr;
}

void CProfessionnels::setAddr(const Adress &value)
{
    addr = value;
}
