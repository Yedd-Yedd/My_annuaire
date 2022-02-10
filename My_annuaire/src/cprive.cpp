#include "headers/cprive.h"
#include "headers/adress.h"

CPrive::CPrive(Adress addr, string date, int id, string nom, string prenom, char genre):
Contact(id, nom, prenom, genre)

{
    this->setAddr(addr);
    this->setDate_naissance(date);
}

Adress* CPrive::getAddr() const
{
    return addr;
}

void CPrive::setAddr(Adress *value)
{
    addr = value;
}

string CPrive::getDate_naissance() const
{
    return date_naissance;
}

void CPrive::setDate_naissance(const string &value)
{
    date_naissance = value;
}

Adress CPrive::getAddr() const
{
    return addr;
}

void CPrive::setAddr(const Adress &value)
{
    addr = value;
}

string CPrive::getDate() const
{
    return date;
}

void CPrive::setDate(const string &value)
{
    date = value;
}
