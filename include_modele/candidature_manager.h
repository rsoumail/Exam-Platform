#include <QtSql>
#include "candidat_manager.h"


class CandidatureManager
{

  private:
    QSqlDatabase db;
    

  public:
    CandidatureManager();
    int save(const Candidature&);
    int update(const Candidature&);
    int count();
    Candidature unique(int);
    list<Candidature> all();

};
