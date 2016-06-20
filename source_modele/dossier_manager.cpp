#include<QtSql>
#include "fonctions.h"
#include "candidature_manager.h"


DossierManager::DossierManager()
{

  db = dB();

}


int DossierManager::save(const Dossier& d)
{

  QString sQuery = "INSERT INTO dossiers (cv, photo, diplome, statut_dossier, id_candidature, acte_naissance, a_traiter) VALUES (:cv, :photo, :diplome, :statut, :id, :acte_naissance, :a_traiter)";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":cv",d.cv());
      query.bindValue(":photo", d.photo());
      query.bindValue(":diplome", d.diplome());
      query.bindValue(":statut", d.statut());
      query.bindValue(":id", d.candidature().id());
      query.bindValue(":acte_naissance", d.acte_naissance());
      query.bindValue(":a_traiter", d.a_traiter());
      if(query.exec())
      {
        db.close();
        return query.lastInsertId().toInt();
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

  QString sQuery = "UPDATE dossiers SET cv=:cv, photo=:photo, diplome=:diplome, statut_dossier=:statut, id_candidature=:id_candidature, acte_naissance=:acte_naissance, a_traiter=:a_traiter WHERE id_dossier=:id";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":cv",d.cv());
      query.bindValue(":photo", d.photo());
      query.bindValue(":diplome", d.diplome());
      query.bindValue(":statut", d.statut());
      query.bindValue(":id_candidature", d.candidature().id());
      query.bindValue(":acte_naissance", d.acte_naissance());
      query.bindValue(":a_traiter", d.a_traiter());
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
      int id_candi;
      QString sQuery = "SELECT * FROM dossiers WHERE id_dossier=:id";
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
           tmp.setStatut(query.value(4).toInt());
           id_candi = query.value(5).toInt();
           tmp.setActe_naissance(query.value(6).toString());
           tmp.setA_traiter(query.value(7).toInt());
        }
      }
      db.close();
      CandidatureManager candidatureManager;
      tmp.setCandidature(candidatureManager.unique(id_candi));
      return tmp;
  }
  else
  {
      return tmp;
  }
}

QList<Dossier> DossierManager::all()
{

  QList<Dossier> dossiers;
  if(db.open())
  {
      QList<int> ids;
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
            tmp.setStatut(query.value(4).toInt());
            ids.insert(ids.end(),query.value(5).toInt());
            tmp.setActe_naissance(query.value(6).toString());
            tmp.setA_traiter(query.value(7).toInt());
            dossiers.insert(dossiers.end(), tmp);
          }
      }
      db.close();
      for(int i=0;i<ids.size();i++)
      {
          CandidatureManager candidatureManager;
          Dossier ds = dossiers.at(i);
          ds.setCandidature(candidatureManager.unique(ids.at(i)));
          dossiers.replace(i, ds);
      }
      return dossiers;
  }
  else
  {
      return dossiers;
  }
}

QSqlTableModel* DossierManager::model(QSqlTableModel*model_)
{
    db.open();
    model_->setTable("dossiers");
    model_->select();
    db.close();
    return model_;
}

QList<Dossier> DossierManager::all_non_valide()
{
    QList<Dossier> dossiers;
    QList<int> ids;
    if(db.open())
    {
        QString sQuery = "SELECT * FROM dossiers WHERE statut_dossier=:statut AND a_traiter=:a_traiter";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":statut", 0);
        query.bindValue(":a_traiter", 0);
        if(query.exec())
        {
            while(query.next()){
              Dossier tmp;
              tmp.setId(query.value(0).toInt());
              tmp.setCv(query.value(1).toString());
              tmp.setPhoto(query.value(2).toString());
              tmp.setDiplome(query.value(3).toString());
              tmp.setStatut(query.value(4).toInt());
              ids.insert(ids.end(),query.value(5).toInt());
              tmp.setActe_naissance(query.value(6).toString());
              tmp.setA_traiter(query.value(7).toInt());
              dossiers.insert(dossiers.end(), tmp);
            }
        }
        db.close();
        for(int i=0;i<ids.size();i++)
        {
            CandidatureManager candidatureManager;
            Dossier ds = dossiers.at(i);
            ds.setCandidature(candidatureManager.unique(ids.at(i)));
            dossiers.replace(i, ds);
        }
        return dossiers;
    }
    else
    {
        return dossiers;
    }
}

QList<Dossier> DossierManager::all_valide()
{
    QList<int> ids;
    QList<Dossier> dossiers;
    if(db.open())
    {
        QString sQuery = "SELECT * FROM dossiers WHERE statut_dossier=:statut";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":statut", 1);
        if(query.exec())
        {
            while(query.next()){
              Dossier tmp;
              tmp.setId(query.value(0).toInt());
              tmp.setCv(query.value(1).toString());
              tmp.setPhoto(query.value(2).toString());
              tmp.setDiplome(query.value(3).toString());
              ids.insert(ids.end(),query.value(5).toInt());
              tmp.setStatut(query.value(4).toInt());
              tmp.setActe_naissance(query.value(6).toString());
              tmp.setA_traiter(query.value(7).toInt());
              dossiers.insert(dossiers.end(), tmp);
            }
        }
        db.close();
        for(int i=0;i<ids.size();i++)
        {
            CandidatureManager candidatureManager;
            Dossier ds = dossiers.at(i);
            ds.setCandidature(candidatureManager.unique(ids.at(i)));
            dossiers.replace(i, ds);
        }
        return dossiers;
    }
    else
    {
        return dossiers;
    }
}

QList<Dossier> DossierManager::all_non_traiter()
{
    QList<Dossier> dossiers;
    if(db.open())
    {
        QList<int> ids;
        QString sQuery = "SELECT * FROM dossiers WHERE a_traiter=:a_traiter ";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":a_traiter", 1);
        if(query.exec())
        {
            while(query.next()){
              Dossier tmp;
              tmp.setId(query.value(0).toInt());
              tmp.setCv(query.value(1).toString());
              tmp.setPhoto(query.value(2).toString());
              tmp.setDiplome(query.value(3).toString());
              ids.insert(ids.end(),query.value(5).toInt());
              tmp.setStatut(query.value(4).toInt());
              tmp.setActe_naissance(query.value(6).toString());
              tmp.setA_traiter(query.value(7).toInt());
              dossiers.insert(dossiers.end(), tmp);
            }
        }
        db.close();

        for(int i=0;i<ids.size();i++)
        {
            CandidatureManager candidatureManager;
            Dossier ds = dossiers.at(i);
            ds.setCandidature(candidatureManager.unique(ids.at(i)));
            dossiers.replace(i, ds);
        }
        return dossiers;
    }
    else
    {
        return dossiers;
    }
}

