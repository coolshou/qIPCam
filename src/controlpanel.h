#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QWebEnginePage>
#include <QAuthenticator>
#include <QUrl>
namespace Ui {
class ControlPanel;
}

class ControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);
    ~ControlPanel();

public slots:
    void handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth);
    void turnDown(bool b);
    void turnLeft(bool b);
    void turnRight(bool b);
    void turnUp(bool b);
    void turnLeftUp(bool b);
    void turnLeftDown(bool b);
    void turnRightUp(bool b);
    void turnRightDown(bool b);
    void setLeftRightStep(int val);
    void setUpDownStep(int val);
    void goHome(bool b);
    void doPatrol(bool b);

private:
    Ui::ControlPanel *ui;
    QWebEnginePage *controlpage;
    QString url;
    QString username;
    QString password;
    int iLeftRightStep;
    int iUpDownStep;
    void doMoveRequest(int x, int y);
};

#endif // CONTROLPANEL_H
