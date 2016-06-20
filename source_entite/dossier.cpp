#include "dossier.h"



void Dossier::setId(int value)
{
    id_ = value;
}


void Dossier::setCv(QString value)
{
    cv_ = value;
}

void Dossier::setDiplome(QString value)
{
    diplome_ = value;
}


void Dossier::setStatut(int value)
{
    statut_ = value;
}


void Dossier::setCandidature(const Candidature &value)
{
    candidature_ = value;
}

int Dossier::id() const
{
    return id_;
}

QString Dossier::cv() const
{
    return cv_;
}

QString Dossier::photo() const
{
    return photo_;
}

void Dossier::setPhoto(QString photo)
{
    photo_ = photo;
}

QString Dossier::diplome() const
{
    return diplome_;
}

int Dossier::statut() const
{
    return statut_;
}

Candidature Dossier::candidature() const
{
    return candidature_;
}

QString Dossier::acte_naissance() const
{
    return acte_naissance_;
}

void Dossier::setActe_naissance(const QString &acte_naissance)
{
    acte_naissance_ = acte_naissance;
}

int Dossier::a_traiter() const
{
    return a_traiter_;
}

void Dossier::setA_traiter(int a_traiter)
{
    a_traiter_ = a_traiter;
}

Dossier::Dossier()
{
    
    statut_ = 100;
    id_ = 0;
    acte_naissance_ = "";
    cv_ = "";
    diplome_ = "";
    photo_ = "";

    
}

Dossier::Dossier(Candidature& candidature)
{
    
    this->candidature_ = candidature;
    this->statut_ = 0;
    this->a_traiter_ = 1;
}

Dossier::Dossier(const Dossier& d)
{

    this->id_ = d.id_;
    this->cv_ = d.cv_;
    this->photo_ = d.photo_;
    this->diplome_ = d.diplome_;
    this->statut_ = d.statut_;
    this->candidature_ = d.candidature_;
    this->acte_naissance_ = d.acte_naissance_;
    this->a_traiter_ = d.a_traiter_;
}

Dossier& Dossier::operator=(const Dossier& d)
{

    this->id_ = d.id_;
    this->cv_ = d.cv_;
    this->photo_ = d.photo_;
    this->diplome_ = d.diplome_;
    this->statut_ = d.statut_;
    this->candidature_ = d.candidature_;
    this->acte_naissance_ = d.acte_naissance_;
    this->a_traiter_ = d.a_traiter_;
    return *this;

}

ostream& operator<<(ostream&, const Dossier& d)
{



}

istream& operator>>(istream&, Dossier& d)
{



}

Dossier::~Dossier()
{



}

