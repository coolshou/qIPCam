#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initStatusBar();

    webpage = new QWebEnginePage;
    webpage->setView(ui->webEngineView);
    connect(webpage, SIGNAL(authenticationRequired(QUrl,QAuthenticator*)), SLOT(handleAuthenticationRequired(QUrl,QAuthenticator*)));

    //ui->widgetWebPage
    ui->webEngineView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    //ui->pbLoad->clicked();
    connect(ui->webEngineView, SIGNAL(loadFinished(bool)), SLOT(loadfinished(bool)));
    connect(ui->webEngineView, SIGNAL(loadProgress(int)), SLOT(loadProgress(int)));


    connect(ui->pbLoad,SIGNAL(clicked(bool)),SLOT(loadweb(bool)));

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

