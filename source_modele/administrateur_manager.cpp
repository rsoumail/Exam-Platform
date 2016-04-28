#include <QtSql>
#include "candidature_manager.h"
#include "fonctions.h"
#include <QDebug>


AdministrateurManager::AdministrateurManager()
{

  db = dB();

}

int AdministrateurManager::save(const Administrateur& a)
{

  if(db.open())
  {
    QString sQuery = "INSERT INTO administrateurs (nom_administrateur, prenom_administrateur, date_naissance_administrateur, sexe_administrateur, civilite_administrateur, adresse_administrateur, telephone_administrateur, email_administrateur, pseudo_administrateur, password_administrateur, id_groupe) VALUES(:nom, :prenom, :date_naissance, :sexe, :civilite, :adresse, :telephone, :email, :pseudo, :password, :groupe)";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", a.nom());
    query.bindValue(":prenom", a.prenom());
    query.bindValue(":date_naissance", a.date_naissance());
    query.bindValue(":sexe", a.sexe());
    query.bindValue(":civilite", a.civilite());
    query.bindValue(":adresse", a.adresse());
    query.bindValue(":telephone", a.telephone());
    query.bindValue(":email", a.email());
    query.bindValue(":pseudo", a.pseudo());
    query.bindValue(":password", a.password());
    query.bindValue(":groupe", a.groupe().id());
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

int AdministrateurManager::update(const Administrateur& a)
{

  if(db.open())
  {
    QString sQuery = "UPDATE administrateurs SET nom_administrateur=:nom, prenom_administrateur=:prenom, date_naissance_administrateur=:date_naissance, sexe_administrateur=:sexe, civilite_administrateur=:civilite, adresse_administrateur=:adresse, telephone_administrateur=:telephone, email_administrateur=:email, pseudo_administrateur=:pseudo, password_administrateur=:password, id_groupe=:groupe WHERE id_administrateur=:id";
    QSqlQuery query ;
    query.prepare(sQuery);
    query.bindValue(":nom", a.nom());
    query.bindValue(":prenom", a.prenom());
    query.bindValue(":date_naissance", a.date_naissance());
    query.bindValue(":sexe", a.sexe());
    query.bindValue(":civilite", a.civilite());
    query.bindValue(":adresse", a.adresse());
    query.bindValue(":telephone", a.telephone());
    query.bindValue(":email", a.email());
    query.bindValue(":pseudo", a.pseudo());
    query.bindValue(":password", a.password());
    query.bindValue(":groupe", a.groupe().id());
    query.bindValue(":id", a.id());
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

int AdministrateurManager::countByPseudo(QString pseudo)
{

  if(db.open())
  {
    QString sQuery = "SELECT COUNT(id_administrateur) as nombre FROM administrateurs WHERE pseudo_administrateur=:pseudo";
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

Administrateur AdministrateurManager::uniqueByPseudoAndPassword(QString pseudo, QString password)
{
    Administrateur tmp;
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

Administrateur AdministrateurManager::unique(int id)
{

  Administrateur tmp;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM administrateurs WHERE id_administrateur=:id";
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


list<Administrateur> AdministrateurManager::all()
{
  list<Administrateur> administrateurs;
  if(db.open())
  {
    QString sQuery = "SELECT * FROM  administrateurs";
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
          Administrateur administrateur(id, nom, prenom, sexe, civilite, nationalite, adresse, date_naissance, telephone, email, pseudo, password, groupe);
          administrateurs.insert(administrateurs.end(),administrateur);
        }
        db.close();
    }
    return administrateurs;
  }
  else
  {
    return administrateurs;
  }
}



