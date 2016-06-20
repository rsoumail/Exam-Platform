
#include <QtSql>
#include <list>
#include "groupe_manager.h"

using namespace std;

class AdministrateurManager
{

  protected:
    QSqlDatabase db;
    

  public:
    AdministrateurManager();
    int save(const Administrateur&);
    int update(const Administrateur&);
    int countByPseudo(QString);
    Administrateur uniqueByPseudoAndPassword(QString, QString);
    Administrateur unique(int);
    QList<Administrateur> all();
    QSqlTableModel* model(QSqlTableModel*);


};


