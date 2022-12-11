
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :


    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

    currentFile.clear();

    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);

    QTextStream in(&file);
    QString text = in.readAll();

    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFile = fileName;

    setWindowTitle(fileName);

    QTextStream out(&file);

    QString text = ui->textEdit->toPlainText();

    out << text;

    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    QString url = "https://drive.google.com/file/d/1_FUZfe7Pm89VZ4yoeKbsJbeyJn2Za2Bp/view?usp=share_link";
    QDesktopServices::openUrl(url);
}

void MainWindow::on_actionBold_2_triggered()
{
    QFont font = ui -> textEdit -> currentFont();
        font.bold() == true ? font.setBold(false) : font.setBold(true);
        ui -> textEdit -> setCurrentFont(font);
}



void MainWindow::on_actionSubScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked == true)
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSuperScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked == true)
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);
}



void MainWindow::on_actionDark_triggered()
{


        QPalette p = ui -> textEdit -> palette();
        p.setColor(QPalette::Base, "#141414");
        p.setColor(QPalette::Text, Qt::white);
        ui -> textEdit -> setPalette(p);

}


void MainWindow::on_actionLight_triggered()
{
    QPalette p = ui -> textEdit -> palette();
    p.setColor(QPalette::Base, "white");
    p.setColor(QPalette::Text, Qt::black);
    ui -> textEdit -> setPalette(p);
}

