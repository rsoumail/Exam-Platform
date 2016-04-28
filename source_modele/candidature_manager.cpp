#include <QtSql>
#include <list>
#include "fonctions.h"
#include "candidature_manager.h"


CandidatureManager::CandidatureManager()
{

  db = dB();

}

int CandidatureManager::save(const Candidature& c)
{

  QString sQuery = "INSERT INTO candidatures (note_math, note_physique, note_francais, note_culture_generale, statut_candidature, id_candidat, id_concour) VALUES (:note_math, :note_physique, :note_francais, :note_culture_generale, :statut_candidature, :id_candidat, :id_concour)";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":note_math", c.note_math());
      query.bindValue(":note_physyque", c.note_physique());
      query.bindValue(":note_francais", c.note_francais());
      query.bindValue(":note_culture_generale", c.note_culture_generale());
      query.bindValue(":statut_candidature", c.statut());
      query.bindValue(":id_candidat", c.candidat().id());
      query.bindValue(":id_concour", c.concours().id());
      if(query.exec())
      {
        db.close();
        return 1;
      }
      else
      {
        db.close();
        return -1;
      }
  }
  else
  {
      return -1;
  }

}

int CandidatureManager::update(const Candidature& c)
{

  QString sQuery = "UPDATE candidatures SET note_math=:note_math, note_physique=:note_physique, note_francais=:note_francais, note_culture_generale=:note_culture_generale, statut_candidature=:statut_candidature, id_candidat=:id_candidat, id_concour=:id_concour , id_dossier=:id_dossier WHERE id_candidature:id";
  if(db.open())
  {
      QSqlQuery query ;
      DossierManager dossierManager;
      query.prepare(sQuery);
      query.bindValue(":note_math", c.note_math());
      query.bindValue(":note_physyque", c.note_physique());
      query.bindValue(":note_francais", c.note_francais());
      query.bindValue(":note_culture_generale", c.note_culture_generale());
      query.bindValue(":statut_candidature", c.statut());
      query.bindValue(":id_candidat", c.candidat().id());
      query.bindValue(":id_concour", c.concours().id());
      query.bindValue(":id_dossier", dossierManager.unique(c.id()).id());
      query.bindValue(":id", c.id());
      if(query.exec())
      {
        db.close();
        return 1;
      }
      else
      {
        db.close();
        return -1;
      }
  }
  else
  {
      return -1;
  }

}

int CandidatureManager::count()
{

  QString sQuery = "SELECT COUNT(id_candidature) as nombre FROM  candidatures";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      if(query.exec())
      {
        if(query.next())
        {
            db.close();
            return query.value(0).toInt();
        }
        else
        {
            db.close();
            return -1;
        }
      }
      else
      {
        db.close();
        return -1;
      }

  }
  else
  {
      return -1;
  }

}

Candidature CandidatureManager::unique(int id)
{

  Candidature tmp;
  if(db.open())
  {
      CandidatManager candidatManager;
      ConcoursManager concoursManager;
      QString sQuery = "SELECT * FROM candidatures WHERE id_candidature=:id";
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", id);
      if(query.exec())
      {
        if(query.next())
        {
            tmp.setId(query.value(0).toInt());
            tmp.setNote_math(query.value(1).toDouble());
            tmp.setNote_physique(query.value(2).toDouble());
            tmp.setNote_francais(query.value(3).toDouble());
            tmp.setNote_culture_generale(query.value(4).toDouble());
            tmp.setStatut(query.value(5).toInt());
            tmp.setCandidat(candidatManager.unique(query.value(6).toInt()));
            tmp.setConcours(concoursManager.unique(query.value(7).toInt()));

        }
      }
      db.close();
      return tmp;
  }
  else
  {
      return tmp;
  }

}

list<Candidature> CandidatureManager::all()
{

  list<Candidature> candidatures;
  CandidatManager candidatManager;
  ConcoursManager concoursManager;
  QString sQuery = "SELECT * FROM candidatures";
  if(db.open())
  {
      QSqlQuery query ;
      if(query.exec(sQuery))
      {
          while(query.next()){
            Candidature candidature;
            candidature.setId(query.value(0).toInt());
            candidature.setNote_math(query.value(1).toDouble());
            candidature.setNote_physique(query.value(2).toDouble());
            candidature.setNote_francais(query.value(3).toDouble());
            candidature.setNote_culture_generale(query.value(4).toDouble());
            candidature.setStatut(query.value(5).toInt());
            candidature.setCandidat(candidatManager.unique(query.value(6).toInt()));
            candidature.setConcours(concoursManager.unique(query.value(7).toInt()));
            candidatures.insert(candidatures.end(), candidature);
          }
          db.close();
          return candidatures;
      }
      else
      {
          db.close();
          return candidatures;
      }
  }
  else
  {
      return candidatures;
  }
}

