/* Dialog for deleting vehicles */
#ifndef DELDIALOG_H
#define DELDIALOG_H

#include <QDialog>

namespace Ui {
class deldialog;
}

class deldialog : public QDialog
{
Q_OBJECT

public:
explicit deldialog(QWidget *parent = 0);
~deldialog();

//Gets License Number
QString getLicNr();

private slots:
private:
Ui::deldialog *ui;
};

#endif // DELDIALOG_H
