#include "fonctions.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>

QSqlDatabase dB()
{
    QString servername = "127.0.0.1";
    QString dbname = "exam";
    QString username = "examadmin";
    QString password = "examadmin";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName(dbname);
    db.setHostName(servername);
    db.setUserName(username);
    db.setPassword(password);

    return db;
}

void imprimer(QTableView* qtableView)
{

            QString filename = QFileDialog::getSaveFileName(0,"Export PDF", "", "fichiers PDF (*.pdf);;All Files (*.*)");

                    QPrinter printer(QPrinter::HighResolution);
                    printer.setFullPage(true);
                    printer.setOutputFileName(filename);
                    printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFormat(QPrinter::PdfFormat);

                   QPainter painter;
                     painter.begin(&printer);
                           double xscale = printer.pageRect().width()/double(qtableView->width());
                           double yscale = printer.pageRect().height()/double(qtableView->height());
                           double scale = qMin(xscale, yscale);
                           painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                                              printer.paperRect().y() + printer.pageRect().height()/6);


                           painter.scale(scale, scale);
                           painter.translate(-qtableView->width()/2, -qtableView->height()/2);


                           qtableView->render(&painter);


                 painter.end();

}
