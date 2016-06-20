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
      query.bindValue(":note_physique", c.note_physique());
      query.bindValue(":note_francais", c.note_francais());
      query.bindValue(":note_culture_generale", c.note_culture_generale());
      query.bindValue(":statut_candidature", c.statut());
      query.bindValue(":id_candidat", c.candidat().id());
      query.bindValue(":id_concour", c.concours().id());
      if(query.exec())
      {
          int id = query.lastInsertId().toInt();
          db.close();
          return id;
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


  QString sQuery = "UPDATE candidatures SET note_math = :note_math, note_physique=:note_physique, note_francais=:note_francais, note_culture_generale=:note_culture_generale, statut_candidature=:statut_candidature, id_candidat=:id_candidat, id_concour=:id_concour, id_dossier=:id_dossier WHERE id_candidature=:id";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":note_math", c.note_math());
      query.bindValue(":note_physique", c.note_physique());
      query.bindValue(":note_francais", c.note_francais());
      query.bindValue(":note_culture_generale", c.note_culture_generale());
      query.bindValue(":statut_candidature", c.statut());
      query.bindValue(":id_candidat", c.candidat().id());
      query.bindValue(":id_concour", c.concours().id());
      query.bindValue(":id_dossier", c.id_dossier());
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
  int id_con, id_can;
  Candidature tmp;
  if(db.open())
  {
      QString sQuery = "SELECT * FROM candidatures WHERE id_candidature=:id";
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", id);
      if(query.exec())
      {
        while(query.next())
        {
            tmp.setId(query.value(0).toInt());
            tmp.setNote_math(query.value(1).toDouble());
            tmp.setNote_physique(query.value(2).toDouble());
            tmp.setNote_francais(query.value(3).toDouble());
            tmp.setNote_culture_generale(query.value(4).toDouble());
            tmp.setStatut(query.value(5).toInt());
            id_can = query.value(6).toInt();
            id_con = query.value(7).toInt();
            tmp.setId_dossier(query.value(8).toInt());

        }
      }
      db.close();
      CandidatManager candidatManager;
      tmp.setCandidat(candidatManager.unique(id_can));
      ConcoursManager concoursManager;
      tmp.setConcours(concoursManager.unique(id_con));
      return tmp;
  }
  else
  {
      return tmp;
  }

}

QList<Candidature> CandidatureManager::all()
{
  QList<int> idscand, idsconc;
  QList<Candidature> candidatures;
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
            idscand.insert(idscand.end(),query.value(6).toInt());
            idsconc.insert(idsconc.end(),query.value(7).toInt());
            candidature.setId_dossier(query.value(8).toInt());
            candidatures.insert(candidatures.end(), candidature);
          }
      }
      db.close();
      for(int i=0;i<idscand.size();i++)
      {
          CandidatManager candidatManager;
          Candidature c = candidatures.at(i);
          c.setCandidat(candidatManager.unique(idscand.at(i)));
          candidatures.replace(i, c);
      }

      for(int i=0;i<idscand.size();i++)
      {
          ConcoursManager concoursManager;
          Candidature c = candidatures.at(i);
          c.setConcours(concoursManager.unique(idsconc.at(i)));
          candidatures.replace(i, c);
      }
      return candidatures;
  }
  else
  {
      return candidatures;
  }
}

QSqlTableModel* CandidatureManager::model(QSqlTableModel*model_)
{
    db.open();
    model_->setTable("candidatures");
    model_->select();
    db.close();
    return model_;
}

Candidature CandidatureManager::actif(int id_candidat)
{
    int id_can,id_con;
    Candidature tmp;
    if(db.open())
    {

        QString sQuery = "SELECT * FROM candidatures WHERE id_candidat=:id_candidat AND statut_candidature=:statut";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":id_candidat", id_candidat);
        query.bindValue(":statut", 1);
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
                id_can = query.value(6).toInt();
                id_con = query.value(7).toInt();
                tmp.setId_dossier(query.value(8).toInt());

            }
          }
          db.close();
          CandidatManager candidatManager;
          tmp.setCandidat(candidatManager.unique(id_can));
          ConcoursManager concoursManager;
          tmp.setConcours(concoursManager.unique(id_con));
          return tmp;;
    }
    else
    {
        return tmp;
    }
}

int CandidatureManager::all_old_to_inactif(int id_candidat)
{
    QString sQuery = "UPDATE candidatures SET statut_candidature=:statut_candidature WHERE id_candidat=:id";
    if(db.open())
    {
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":statut_candidature", 0);
        query.bindValue(":id", id_candidat);
        if(query.exec())
        {
          //if(query.next())
         // {
              db.close();
              return 1;
          //}
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

QList<Candidature> CandidatureManager::all_accepte(int id_concours_actif)
{
    QList<int> idscand,idsconc;
    QList<Candidature> candidatures;
    if(db.open())
    {
        QString sQuery = "SELECT * FROM candidatures c, dossiers d WHERE id_concour=:id_concour AND c.id_dossier = d.id_dossier AND statut_dossier=:statut";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":id_concour", id_concours_actif);
        query.bindValue(":statut", 1);
        if(query.exec())
        {
            while(query.next()){
              Candidature candidature;
              candidature.setId(query.value(0).toInt());
              candidature.setNote_math(query.value(1).toDouble());
              candidature.setNote_physique(query.value(2).toDouble());
              candidature.setNote_francais(query.value(3).toDouble());
              candidature.setNote_culture_generale(query.value(4).toDouble());
              candidature.setStatut(query.value(5).toInt());
              idscand.insert(idscand.end(),query.value(6).toInt());
              idsconc.insert(idsconc.end(),query.value(7).toInt());
              candidature.setId_dossier(query.value(8).toInt());
              candidatures.insert(candidatures.end(), candidature);
            }

        }
        db.close();

        for(int i=0;i<idscand.size();i++)
        {
            CandidatManager candidatManager;
            Candidature c = candidatures.at(i);
            c.setCandidat(candidatManager.unique(idscand.at(i)));
            candidatures.replace(i, c);
        }

        for(int i=0;i<idscand.size();i++)
        {
            ConcoursManager concoursManager2;
            Candidature c = candidatures.at(i);
            c.setConcours(concoursManager2.unique(idsconc.at(i)));
            candidatures.replace(i, c);
        }
        return candidatures;
    }
    else
    {
        return candidatures;
    }
}

QList<Candidature> CandidatureManager::liste_admis()
{
    QList<Candidature> admis;
    ConcoursManager concoursManager;
    Concours concour_actif = concoursManager.actif();
    CandidatureManager manager;
    QList<Candidature> candidatures = manager.all_accepte(concour_actif.id());
    for(int i = 0; i < candidatures.size();i++)
    {
        if(((candidatures.at(i).note_math() + candidatures.at(i).note_physique() + candidatures.at(i).note_francais() + candidatures.at(i).note_culture_generale()) / 4.0 ) >= 10.0)
        {
            admis.insert(i,candidatures.at(i));
        }
    }
    return admis;
}

QList<Candidature> CandidatureManager::liste_recales()
{
    QList<Candidature> recales;
    ConcoursManager concoursManager;
    Concours concour_actif = concoursManager.actif();
    CandidatureManager manager;
    QList<Candidature> candidatures = manager.all_accepte(concour_actif.id());
    for(int i = 0; i < candidatures.size();i++)
    {
        if(((candidatures.at(i).note_math() + candidatures.at(i).note_physique() + candidatures.at(i).note_francais() + candidatures.at(i).note_culture_generale()) / 4.0 ) < 10.0)
        {
            recales.insert(i,candidatures.at(i));
        }
    }
    return recales;
}


