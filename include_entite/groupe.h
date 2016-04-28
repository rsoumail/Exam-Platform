#include <QString>
#include <fstream>
using namespace std;

class Groupe{

  private:
    int id_;
    QString nom_;

  public:
    Groupe();
    Groupe(int, QString);
    Groupe(const Groupe&);
    Groupe& operator=(const Groupe&);
    friend ostream& operator<<(ostream&, const Groupe&);
    friend istream& operator>>(istream&, Groupe&);
    void setId(int);
    void setNom(QString);
    ~Groupe();

    int id() const;
    QString nom() const;
};
