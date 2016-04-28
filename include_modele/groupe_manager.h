#include <QtSql>
#include "dossier.h"
#include <list>

class GroupeManager
{

  private:
    QSqlDatabase db;
    

  public:
    GroupeManager();
    int save(const Groupe&);
    int update(const Groupe&);
    int count();
    Groupe unique(int);
    list<Groupe> all();

};
