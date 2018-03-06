#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_goButton_clicked() {
    MainWindow::startSearch();
}

void MainWindow::on_searchField_returnPressed() {
    MainWindow::startSearch();
}

void MainWindow::getTextFile(QString filename) {
    QFile myFile(filename);

    myFile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::startSearch() {

    QString word = ui->searchField->text();
    ui->textEdit->find(word, QTextDocument::FindWholeWords);
}

void MainWindow::on_actionLoad_file_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open a text file..."), "Choose a file...", "Text File (*.txt);;All files (*.*)");
    MainWindow::getTextFile(filename);
}
