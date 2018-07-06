#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object3dwindow.h"
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openObject3DWindow();

private:
    Ui::MainWindow *ui;
    Object3DWindow *object3DWindow;
    bool checkFileFormat(QString path);
    char toLower(char c);
};

#endif // MAINWINDOW_H
