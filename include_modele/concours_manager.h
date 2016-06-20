#include <QtSql>
#include <list>
#include "dossier_manager.h"
#include <QtCore>

using namespace std;

class ConcoursManager
{

  private:
    QSqlDatabase db;
    

  public:
    ConcoursManager();
    int save(const Concours&);
    int update(const Concours&);
    int count();
    Concours unique(int);
    Concours actif();
    QList<Concours> all();
    QSqlTableModel* model(QSqlTableModel*);
    int all_old_to_inactif();

};
