#include "headers/cprive.h"
#include "headers/adress.h"

CPrive::CPrive()
{

}

Adress CPrive::getAddr() const
{
    return addr;
}

void CPrive::setAddr(const Adress &value)
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
