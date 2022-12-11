#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFont>
#include <QMainWindow>
#include <QtCore>
#include <QTextCharFormat>
#include <QtWidgets>

// Use the standard UI namespace which is tied to the .ui file
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionBold_2_triggered();

    void on_actionSubScript_triggered(bool checked);

    void on_actionSuperScript_triggered(bool checked);

    void on_actionDark_triggered();

    void on_actionLight_triggered();

private:


    Ui::MainWindow *ui;

    QString currentFile = "";
};

#endif // MainWindow_H


