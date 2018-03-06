#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_goButton_clicked();
    void on_actionLoad_file_triggered();

    void on_searchField_returnPressed();

private:
    Ui::MainWindow *ui;
    void getTextFile(QString filename);
    void startSearch();
};

#endif // MAINWINDOW_H
