#include<QtSql>
#include "fonctions.h"
#include "candidature_manager.h"


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
      QString sQuery = "SELECT * FROM  WHERE id_concour=:id";
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

list<Concours> ConcoursManager::all()
{

  list<Concours> concours;
  QString sQuery = "SELECT * FROM concours ";
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

