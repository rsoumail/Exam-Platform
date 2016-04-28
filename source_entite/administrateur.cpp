#include "administrateur.h"

Administrateur::Administrateur()
{

  

}

Administrateur::Administrateur(int id, QString nom, QString prenom, QString sexe, QString civilite, QString nationalite, QString adresse, QString date_naissance, QString telephone, QString email, QString pseudo, QString password, Groupe groupe):Utilisateur(id, nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email, pseudo, password, groupe)
{


}

Administrateur::Administrateur(const Administrateur& a):Utilisateur(a)
{


}

Administrateur& Administrateur::operator=(const Administrateur& a)
{

  this->id_ = a.id_;
  this->nom_ = a.nom_;
  this->prenom_ = a.prenom_;
  this->sexe_ = a.sexe_;
  this->civilite_ = a.civilite_;
  this->date_naissance_ = a.date_naissance_;
  this->nationalite_ = a.nationalite_;
  this->adresse_ = a.adresse_;
  this->telephone_ = a.telephone_;
  this->email_ = a.email_;
  this->pseudo_ = a.pseudo_;
  this->password_ = a.password_;
  this->groupe_ = a.groupe_;
  return *this; 

}

ostream& operator<<(ostream&, const Administrateur& a)
{

  

}

istream& operator>>(istream&, Administrateur& a)
{

  

}

Administrateur::~Administrateur()
{

  

}



