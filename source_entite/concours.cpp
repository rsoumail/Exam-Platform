#include "concours.h"

int Concours::id() const
{
    return id_;
}

QString Concours::annee() const
{
    return annee_;
}

int Concours::age_limite() const
{
    return age_limite_;
}

QString Concours::date_limite() const
{
    return date_limite_;
}

QString Concours::date_resultats() const
{
    return date_resultats_;
}

int Concours::statut() const
{
    return statut_;
}

Concours::Concours()
{
    age_limite_ = 100;
    date_limite_ = "";
    date_resultats_ = "";
    statut_ = 1;

}

Concours::Concours(QString annee, int age_limite, QString date_limite)
{
 this->annee_ = annee;
  this->age_limite_ = age_limite;
  this->date_limite_ = date_limite;
  this->date_resultats_ = "";;
  this->statut_ = 1;

}

Concours::Concours(const Concours& c)
{

  this->id_ = c.id_;
  this->annee_ = c.annee_;
  this->age_limite_ = c.age_limite_;
  this->date_limite_ = c.date_limite_;
  this->date_resultats_ = c.date_resultats_;
  this->statut_ = c.statut_;
  
}

Concours& Concours::operator=(const Concours& c)
{

   this->id_ = c.id_;
   this->annee_ = c.annee_;
   this->age_limite_ = c.age_limite_;
   this->date_limite_ = c.date_limite_;
   this->date_resultats_ = c.date_resultats_;
   this->statut_ = c.statut_;
   return *this;

}

ostream& operator<<(ostream&, const Concours& c)
{

  

}

istream& operator>>(istream&, Concours& c)
{

  

}

void Concours::setId(int id)
{
  this->id_ = id;
}

void Concours::setAnnee(QString annee)
{
  this->annee_ = annee;
}

void Concours::setAge_limite(int age_limite)
{
  this->age_limite_ = age_limite;
}

void Concours::setDate_limite(QString date_limite)
{
  this->date_limite_ = date_limite;
}

void Concours::setDate_resultats(QString date_resultats)
{
  this->date_resultats_ = date_resultats;
}

void Concours::setStatut(int statut)
{
  this->statut_= statut;
}


Concours::~Concours()
{

  

}

