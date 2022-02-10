#include "contact.h"

Contact::Contact()
{

}

string Contact::getNom() const
{
    return nom;
}

void Contact::setNom(const string &value)
{
    nom = value;
}

string Contact::getPrenom() const
{
    return prenom;
}

void Contact::setPrenom(const string &value)
{
    prenom = value;
}

char Contact::getGenre() const
{
    return genre;
}

void Contact::setGenre(char value)
{
    genre = value;
}

int Contact::getId() const
{
    return id;
}

void Contact::setId(int value)
{
    id = value;
}
