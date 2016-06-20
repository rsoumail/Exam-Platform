#include <QSql>
#include "candidature_manager.h"
#include "fonctions.h"



GroupeManager::GroupeManager()
{

    db = dB();

}

int GroupeManager::save(const Groupe& g)
{

  QString sQuery = "INSERT INTO groupes (nom_groupe) VALUES (:nom)";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":nom", g.nom());
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

int GroupeManager::update(const Groupe& g)
{

  QString sQuery = "UPDATE groupes SET nom_groupe WHERE id_groupe:id";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", g.id());
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

int GroupeManager::count()
{

  QString sQuery = "SELECT COUNT(id_groupe) as nombre FROM  groupes";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      if(query.exec())
      {
        if(query.next())
        {
            int nombre = query.value(1).toInt() ;
            db.close();
            return nombre;
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

Groupe GroupeManager::unique(int id)
{

  Groupe tmp;
  QString sQuery = "SELECT * FROM groupes WHERE  id_groupe=:id";
  if(db.open())
  {
      QSqlQuery query ;
      query.prepare(sQuery);
      query.bindValue(":id", id);
      if(query.exec())
      {
        if(query.next())
        {
            tmp.setId(query.value(0).toInt());
            tmp.setNom(query.value(1).toString());
        }
        db.close();
        return tmp;
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

list<Groupe> GroupeManager::all()
{

  list<Groupe> groupes;
  QString sQuery = "SELECT * FROM groupes ";
  if(db.open())
  {
      QSqlQuery query ;
      if(query.exec(sQuery))
      {
          while(query.next()){
            Groupe groupe;
            groupe.setId(query.value(0).toInt());
            groupe.setNom(query.value(1).toString());
            groupes.insert(groupes.end(), groupe);
          }
      }
      db.close();
  }
  return groupes;
}

QSqlTableModel* GroupeManager::model(QSqlTableModel*model_)
{
    db.open();
    model_->setTable("groupes");
    model_->select();
    db.close();
    return model_;
}

