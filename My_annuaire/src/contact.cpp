#include "../headers/contact.h"

#include <QDebug>

Contact::Contact(int id, string nom, string prenom, char genre)
{
    this->setId(id);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setGenre(genre);
}

/*Contact::~Contact()
{

}*/

string Contact::getNom() const
{
    return nom;
}

void Contact::setNom(const string &value)
{
    string res=value;
    if(value.length()<=30){
        for(int i=0;i<res.length();i++){
            res[i]=toupper(res[i]);
        }
        this->nom=res;
    }
    else{
        throw "Erreur dans le Nom";
    }
}

string Contact::getPrenom() const
{
    return prenom;
}

void Contact::setPrenom(const string &value)
{
    string res=value;
    if(value.length()<=30){
        res[0]=toupper(value[0]);
        this->prenom=res;
    }
    else{
        throw "Erreur dans le prenom";
    }

}

char Contact::getGenre() const
{
    return genre;
}

void Contact::setGenre(char value)
{
    if(value=='h' or value=='H' or value=='f' or value=='F'){
        genre = toupper(value);
    }
    else{
        throw "Erreur dans le genre";
    }
}

int Contact::getId() const
{
    return id;
}

void Contact::setId(int value)
{
    id = value;
}

string Contact::toString()
{
    ostringstream  oss;
    oss << "Id : "<<this->getId()<<endl;
    oss << "Nom : "<<this->getNom()<<endl;
    oss << "Prenom : "<<this->getPrenom()<<endl;
    oss << "Genre : : "<<this->getGenre()<<endl;
    return oss.str();
}

