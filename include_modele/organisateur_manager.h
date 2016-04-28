#include <QString>
#include <QtSql>
#include <list>
#include "administrateur_manager.h"


class OrganisateurManager
{

  protected:
    QSqlDatabase db;
    

  public:
    OrganisateurManager();
    int save(const Organisateur&);
    int update(const Organisateur&);
    int countByPseudo(QString);
    Organisateur uniqueByPseudoAndPassword(QString, QString);
    Organisateur unique(int);
    list<Organisateur> all();


};

