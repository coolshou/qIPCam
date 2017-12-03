#include "viewform.h"
#include "ui_viewform.h"

ViewForm::ViewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewForm)
{
    ui->setupUi(this);
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

ViewForm::~ViewForm()
{
    webpage->deleteLater();
    delete ui;
}
void ViewForm::handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth)
{
    auth->setUser(ui->leUser->text());
    auth->setPassword(ui->lePassword->text());
    Q_UNUSED(requestUrl);
}
void ViewForm::loadweb(bool c)
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
void ViewForm::setFinished(bool)
{
    //TODO: loadfinish
    //msgLabel->setText("Load finish:" + c);
    //loadfinished();

}
void ViewForm::setProgress(int progress)
{
    ui->progressBar->setValue(progress);
    //loadProgress(progress);
}
