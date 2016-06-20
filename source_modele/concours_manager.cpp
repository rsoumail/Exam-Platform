#include<QtSql>
#include "fonctions.h"
#include "candidature_manager.h"
#include <QtCore>


ConcoursManager::ConcoursManager()
{

  db = dB();

}


int ConcoursManager::save(const Concours& c)
{

  QString sQuery = "INSERT INTO concours (annee_concour, age_limite_concour, date_limite_concour, date_resultats_concour, statut_concour) VALUES (:annee, :age, :date_limite, :date_resultats, :statut)";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":annee", c.annee());
      query.bindValue(":age", c.age_limite());
      query.bindValue(":date_limite", c.date_limite());
      query.bindValue(":date_resultats", c.date_resultats());
      query.bindValue(":statut", c.statut());
      if(query.exec())
      {
        db.close();
        return 1;
      }
      else
      {
        db.close();
        qDebug() << db.lastError() <<" " <<c.annee() << " " <<c.age_limite() << " " << c.date_limite() << " " << c.date_resultats()<< " " << c.statut();
        return -1;
      }
  }
  else
  {
      return -1;
  }
}

int ConcoursManager::update(const Concours& c)
{

   QString sQuery = "UPDATE concours SET annee_concour=:annee, age_limite_concour=:age, date_limite_concour=:date_limite, date_resultats_concour=:date_resultats, statut_concour=:statut WHERE id_concour=:id";
   if(db.open())
   {
       QSqlQuery query ;
       query.prepare(sQuery);
       query.bindValue(":annee", c.annee());
       query.bindValue(":age", c.age_limite());
       query.bindValue(":date_limite", c.date_limite());
       query.bindValue(":date_resultats", c.date_resultats());
       query.bindValue(":statut", c.statut());
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

int ConcoursManager::count()
{

  QString sQuery = "SELECT COUNT(id_concour) as nombre FROM  concours";
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

Concours ConcoursManager::unique(int id)
{
  Concours tmp;
  if(db.open())
  {
      QString sQuery = "SELECT * FROM  concours WHERE id_concour=:id";
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", id);
      if(query.exec())
      {
        if(query.next())
        {
            tmp.setId(query.value(0).toInt());
            tmp.setAnnee(query.value(1).toString());
            tmp.setAge_limite(query.value(2).toInt());
            tmp.setDate_limite(query.value(3).toString());
            tmp.setDate_resultats(query.value(4).toString());
            tmp.setStatut(query.value(5).toInt());

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

QList<Concours> ConcoursManager::all()
{

  QList<Concours> concours;
  QString sQuery = "SELECT * FROM concours ORDER BY annee_concour DESC";
  if(db.open())
  {
      QSqlQuery query ;
      if(query.exec(sQuery))
      {
          while(query.next()){
            Concours tmp;
            tmp.setId(query.value(0).toInt());
            tmp.setAnnee(query.value(1).toString());
            tmp.setAge_limite(query.value(2).toInt());
            tmp.setDate_limite(query.value(3).toString());
            tmp.setDate_resultats(query.value(4).toString());
            tmp.setStatut(query.value(5).toInt());
            concours.insert(concours.end(), tmp);
          }
          db.close();
      }
      return concours;
  }
  else
  {
      return concours;
  }

}

QSqlTableModel* ConcoursManager::model(QSqlTableModel*model_)
{
    db.open();
    model_->setTable("concours");
    model_->select();
    db.close();
    return model_;
}

Concours ConcoursManager::actif()
{
    Concours tmp;
    if(db.open())
    {
        QString sQuery = "SELECT * FROM concours  WHERE statut_concour=:statut";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":statut", 1);
        if(query.exec())
        {
          if(query.next())
          {
              tmp.setId(query.value(0).toInt());
              tmp.setAnnee(query.value(1).toString());
              tmp.setAge_limite(query.value(2).toInt());
              tmp.setDate_limite(query.value(3).toString());
              tmp.setDate_resultats(query.value(4).toString());
              tmp.setStatut(query.value(5).toInt());
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

int ConcoursManager::all_old_to_inactif()
{
    QString sQuery = "UPDATE concours SET statut_concour=:statut";
    if(db.open())
    {
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":statut", 0);
        if(query.exec())
        {
          if(query.next())
          {
              db.close();
              return 1;
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
