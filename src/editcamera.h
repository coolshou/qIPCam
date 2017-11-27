#ifndef EDITCAMERA_H
#define EDITCAMERA_H

#include <QDialog>

#include "vlcplayer.h"

namespace Ui {
class EditCamera;
}

class EditCamera : public QDialog
{
    Q_OBJECT

public:
    explicit EditCamera(QWidget *parent = 0);
    ~EditCamera();
public slots:
    void changeBrand(int idx);
    void changeModel(int idx);
    void changeViewMode(bool checked);
    void preview(bool checked);

private:
    Ui::EditCamera *ui;
    vlcPlayer *player;
};

#endif // EDITCAMERA_H
