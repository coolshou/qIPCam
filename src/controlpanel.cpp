#include "controlpanel.h"
#include "ui_controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
    //TODO: set url, username, password
    url = "127.0.0.1";
    controlpage= new QWebEnginePage;
    connect(controlpage, SIGNAL(authenticationRequired(QUrl,QAuthenticator*)), SLOT(handleAuthenticationRequired(QUrl,QAuthenticator*)));
    iLeftRightStep = ui->leLeftRightStep->text().toInt();
    iUpDownStep = ui->leUpDownStep->text().toInt();
    //TODO: username, password
    connect(ui->sliderLeftRight,SIGNAL(valueChanged(int)),SLOT(setLeftRightStep(int)));
    connect(ui->sliderUpDown,SIGNAL(valueChanged(int)),SLOT(setUpDownStep(int)));

    //Left,Right....
    connect(ui->pbDown, SIGNAL(clicked(bool)), SLOT(turnDown(bool)));
    connect(ui->pbLeft, SIGNAL(clicked(bool)), SLOT(turnLeft(bool)));
    connect(ui->pbRight, SIGNAL(clicked(bool)), SLOT(turnRight(bool)));
    connect(ui->pbUp, SIGNAL(clicked(bool)), SLOT(turnUp(bool)));
    connect(ui->pbLeftUp, SIGNAL(clicked(bool)), SLOT(turnLeftUp(bool)));
    connect(ui->pbLeftDown, SIGNAL(clicked(bool)), SLOT(turnLeftDown(bool)));
    connect(ui->pbRightUp, SIGNAL(clicked(bool)), SLOT(turnRightUp(bool)));
    connect(ui->pbRightDown, SIGNAL(clicked(bool)), SLOT(turnRightDown(bool)));
    connect(ui->pbHome, SIGNAL(clicked(bool)), SLOT(goHome(bool)));
    connect(ui->pbPatrol, SIGNAL(clicked(bool)), SLOT(doPatrol(bool)));
}
void ControlPanel::handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth)
{
    auth->setUser(username);
    auth->setPassword(password);
    Q_UNUSED(requestUrl);
}
ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::turnDown(bool b)
{
    this->doMoveRequest(0, 0-iUpDownStep);
    Q_UNUSED(b);
}

void ControlPanel::turnLeft(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, 0);
    Q_UNUSED(b);
}
void ControlPanel::turnRight(bool b)
{
    this->doMoveRequest(iLeftRightStep, 0);
    Q_UNUSED(b);
}
void ControlPanel::turnUp(bool b)
{
    this->doMoveRequest(0, iUpDownStep);
    Q_UNUSED(b);
}
void ControlPanel::turnLeftUp(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, iUpDownStep);
    Q_UNUSED(b);
}
void ControlPanel::turnLeftDown(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, 0-iUpDownStep);
    Q_UNUSED(b);
}
void ControlPanel::turnRightUp(bool b)
{
    this->doMoveRequest(iLeftRightStep, iUpDownStep);
    Q_UNUSED(b);
}
void ControlPanel::turnRightDown(bool b)
{
    this->doMoveRequest(iLeftRightStep, 0 - iUpDownStep);
    Q_UNUSED(b);
}
void ControlPanel::doMoveRequest(int x, int y)
{
    //QString("http://%1/cgi/ptdc.cgi?command=set_relative_pos&posX=%2&posY=%3").arg(url).arg(QString::number(x)).arg(QString::number(y));

    QString s ="http://";
    QString p = "/cgi/ptdc.cgi?command=set_relative_pos&posX="+  QString::number(x);
    QString p2 = "&posY="+  QString::number(y);
    s.append(url).append(p).append(p2);

    controlpage->setUrl(QUrl(s));

}

void ControlPanel::setLeftRightStep(int val)
{
    iLeftRightStep = val;
    ui->leLeftRightStep->setText(QString::number(val));
}
void ControlPanel::setUpDownStep(int val)
{
    iUpDownStep = val;
    ui->leUpDownStep->setText(QString::number(val));
}
//setHomePos('set_home')
//setHomePos('restore_home')
//homePos()
void ControlPanel::goHome(bool b)
{
    QString s ="http://";
    QString p = "/cgi/ptdc.cgi?command=go_home";
    s.append(url).append(p);
    controlpage->setUrl(QUrl(s));
    Q_UNUSED(b);
}
void ControlPanel::doPatrol(bool b)
{
    QString s ="http://";
    QString p = "";
    if ( ! ui->cbPatrol->isChecked() ) {
        p = "/cgi/ptdc.cgi?command=single_patrol";
        //p = "/cgi/ptdc.cgi?command=stop";
    } else {
//preset pos
//        "/cgi/ptdc.cgi?command=goto_preset_position&presetName=" + presetName ;

//gpio
// '/dev/gpioCtrl.cgi?out1=' + value;
//led
// '/dev/gpioCtrl.cgi?led=' + value;
    }
    s.append(url).append(p);
    controlpage->setUrl(QUrl(s));
    Q_UNUSED(b);

}
//preset
//add : addPreset()
