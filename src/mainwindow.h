#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QWebEnginePage>


#include "editcamera.h"
#include "viewform.h"

#include <QDebug>

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
    void showAddCamera(bool);
    void viewCamera(bool);

private:
    Ui::MainWindow *ui;
    EditCamera *editCameraDialog;
    ViewForm *viewForm;
    QLabel *msgLabel;
    QProgressBar *progressbar;
    void initStatusBar();

};

#endif // MAINWINDOW_H
