#ifndef TRANSPORTREGISTERWINDOW_H
#define TRANSPORTREGISTERWINDOW_H

#include "editbusdialog.h"
#include "editccardialog.h"
#include "editcvandialog.h"
#include "editmbikedialog.h"
#include "editpcardialog.h"
#include "editpvandialog.h"
#include "transportregister.h"
#include "addpcardialog.h"
#include "addpvandialog.h"
#include "addmbikedialog.h"
#include "addccardialog.h"
#include "addcvandialog.h"
#include "addbusdialog.h"
#include "deldialog.h"
#include "about.h"
#include "fileexport.h"
#include "login.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include  <typeinfo>
namespace Ui {
class TransportRegisterWindow;
}

class TransportRegisterWindow : public QMainWindow
{
Q_OBJECT
friend class fileexport;
friend class Login;

public:
explicit TransportRegisterWindow(QWidget *parent = 0);
~TransportRegisterWindow();

//This code is used when logging out
static int const EXIT_CODE_REBOOT;

//Function that restricts access depending on user's group
void restrictUi(QString userGroup);

private slots:

//Information display
void on_PCarView_clicked(const QModelIndex &index);
void on_PVanView_clicked(const QModelIndex &index);
void on_MBikeView_clicked(const QModelIndex &index);
void on_CCarView_clicked(const QModelIndex &index);
void on_CVanView_clicked(const QModelIndex &index);
void on_BusView_clicked(const QModelIndex &index);

//Edit triggers
void on_PCarView_doubleClicked(const QModelIndex &index);
void on_PVanView_doubleClicked(const QModelIndex &index);
void on_MBikeView_doubleClicked(const QModelIndex &index);
void on_CCarView_doubleClicked(const QModelIndex &index);
void on_CVanView_doubleClicked(const QModelIndex &index);
void on_BusView_doubleClicked(const QModelIndex &index);

//Add-buttons
void on_addPCarButton_clicked();
void on_addPVanButton_clicked();
void on_addMBikeButton_clicked();
void on_addCCarButton_clicked();
void on_addCVanButton_clicked();
void on_addBusButton_clicked();

//Other buttons
void on_quitButton_clicked(); //Closes application
void on_removeButton_clicked(); //Opens Remove-dialog
void on_aboutButton_clicked(); //Opens About-dialog
void on_exportButton_clicked(); //Opens Export-dialog
void on_importButton_clicked(); //Appends the database with vehicles from file. Duplicates avoided.
void on_openButton_clicked(); //Replaces current register med one from file. Use with caution!
void on_clearButton_clicked(); //Clears register and tables.
void on_searchButton_clicked(); //Searches matching...
void on_lineEdit_returnPressed(); //Call on_searchButton_clicked().
void on_logoutButton_clicked(); //Restarts application

private:
Ui::TransportRegisterWindow *ui;

//Models that store values of respective type
QStandardItemModel *pCarModel;
QStandardItemModel *pVanModel;
QStandardItemModel *mBikeModel;
QStandardItemModel *cCarModel;
QStandardItemModel *cVanModel;
QStandardItemModel *busModel;
QStandardItemModel *searchModel;

//Main Register
TransportRegister Regstr;

};
#endif // TRANSPORTREGISTERWINDOW_H
