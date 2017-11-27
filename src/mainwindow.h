#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QWebEnginePage>
#include <QAuthenticator>

#include "editcamera.h"

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
    void loadweb(bool c);
    void loadfinished(bool c);
    void loadProgress(int val);
    void handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth);
    void showAddCamera(bool);

private:
    Ui::MainWindow *ui;
    EditCamera *editCameraDialog;
    QWebEnginePage *webpage;
    QLabel *msgLabel;
    QProgressBar *progressbar;
    void initStatusBar();

};

#endif // MAINWINDOW_H
