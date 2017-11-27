#include <QFileDialog>
#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

#include "EqualizerDialog.h"

#include "vlcplayer.h"
#include "ui_vlcplayer.h"

vlcPlayer::vlcPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vlcPlayer),
    _media(0),
    _equalizerDialog(new EqualizerDialog(this))
{
    ui->setupUi(parent);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);
    _equalizerDialog->setMediaPlayer(_player);

    ui->video->setMediaPlayer(_player);
    ui->volume->setMediaPlayer(_player);
    ui->volume->setVolume(50);
    ui->seek->setMediaPlayer(_player);

    connect(ui->actionOpenLocal, &QAction::triggered, this, &vlcPlayer::openLocal);
    connect(ui->actionOpenUrl, SIGNAL(triggered(bool)), this, SLOT(openUrl(bool)));
    connect(ui->actionStop, &QAction::triggered, _player, &VlcMediaPlayer::stop);

}

vlcPlayer::~vlcPlayer()
{
    delete _player;
    delete _media;
    delete _instance;
    delete ui;
}
void vlcPlayer::openLocal()
{
    QString file =
            QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    _media = new VlcMedia(file, true, _instance);

    _player->open(_media);
}

void vlcPlayer::openUrl(bool chk)
{
    QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;

    this->openUrl(url);
}

void vlcPlayer::openUrl(QString url)
{
    _media = new VlcMedia(url, _instance);

    _player->open(_media);

}
void vlcPlayer::showControl(bool b)
{
     ui->widgetControl->setVisible(b);
}
