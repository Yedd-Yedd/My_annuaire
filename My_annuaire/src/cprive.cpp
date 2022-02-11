#include "headers/cprive.h"
#include "headers/adress.h"

CPrive::CPrive(Adress *addr, string date, int id, string nom, string prenom, char genre):
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
    if (value != nullptr)
        addr = value;
    else {

        qDebug() << "CPrive.setAddr(*value) << value is null";
    }
}

string CPrive::getDate_naissance() const
{
    return date_naissance;
}

void CPrive::setDate_naissance(const string &value)
{
  if (checkStringVal(value) == true)
  {
      const char *tmp = value.c_str();
      size_t i = -1;
      int bs = 0;
      while (tmp[++i] != '\0'){
          if ((tmp[i] == '/' && i == 2) ||
              (tmp[i] == '/' && i == 5))
               bs++;
      }
      i = 0;
      while(tmp[i] != '\0'){
          if (tmp[i] == '/' || (tmp[i] >= '0' && tmp[i] <= '9'))
            i++;
          else
              break;
      }

      qDebug() << "le i= " << i;
      if (bs == 2 && i == strlen(tmp)){
          this->date_naissance = value;
          qDebug()<<"date valid";
      }
      else {
          qDebug("date invalid");
      }
  }
  else {
      qDebug() << "CPrive.setDate_naissance(value) << value is empty";
  }

}
