/* Dialog for exporting database to text files */
#ifndef FILEEXPORT_H
#define FILEEXPORT_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "transportregister.h"
#include "transportregisterwindow.h"

namespace Ui {
class fileexport;
}

class fileexport : public QDialog
{
Q_OBJECT

public:
explicit fileexport(QWidget *parent = 0, TransportRegister *regPtr = 0);
~fileexport();

private slots:
void on_whatToExport_activated(int index); //Enables/disables sorting options depending on chosen option in this combo-box
void on_exportButtons_accepted();
private:
Ui::fileexport *ui;
TransportRegister reg; //For getting the copy of main register.
};

#endif // FILEEXPORT_H
