#ifndef OBJECT3DWINDOW_H
#define OBJECT3DWINDOW_H

#include <QWidget>
#include <iostream>

namespace Ui {
class Object3DWindow;
}

class Object3DWindow : public QWidget
{
    Q_OBJECT

public:
    explicit Object3DWindow(QWidget *parent = 0);
    ~Object3DWindow();
    void start(const char *pathToFile);

private:
    Ui::Object3DWindow *ui;
};

#endif // OBJECT3DWINDOW_H
