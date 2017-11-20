#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QWebEnginePage>
#include <QAuthenticator>

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
    void turnDown(bool b);
    void turnLeft(bool b);
    void turnRight(bool b);
    void turnUp(bool b);
    void turnLeftUp(bool b);
    void turnLeftDown(bool b);
    void turnRightUp(bool b);
    void turnRightDown(bool b);
    void goHome(bool b);
    void doPatrol(bool b);
    void setLeftRightStep(int val);
    void setUpDownStep(int val);

private:
    Ui::MainWindow *ui;
    QWebEnginePage *webpage;
    QWebEnginePage *controlpage;
    QLabel *msgLabel;
    QProgressBar *progressbar;
    int iLeftRightStep;
    int iUpDownStep;
    void initStatusBar();
    void doMoveRequest(int x, int y);
};

#endif // MAINWINDOW_H
