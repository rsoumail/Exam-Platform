#include <QSql>
#include "candidature_manager.h"
#include "fonctions.h"
#include <QDebug>


OrganisateurManager::OrganisateurManager()
{

  db = dB();

}

int OrganisateurManager::save(const Organisateur& o)
{

  if(db.open())
  {
    QString sQuery = "INSERT INTO organisateurs (nom_organisateur, prenom_organisateur, date_naissance_organisateur, sexe_organisateur, civilite_organisateur, adresse_organisateur, telephone_organisateur, email_organisateur, pseudo_organisateur, password_organisateur, id_groupe) VALUES(:nom, :prenom, :date_naissance, :sexe, :civilite, :adresse, :telephone, :email, :pseudo, :password, :groupe)";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", o.nom());
    query.bindValue(":prenom", o.prenom());
    query.bindValue(":date_naissance", o.date_naissance());
    query.bindValue(":sexe", o.sexe());
    query.bindValue(":civilite", o.civilite());
    query.bindValue(":adresse", o.adresse());
    query.bindValue(":telephone", o.telephone());
    query.bindValue(":email", o.email());
    query.bindValue(":pseudo", o.pseudo());
    query.bindValue(":password", o.password());
    query.bindValue(":groupe", o.groupe().id());
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

int OrganisateurManager::update(const Organisateur& o)
{

  if(db.open())
  {
    QString sQuery = "UPDATE  SET nom_organisateur=:nom, prenom_organisateur=:prenom, date_naissance_organisateur=:date_naissance, sexe_organisateur=:sexe, civilite_organisateur=:civilite, adresse_organisateur=:adresse, telephone_organisateur=:telephone, email_organisateur=:email, pseudo_organisateur=:pseudo, password_organisateur=:password, id_groupe=:groupe WHERE id_organisateur=:id";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", o.nom());
    query.bindValue(":prenom", o.prenom());
    query.bindValue(":date_naissance", o.date_naissance());
    query.bindValue(":sexe", o.sexe());
    query.bindValue(":civilite", o.civilite());
    query.bindValue(":adresse", o.adresse());
    query.bindValue(":telephone", o.telephone());
    query.bindValue(":email", o.email());
    query.bindValue(":pseudo", o.pseudo());
    query.bindValue(":password", o.password());
    query.bindValue(":groupe", o.groupe().id());
    query.bindValue(":id", o.id());
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

int OrganisateurManager::countByPseudo(QString pseudo)
{

  if(db.open())
  {
    QString sQuery = "SELECT COUNT(id_organisateur) as nombre FROM organisateurs WHERE pseudo_organisateur=:pseudo";
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
      db.close();
      return -1;
    }
  }
  else
  {

    return -1;
  }

}

Organisateur OrganisateurManager::uniqueByPseudoAndPassword(QString pseudo, QString password)
{
    Organisateur tmp;
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

Organisateur OrganisateurManager::unique(int id)
{

  Organisateur tmp;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM organisateurs WHERE id_organisateur=:id";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":id", id);
    if(query.exec())
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

list<Organisateur> OrganisateurManager::all()
{
  list<Organisateur> organisateurs;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM  organisateurs";
    QSqlQuery query ;
    if(query.exec(sQuery))
    {
        while(query.next()){
          int id = query.value(0).toInt();
          QString nom = query.value(1).toString();
          QString prenom = query.value(2).toString();
          QString sexe = query.value(3).toString();
          QString civilite = query.value(4).toString();
          QString nationalite = query.value(5).toString();
          QString adresse = query.value(6).toString();
          QString date_naissance = query.value(7).toString();
          QString telephone = query.value(8).toString();
          QString email = query.value(9).toString();
          QString pseudo = query.value(10).toString();
          QString password = query.value(11).toString();
          int id_groupe = query.value(12).toInt();

          GroupeManager groupeManager;
          Groupe groupe = groupeManager.unique(id_groupe);
          Organisateur organisateur(id, nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email, pseudo, password, groupe);
          organisateurs.insert(organisateurs.end(),organisateur);
        }
        db.close();
    }
    return organisateurs;
  }
  else
  {
    return organisateurs;
  }
}


