#include "editcamera.h"
#include "ui_editcamera.h"

#include <QDebug>

EditCamera::EditCamera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCamera)
{
    ui->setupUi(this);
    connect(ui->cbBrand, SIGNAL(currentIndexChanged(int)),this, SLOT(changeBrand(int)));
    connect(ui->cbModel, SIGNAL(currentIndexChanged(int)),this, SLOT(changeModel(int)));
    connect(ui->rbHTTP, SIGNAL(clicked(bool)),this, SLOT(changeViewMode(bool)));
    connect(ui->rbRTSP, SIGNAL(clicked(bool)),this, SLOT(changeViewMode(bool)));
    connect(ui->pbPreview, SIGNAL(clicked(bool)),this, SLOT(preview(bool)));
    //connect(ui->gbViewMode, SIGNAL(clicked(bool)),this, SLOT(changeViewMode(bool)));

    //TODO: init value
    this->changeBrand(0);
    this->changeViewMode(false);
}

EditCamera::~EditCamera()
{
//    delete player;
    delete ui;
}

void EditCamera::changeBrand(int idx)
{
    qDebug() << "changeBrand: " << idx;
    //TODO: update model list
    ui->cbModel->clear();
    QString cur = ui->cbBrand->currentText();
    if (cur == "Sparklan") {
        ui->cbModel->addItem("CAS-673W");
    }
    if (cur == "TRENDnet") {
        ui->cbModel->addItem("TV-IP501P");
    }
    ui->cbModel->addItem("Custom");


}
void EditCamera::changeModel(int idx)
{
    qDebug() << "changeModel: " << idx;
    QString cur = ui->cbModel->currentText();
    if (cur == "TV-IP501P") {
        ui->rbHTTP->setChecked(true);
        ui->rbRTSP->setEnabled(false);
        this->changeViewMode(false);
    }
}
void EditCamera::changeViewMode(bool checked)
{
    qDebug() << "changeViewMode: " << checked;
    QString cur = ui->cbModel->currentText();
    if (cur == "CAS-673W") {
        if (ui->rbHTTP->isChecked()) {
            ui->lePath->setText("/video/mjpg.cgi");
        }
        if (ui->rbRTSP->isChecked()) {
            ui->lePath->setText("/3gpp");
        }
    }else if (cur == "TV-IP501P") {
        //TODO:
        ui->lePath->setText("/mjpeg.cgi");//vlc not work
        //"play3.sdp";
    }
}
void EditCamera::preview(bool checked)
{
    if (ui->leIP->text().isEmpty()) {
        //TODO: error check
        return;
    }

    if (ui->rbHTTP->isChecked()) {
        //TODO:    webpage = new QWebEnginePage;

    }

    if (ui->rbRTSP->isChecked()) {
        player = new vlcPlayer(ui->Preview);
        player->showControl(false);
        QString url("rtsp://");
        url.append(ui->leIP->text()).append(ui->lePath->text());
        player->openUrl(url);
    }
    Q_UNUSED(checked)
}
