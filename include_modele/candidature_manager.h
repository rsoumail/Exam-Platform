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
    Candidature actif(int);
    QList<Candidature> all();
    QSqlTableModel* model(QSqlTableModel*);
    int all_old_to_inactif(int);
    QList<Candidature> all_accepte(int);
    QList<Candidature> liste_admis();
    QList<Candidature> liste_recales();
};
