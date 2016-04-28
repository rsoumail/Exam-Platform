#include "groupe.h"
#include <QString>
#include <fstream>

using namespace std;



int Groupe::id() const
{
    return id_;
}

QString Groupe::nom() const
{
    return nom_;
}

Groupe::Groupe()
{

    id_ = 0;
    nom_ = "";

}

Groupe::Groupe(int id, QString nom)
{

  this->id_ = id;
  this->nom_ = nom;


}

Groupe::Groupe(const Groupe& g)
{

  this->id_ = g.id_;
  this->nom_ = g.nom_;

}

Groupe& Groupe::operator=(const Groupe& g)
{

  this->id_ = g.id_;
  this->nom_ = g.nom_;
  return *this; 

}

ostream& operator<<(ostream&, const Groupe& g)
{

  

}

istream& operator>>(istream&, Groupe& g)
{

  

}

void Groupe::setNom(QString nom)
{
  this->nom_ = nom;
}

void Groupe::setId(int id)
{
  this->id_ = id;
}


Groupe::~Groupe()
{

  

}

