
#include <QtSql>
#include <list>

#include "concours_manager.h"


class CandidatManager
{

  protected:
    QSqlDatabase db;
    

  public:
    CandidatManager();
    int save(const Candidat&);
    int update(const Candidat&);
    int countByPseudo(QString);
    Candidat uniqueByPseudoAndPassword(QString, QString);
    Candidat unique(int);
    void setCandidat(const Candidat&);
    list<Candidat> all();
    //list<Candidat> admis();
    //list<Candidat> echoues();

};
