#include <QSql>
#include "candidature_manager.h"
#include "fonctions.h"
#include <QDebug>


CandidatManager::CandidatManager()
{

  db = dB();

}

int CandidatManager::save(const Candidat& c)
{

  if(db.open())
  {
    QString sQuery = "INSERT INTO candidats (nom_candidat, prenom_candidat, date_naissance_candidat, sexe_candidat, civilite_candidat, nationalite_candidat, adresse_candidat, telephone_candidat, email_candidat, pseudo_candidat, password_candidat, id_groupe) VALUES(:nom, :prenom, :date_naissance, :sexe, :civilite, :nationalite_candidat, :adresse, :telephone, :email, :pseudo, :password, :groupe)";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", c.nom());
    query.bindValue(":prenom", c.prenom());
    query.bindValue(":date_naissance", c.date_naissance());
    query.bindValue(":sexe", c.sexe());
    query.bindValue(":civilite", c.civilite());
    query.bindValue(":adresse", c.adresse());
    query.bindValue(":telephone", c.telephone());
    query.bindValue(":email", c.email());
    query.bindValue(":pseudo", c.pseudo());
    query.bindValue(":password", c.password());
    query.bindValue(":nationalite_candidat", c.nationalite());
    query.bindValue(":groupe", c.groupe().id());
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

int CandidatManager::update(const Candidat& c)
{

  if(db.open())
  {
    QString sQuery = "UPDATE candidats SET nom_candidat=:nom, prenom_candidat=:prenom, date_naissance_candidat=:date_naissance, sexe_candidat=:sexe, civilite_candidat=:civilite, nationalite_candidat=:nationalite_candidat, adresse_candidat=:adresse, telephone_candidat=:telephone, email_candidat=:email, pseudo_candidat=:pseudo, password_candidat=:password, id_groupe=:groupe WHERE id_candidat=:id";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", c.nom());
    query.bindValue(":prenom", c.prenom());
    query.bindValue(":date_naissance", c.date_naissance());
    query.bindValue(":sexe", c.sexe());
    query.bindValue(":civilite", c.civilite());
    query.bindValue(":adresse", c.adresse());
    query.bindValue(":telephone", c.telephone());
    query.bindValue(":email", c.email());
    query.bindValue(":pseudo", c.pseudo());
    query.bindValue(":password", c.password());
    query.bindValue(":nationalite_candidat", c.nationalite());
    query.bindValue(":groupe", c.groupe().id());
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

int CandidatManager::countByPseudo(QString pseudo)
{

  if(db.open())
  {
    QString sQuery = "SELECT COUNT(id_candidat) as nombre FROM candidats WHERE pseudo_candidat=:pseudo";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":pseudo", pseudo);
    if(query.exec())
    {
      if(query.next())
      {
          if(query.value(0).toInt() == 0)
          {
              db.close();
              return 0;
          }
          else
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
      db.close();
      return -1;
    }
  }
  else
  {

    return -1;
  }

}

Candidat CandidatManager::uniqueByPseudoAndPassword(QString pseudo, QString password)
{
    Candidat tmp;
    if(db.open())
    {
        QString sQuery = "SELECT * FROM candidats WHERE pseudo_candidat=:pseudo AND password_candidat=:password";
        QSqlQuery query ;
        query.prepare(sQuery);
        query.bindValue(":pseudo", pseudo);
        query.bindValue(":password", password);
        if(query.exec())
        {
            if(query.next())
            {
                tmp.setId(query.value(0).toInt());
                tmp.setNom(query.value(1).toString());
                tmp.setPrenom(query.value(2).toString());
                tmp.setDate_naissance(query.value(3).toString());
                tmp.setSexe(query.value(4).toString());
                tmp.setCivilite(query.value(5).toString());
                tmp.setNationalite(query.value(6).toString());
                tmp.setAdresse(query.value(7).toString());
                tmp.setTelephone(query.value(8).toString());
                tmp.setEmail(query.value(9).toString());
                tmp.setPseudo(query.value(10).toString());
                tmp.setPassword(query.value(11).toString());
                int id_groupe = query.value(12).toInt();
                GroupeManager groupeManager;
                Groupe groupe = groupeManager.unique(id_groupe);
                tmp.setGroupe(groupe);
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

Candidat CandidatManager::unique(int id)
{
  int id_groupe;
  Candidat tmp;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM candidats WHERE id_candidat=:id";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":id", id);
    if(query.exec())
    {
      if(query.next())
      {
          tmp.setId(query.value(0).toInt());
          tmp.setNom(query.value(1).toString());
          tmp.setPrenom(query.value(2).toString());
          tmp.setDate_naissance(query.value(3).toString());
          tmp.setSexe(query.value(4).toString());
          tmp.setCivilite(query.value(5).toString());
          tmp.setNationalite(query.value(6).toString());
          tmp.setAdresse(query.value(7).toString());
          tmp.setTelephone(query.value(8).toString());
          tmp.setEmail(query.value(9).toString());
          tmp.setPseudo(query.value(10).toString());
          tmp.setPassword(query.value(11).toString());
          id_groupe = query.value(12).toInt();
      }
    }
    db.close();
    GroupeManager groupeManager;
    Groupe groupe = groupeManager.unique(id_groupe);
    tmp.setGroupe(groupe);
    return tmp;
  }
  else
  {
    return tmp;
  }


}

QList<Candidat> CandidatManager::all()
{
  QList<int> ids;
  QList<Candidat> candidats;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM  candidats";
    QSqlQuery query ;
    if(query.exec(sQuery))
    {
        while(query.next()){
            Candidat tmp;
            tmp.setId(query.value(0).toInt());
            tmp.setNom(query.value(1).toString());
            tmp.setPrenom(query.value(2).toString());
            tmp.setDate_naissance(query.value(3).toString());
            tmp.setSexe(query.value(4).toString());
            tmp.setCivilite(query.value(5).toString());
            tmp.setNationalite(query.value(6).toString());
            tmp.setAdresse(query.value(7).toString());
            tmp.setTelephone(query.value(8).toString());
            tmp.setEmail(query.value(9).toString());
            tmp.setPseudo(query.value(10).toString());
            tmp.setPassword(query.value(11).toString());
            ids.insert(ids.end(),query.value(12).toInt());
            candidats.insert(candidats.end(),tmp);
        }
        db.close();
        for(int i = 0;i<ids.size();i++)
        {
            Candidat c = candidats.at(i);
            GroupeManager groupeManager;
            c.setGroupe(groupeManager.unique(ids.at(i)));
            candidats.replace(i,c);
        }
    }
    return candidats;
  }
  else
  {
    return candidats;
  }
}

QSqlTableModel* CandidatManager::model(QSqlTableModel*model_)
{
    db.open();
    model_->setTable("candidats");
    model_->select();
    db.close();
    return model_;
}



