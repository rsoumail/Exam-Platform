#include<QtSql>
#include "fonctions.h"
#include "candidature_manager.h"


DossierManager::DossierManager()
{

  db = dB();

}


int DossierManager::save(const Dossier& d)
{

  QString sQuery = "INSERT INTO dossiers (cv, photo, diplome, statut_dossier, id_candidature) VALUES (:cv, :photo, :diplome, :statut, :id)";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":cv",d.cv());
      query.bindValue(":photo", d.photo());
      query.bindValue(":diplome", d.diplome());
      query.bindValue(":statut", d.statut());
      query.bindValue(":id", d.candidature().id());
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

int DossierManager::update(const Dossier& d)
{

  QString sQuery = "UPDATE dossiers SET cv=:cv, photo=:photo, diplome=:diplome, statut_dossier=:statut, id_candidature=:id_candidature WHERE id_:id";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":cv",d.cv());
      query.bindValue(":photo", d.photo());
      query.bindValue(":diplome", d.diplome());
      query.bindValue(":statut", d.statut());
      query.bindValue(":id_candidature", d.candidature().id());
      query.bindValue(":id", d.id());
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

int DossierManager::count()
{

  QString sQuery = "SELECT COUNT(id_dosier) as nombre FROM  dossiers";
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

Dossier DossierManager::unique(int id)
{

  Dossier tmp;
  if(db.open())
  {
      CandidatureManager candidatureManager;
      QString sQuery = "SELECT * FROM  WHERE id_dossier=:id";
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", id);
      if(query.exec())
      {
        if(query.next())
        {
           tmp.setId(query.value(0).toInt());
           tmp.setCv(query.value(1).toString());
           tmp.setPhoto(query.value(2).toString());
           tmp.setDiplome(query.value(3).toString());
           tmp.setCandidature(candidatureManager.unique(query.value(4).toInt()));
           tmp.setStatut(query.value(5).toInt());
           db.close();
           return tmp;
        }
      }
      else
      {
        db.close();
        return tmp;
      }
  }
  else
  {
      return tmp;
  }
}

list<Dossier> DossierManager::all()
{

  list<Dossier> dossiers;
  if(db.open())
  {
      CandidatureManager candidatureManager;
      QString sQuery = "SELECT * FROM dossiers ";
      QSqlQuery query ;
      if(query.exec(sQuery))
      {
          while(query.next()){
            Dossier tmp;
            tmp.setId(query.value(0).toInt());
            tmp.setCv(query.value(1).toString());
            tmp.setPhoto(query.value(2).toString());
            tmp.setDiplome(query.value(3).toString());
            tmp.setCandidature(candidatureManager.unique(query.value(4).toInt()));
            tmp.setStatut(query.value(5).toInt());
            dossiers.insert(dossiers.end(), tmp);
          }
      }
      db.close();
      return dossiers;
  }
  else
  {
      return dossiers;
  }
}

