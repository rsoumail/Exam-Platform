#include "candidature.h"

int Candidature::id() const
{
    return id_;
}

double Candidature::note_math() const
{
    return note_math_;
}

double Candidature::note_physique() const
{
    return note_physique_;
}

double Candidature::note_francais() const
{
    return note_francais_;
}

double Candidature::note_culture_generale() const
{
    return note_culture_generale_;
}

Candidat Candidature::candidat() const
{
    return candidat_;
}

Concours Candidature::concours() const
{
    return concours_;
}

int Candidature::statut() const
{
    return statut_;
}

int Candidature::id_dossier() const
{
    return id_dossier_;
}

void Candidature::setId_dossier(int id_dossier)
{
    id_dossier_ = id_dossier;
}


Candidature::Candidature()
{



}

Candidature::Candidature(Candidat candidat, Concours concours)
{

    this->candidat_ = candidat;
    this->concours_ = concours;
    this->statut_ = 1;

}

Candidature::Candidature(const Candidature& candidature)
{

    this->id_ = candidature.id_;
    this->note_math_ = candidature.note_math_;
    this->note_physique_ = candidature.note_physique_;
    this->note_francais_ = candidature.note_francais_;
    this->note_culture_generale_ = candidature.note_culture_generale_;
    this->moyenne_ = candidature.moyenne_;
    this->statut_ = candidature.statut_;
    this->candidat_ = candidature.candidat_;
    this->concours_ = candidature.concours_;

}

Candidature& Candidature::operator=(const Candidature& candidature)
{
    this->id_ = candidature.id_;
    this->note_math_ = candidature.note_math_;
    this->note_physique_ = candidature.note_physique_;
    this->note_francais_ = candidature.note_francais_;
    this->note_culture_generale_ = candidature.note_culture_generale_;
    this->moyenne_ = candidature.moyenne_;
    this->statut_ = candidature.statut_;
    this->candidat_ = candidature.candidat_;
    this->concours_ = candidature.concours_;
    return *this;

}

ostream& operator<<(ostream&, const Candidature& candidature)
{

  

}

istream& operator>>(istream&, Candidature& candidature)
{

  

}

void Candidature::setId(int id)
{
  this->id_ = id;
}

void Candidature::setNote_math(double note_math)
{
  this->note_math_ = note_math;
}

void Candidature::setNote_physique(double note_physique)
{
  this->note_physique_ = note_physique;
}

void Candidature::setNote_francais(double note_francais)
{
  this->note_francais_ = note_francais;
}

void Candidature::setNote_culture_generale(double note_culture_generale)
{
  this->note_culture_generale_ = note_culture_generale;
}

void Candidature::setCandidat(const Candidat& candidat)
{
  this->candidat_ = candidat;
}

void Candidature::setConcours(const Concours& concours)
{
  this->concours_ = concours;
}

void Candidature::setStatut(int statut)
{
  this->statut_ = statut;
}



Candidature::~Candidature()
{

  

}

