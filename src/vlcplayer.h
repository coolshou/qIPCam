#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include <QWidget>

namespace Ui {
class vlcPlayer;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class EqualizerDialog;

class vlcPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit vlcPlayer(QWidget *parent = 0);
    ~vlcPlayer();
    void showControl(bool b);

public slots:
    void openUrl(QString url);
private slots:
    void openLocal();
    void openUrl(bool chk);


private:
    Ui::vlcPlayer *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;

    EqualizerDialog *_equalizerDialog;
};

#endif // VLCPLAYER_H
