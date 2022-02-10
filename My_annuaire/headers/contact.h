#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Contact
{
private:
    string nom;
    string prenom;
    char genre;
    int id;
public:
    Contact(int, string, string, char);
    ~Contact();
    
    string getNom() const;
    void setNom(const string &value);
    string getPrenom() const;
    void setPrenom(const string &value);
    char getGenre() const;
    void setGenre(char value);
    int getId() const;
    void setId(int value);

    string toString();
};

#endif // CONTACT_H
