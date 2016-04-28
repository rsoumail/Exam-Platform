#include "utilisateur.h"
#include <fstream>


QString Utilisateur::pseudo() const
{
    return pseudo_;
}

void Utilisateur::setPseudo(const QString &pseudo)
{
    pseudo_ = pseudo;
}

QString Utilisateur::password() const
{
    return password_;
}

void Utilisateur::setPassword(const QString &password)
{
    password_ = password;
}

Groupe Utilisateur::groupe() const
{
    return groupe_;
}

void Utilisateur::setGroupe(const Groupe &groupe)
{
    groupe_ = groupe;
}

int Utilisateur::id() const
{
    return id_;
}

void Utilisateur::setId(int id)
{
    id_ = id;
}

Utilisateur::Utilisateur()
{
    
    
    
}

Utilisateur::Utilisateur(int id, QString nom, QString prenom, QString sexe, QString civilite, QString nationalite, QString adresse, QString date_naissance, QString telephone, QString email, QString pseudo, QString password, Groupe groupe):Personne(nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email)
{
  id_ = id;
  pseudo_ = pseudo;
  password_ = password;
  groupe_ = groupe;

}

Utilisateur::Utilisateur(const Utilisateur& u):Personne(u)
{
  id_ = u.id_;
  pseudo_ = u.pseudo_;
  password_ = u.password_;
  groupe_ = u.groupe_;

}

Utilisateur& Utilisateur::operator=(const Utilisateur& u)
{

  this->id_ = u.id_;
  this->nom_ = u.nom_;
  this->prenom_ = u.prenom_;
  this->sexe_ = u.sexe_;
  this->civilite_ = u.civilite_;
  this->date_naissance_ = u.date_naissance_;
  this->nationalite_ = u.nationalite_;
  this->adresse_ = u.adresse_;
  this->telephone_ = u.telephone_;
  this->email_ = u.email_;
  this->pseudo_ = u.pseudo_;
  this->password_ = u.password_;
  this->groupe_ = u.groupe_;
  return *this; 

}

ostream& operator<<(ostream&, const Utilisateur& u)
{

  

}

istream& operator>>(istream&, Utilisateur& u)
{

  

}

Utilisateur::~Utilisateur()
{

  

}

