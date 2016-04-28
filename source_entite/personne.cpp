#include "personne.h"


Personne::Personne()
{
    
    nom_ = "";
    prenom_ = "";
    sexe_ = "";
    civilite_ = "";
    date_naissance_ = "";
    nationalite_ = "";
    adresse_ = "";
    telephone_ = "";
    email_ = "";


}

Personne::Personne(QString nom, QString prenom, QString sexe, QString civilite, QString nationalite, QString adresse, QString date_naissance, QString telephone, QString email)
{

  this->nom_ = nom;
  this->prenom_ = prenom;
  this->sexe_ = sexe;
  this->civilite_ = civilite;
  this->date_naissance_ = date_naissance;
  this->nationalite_ = nationalite;
  this->adresse_ = adresse;
  this->telephone_ = telephone;
  this->email_ = email;


}

Personne::Personne(const Personne& p)
{

    this->nom_ = p.nom_;
    this->prenom_ = p.prenom_;
    this->sexe_ = p.sexe_;
    this->civilite_ = p.civilite_;
    this->date_naissance_ = p.date_naissance_;
    this->nationalite_ = p.nationalite_;
    this->adresse_ = p.adresse_;
    this->telephone_ = p.telephone_;
    this->email_ = p.email_;

}

Personne& Personne::operator=(const Personne& p)
{

    this->nom_ = p.nom_;
    this->prenom_ = p.prenom_;
    this->sexe_ = p.sexe_;
    this->civilite_ = p.civilite_;
    this->date_naissance_ = p.date_naissance_;
    this->nationalite_ = p.nationalite_;
    this->adresse_ = p.adresse_;
    this->telephone_ = p.telephone_;
    this->email_ = p.email_;
    return *this;

}

ostream& operator<<(ostream&, const Personne& p)
{

  

}

istream& operator>>(istream&, Personne& p)
{

  

}


void Personne::setNom(QString nom)
{
    this->nom_ = nom;
}

void Personne::setPrenom(QString prenom)
{
    this->prenom_ = prenom;
}

void Personne::setSexe(QString sexe)
{
    this->sexe_ = sexe;
}

void Personne::setCivilite(QString civilite)
{
    this->civilite_ = civilite;
}

void Personne::setNationalite(QString nationalite)
{
    this->nationalite_ = nationalite;
}

void Personne::setAdresse(QString adresse)
{
    this->adresse_ = adresse;
}

void Personne::setDate_naissance(QString date_naissance)
{
    this->date_naissance_ = date_naissance;
}

void Personne::setTelephone(QString telephone)
{
    this->telephone_ = telephone;
}

void Personne::setEmail(QString email)
{
    this->email_ = email;
}


QString Personne::nom() const
{
  return nom_;
}

QString Personne::prenom() const
{
  return prenom_;
}

QString Personne::sexe() const
{
  return sexe_;
}

QString Personne::civilite() const
{
  return civilite_;
}

QString Personne::nationalite() const
{
  return nationalite_;
}

QString Personne::adresse() const
{
  return adresse_;
}

QString Personne::date_naissance() const
{
  return date_naissance_;
}

QString Personne::telephone() const
{
  return telephone_;
}

QString Personne::email() const
{
  return email_;
}


Personne::~Personne()
{

  

}

