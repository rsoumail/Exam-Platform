#include "organisateur.h"

Organisateur::Organisateur()
{

  

}

Organisateur::Organisateur(int id, QString nom, QString prenom, QString sexe, QString civilite, QString nationalite, QString adresse, QString date_naissance, QString telephone, QString email, QString pseudo, QString password, Groupe groupe):Utilisateur(id, nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email, pseudo, password, groupe)
{

}

Organisateur::Organisateur(const Organisateur& o):Utilisateur(o)
{

}

Organisateur& Organisateur::operator=(const Organisateur& o)
{

    this->id_ = o.id_;
    this->nom_ = o.nom_;
    this->prenom_ = o.prenom_;
    this->sexe_ = o.sexe_;
    this->civilite_ = o.civilite_;
    this->date_naissance_ = o.date_naissance_;
    this->nationalite_ = o.nationalite_;
    this->adresse_ = o.adresse_;
    this->telephone_ = o.telephone_;
    this->email_ = o.email_;
    this->pseudo_ = o.pseudo_;
    this->password_ = o.password_;
    this->groupe_ = o.groupe_;
    return *this;

}

ostream& operator<<(ostream&, const Organisateur& o)
{

  

}

istream& operator>>(istream&, Organisateur& o)
{

  

}

Organisateur::~Organisateur()
{

  

}


