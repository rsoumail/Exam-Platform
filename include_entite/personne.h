#include <QString>
#include <fstream>


using namespace std;

class Personne{

  protected:
    QString nom_;
    QString prenom_;
    QString sexe_;
    QString civilite_;
    QString nationalite_;
    QString adresse_;
    QString date_naissance_;
    QString telephone_;
    QString email_;


  public:
    Personne();
    Personne(QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Personne(const Personne&);
    Personne& operator=(const Personne&);
    friend ostream& operator<<(ostream&, const Personne&);
    friend istream& operator>>(istream&, Personne&);
    void setNom(QString);
    void setPrenom(QString);
    void setSexe(QString);
    void setCivilite(QString);
    void setNationalite(QString);
    void setAdresse(QString);
    void setDate_naissance(QString);
    void setTelephone(QString);
    void setEmail(QString);
    QString nom() const;
    QString prenom() const;
    QString sexe() const;
    QString civilite() const;
    QString nationalite() const;
    QString adresse() const;
    QString date_naissance() const;
    QString telephone() const;
    QString email() const;
    ~Personne();

};
