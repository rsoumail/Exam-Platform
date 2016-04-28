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

Dossier::Dossier()
{
    
    
    
}

Dossier::Dossier(Candidature& candidature)
{
    
    this->candidature_ = candidature;
    
}

Dossier::Dossier(const Dossier& d)
{

    this->id_ = d.id_;
    this->cv_ = d.cv_;
    this->photo_ = d.photo_;
    this->diplome_ = d.diplome_;
    this->statut_ = d.statut_;
    this->candidature_ = d.candidature_;

}

Dossier& Dossier::operator=(const Dossier& d)
{

    this->id_ = d.id_;
    this->cv_ = d.cv_;
    this->photo_ = d.photo_;
    this->diplome_ = d.diplome_;
    this->statut_ = d.statut_;
    this->candidature_ = d.candidature_;
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

