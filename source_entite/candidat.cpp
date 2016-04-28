#include "candidat.h"


Candidat::Candidat()
{



}

Candidat::Candidat(int id, QString nom, QString prenom, QString sexe, QString civilite, QString nationalite, QString adresse, QString date_naissance, QString telephone, QString email, QString pseudo, QString password, Groupe groupe):Utilisateur(id, nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email, pseudo, password, groupe)
{

}

Candidat::Candidat(const Candidat& c):Utilisateur(c)
{

  this->groupe_ = c.groupe_;

}

Candidat& Candidat::operator=(const Candidat& c)
{

    this->id_ = c.id_;
    this->nom_ = c.nom_;
    this->prenom_ = c.prenom_;
    this->sexe_ = c.sexe_;
    this->civilite_ = c.civilite_;
    this->date_naissance_ = c.date_naissance_;
    this->nationalite_ = c.nationalite_;
    this->adresse_ = c.adresse_;
    this->telephone_ = c.telephone_;
    this->email_ = c.email_;
    this->pseudo_ = c.pseudo_;
    this->password_ = c.password_;
    this->groupe_ = c.groupe_;
    return *this;

}

ostream& operator<<(ostream&, const Candidat& c)
{

  

}

istream& operator>>(istream&, Candidat& c)
{

  

}

Candidat::~Candidat()
{

  

}

