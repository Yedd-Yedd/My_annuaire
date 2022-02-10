#ifndef CPRIVE_H
#define CPRIVE_H

#include "contact.h"
#include "adress.h"
#include <iostream>
#include <cstring>
#include <string>


#include <QDebug>

class CPrive : public Contact
{
private:
    Adress *addr;
    string date_naissance;
public:
    CPrive(Adress*, string, int, string, string, char);
    ~CPrive();
    Adress *getAddr() const;
    void setAddr(Adress *value);
    string getDate_naissance() const;
    void setDate_naissance(const string &value);
};

#endif // CPRIVE_H
