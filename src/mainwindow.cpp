#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initStatusBar();

    viewForm = new ViewForm();
    editCameraDialog = new EditCamera(this);

    //actions
    connect(ui->actionAddCamera, SIGNAL(triggered(bool)), this, SLOT(showAddCamera(bool)));
    connect(ui->actionView, SIGNAL(triggered(bool)), this, SLOT(viewCamera(bool)));
}

MainWindow::~MainWindow()
{
    editCameraDialog->deleteLater();
    viewForm->deleteLater();
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


void MainWindow::showAddCamera(bool chk)
{
    editCameraDialog->setWindowTitle("Add Camera");
    editCameraDialog->exec();
    Q_UNUSED(chk);
}

void MainWindow::viewCamera(bool chk)
{
    viewForm->show();
    Q_UNUSED(chk);
}
