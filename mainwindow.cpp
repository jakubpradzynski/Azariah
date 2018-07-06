#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    object3DWindow = new Object3DWindow();
    object3DWindow->setWindowTitle("Object 3D");
    connect(ui->loadFileButton, SIGNAL(pressed()), this, SLOT(openObject3DWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openObject3DWindow()
{
    QString path = ui->pathToFileLine->text();
    QFile qFile(path);
    if(qFile.exists() && checkFileFormat(path)) {
        ui->errorLabel->setText("");
        object3DWindow->show();
        object3DWindow->start(qUtf8Printable(path));
    } else {
        ui->errorLabel->setText("Niepoprawna ścieżka do pliku!");
    }
}

bool MainWindow::checkFileFormat(QString path)
{
    int size = path.size();
    const char *tmp = qUtf8Printable(path);
    if (toLower(tmp[size - 3]) == 's' && toLower(tmp[size - 2]) == 't' && toLower(tmp[size - 1]) == 'l')
        return true;
    return false;
}

char MainWindow::toLower(char c)
{
    if (c > 64 && c < 91)
        return c + 32;
    return c;
}
