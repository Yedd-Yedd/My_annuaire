#include "headers/cprofessionnels.h"

CProfessionnels::CProfessionnels(string nomE, string mail, Adress *addr, int id, string nom, string prenom, char genre) :
Contact(id, nom, prenom, genre)
{
    this->setAddr(addr);
    this->setMail(mail);
    this->setNomE(nomE);
}

string CProfessionnels::getNomE() const
{
    return nomE;
}

void CProfessionnels::setNomE(const string &value)
{
    string res=value;
    if(value.length()<=50){
        for(int i=0;i<res.length();i++){
            res[i]=toupper(res[i]);
        }
        this->nomE=res;
    }
    else{
        throw "Erreur dans le Nom";
    }
}

string CProfessionnels::getMail() const
{
    return mail;
}

void CProfessionnels::setMail(const string &value)
{
    regex reg(".*@([a-z]|[A-Z])*\\.(com|fr)");
    if(regex_match(value,reg)){
        this->mail=value;
    }
    else{
        throw "Erreur mail";
    }
}

Adress *CProfessionnels::getAddr() const
{
    return addr;
}

void CProfessionnels::setAddr(Adress *value)
{
    addr = value;
}

string CProfessionnels::toString()
{
    string contact=Contact::toString();
    ostringstream oss;
    oss<< "Nom entreprise : "<<this->getNomE()<<endl;
    oss<< "Mail :"<<this->getMail()<<endl;
    contact += oss.str() + getAddr()->toString();
    return contact;
}

