#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initStatusBar();
    iLeftRightStep = ui->leLeftRightStep->text().toInt();
    iUpDownStep = ui->leUpDownStep->text().toInt();
    controlpage= new QWebEnginePage;
    webpage = new QWebEnginePage;
    webpage->setView(ui->webEngineView);
    connect(webpage, SIGNAL(authenticationRequired(QUrl,QAuthenticator*)), SLOT(handleAuthenticationRequired(QUrl,QAuthenticator*)));
    connect(controlpage, SIGNAL(authenticationRequired(QUrl,QAuthenticator*)), SLOT(handleAuthenticationRequired(QUrl,QAuthenticator*)));
    //ui->widgetWebPage
    ui->webEngineView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    //ui->pbLoad->clicked();
    connect(ui->webEngineView, SIGNAL(loadFinished(bool)), SLOT(loadfinished(bool)));
    connect(ui->webEngineView, SIGNAL(loadProgress(int)), SLOT(loadProgress(int)));

    connect(ui->sliderLeftRight,SIGNAL(valueChanged(int)),SLOT(setLeftRightStep(int)));
    connect(ui->sliderUpDown,SIGNAL(valueChanged(int)),SLOT(setUpDownStep(int)));

    connect(ui->pbLoad,SIGNAL(clicked(bool)),SLOT(loadweb(bool)));
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

MainWindow::~MainWindow()
{
    webpage->deleteLater();
    delete ui;
}

void MainWindow::initStatusBar()
{
    progressbar = new QProgressBar;
    //progressbar->setMinimumSize(100);
    progressbar->setMaximum(100);
    ui->statusBar->addWidget(progressbar);
    msgLabel = new QLabel;
    msgLabel->setMinimumSize(300,10);
    //msgLabel->setAlignment(Qt::AlignHCenter);
    ui->statusBar->addWidget(msgLabel);

}

void MainWindow::loadweb(bool c)
{
    QString s = "http://";
    QString p = "/video/mjpg.cgi";
    s.append(ui->leURL->text());
    s.append(p);
    qDebug() << "loadweb:" << s << endl;
    webpage->setUrl(QUrl(s));
    //ui->webEngineView->
    //ui->webEngineView->setUrl(QUrl(s));
    //ui->webEngineView->show();
    //ui->webEngineView->setAttribute();
    Q_UNUSED(c);
}
void MainWindow::loadfinished(bool c)
{
    msgLabel->setText("Load finish:" + c);
}
void MainWindow::loadProgress(int val)
{
    progressbar->setValue(val);
}
void MainWindow::handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth)
{
    auth->setUser(ui->leUser->text());
    auth->setPassword(ui->lePassword->text());
    Q_UNUSED(requestUrl);
}
void MainWindow::turnDown(bool b)
{
    this->doMoveRequest(0, 0-iUpDownStep);
    Q_UNUSED(b);
}

void MainWindow::turnLeft(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, 0);
    Q_UNUSED(b);
}
void MainWindow::turnRight(bool b)
{
    this->doMoveRequest(iLeftRightStep, 0);
    Q_UNUSED(b);
}
void MainWindow::turnUp(bool b)
{
    this->doMoveRequest(0, iUpDownStep);
    Q_UNUSED(b);
}
void MainWindow::turnLeftUp(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, iUpDownStep);
    Q_UNUSED(b);
}
void MainWindow::turnLeftDown(bool b)
{
    this->doMoveRequest(0-iLeftRightStep, 0-iUpDownStep);
    Q_UNUSED(b);
}
void MainWindow::turnRightUp(bool b)
{
    this->doMoveRequest(iLeftRightStep, iUpDownStep);
    Q_UNUSED(b);
}
void MainWindow::turnRightDown(bool b)
{
    this->doMoveRequest(iLeftRightStep, 0 - iUpDownStep);
    Q_UNUSED(b);
}
void MainWindow::doMoveRequest(int x, int y)
{
    QString s ="http://";
    QString p = "/cgi/ptdc.cgi?command=set_relative_pos&posX="+  QString::number(x);
    QString p2 = "&posY="+  QString::number(y);
    s.append(ui->leURL->text()).append(p).append(p2);
    controlpage->setUrl(QUrl(s));

}
//setHomePos('set_home')
//setHomePos('restore_home')
//homePos()
void MainWindow::goHome(bool b)
{
    QString s ="http://";
    QString p = "/cgi/ptdc.cgi?command=go_home";
    s.append(ui->leURL->text()).append(p);
    controlpage->setUrl(QUrl(s));
    Q_UNUSED(b);
}
void MainWindow::doPatrol(bool b)
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
    s.append(ui->leURL->text()).append(p);
    controlpage->setUrl(QUrl(s));
    Q_UNUSED(b);

}
//preset
//add : addPreset()

void MainWindow::setLeftRightStep(int val)
{
    iLeftRightStep = val;
    ui->leLeftRightStep->setText(QString::number(val));
}
void MainWindow::setUpDownStep(int val)
{
    iUpDownStep = val;
    ui->leUpDownStep->setText(QString::number(val));
}
