#ifndef VIEWFORM_H
#define VIEWFORM_H

#include <QWidget>
#include <QWebEnginePage>
#include <QAuthenticator>
#include <QWebEngineSettings>

namespace Ui {
class ViewForm;
}

class ViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewForm(QWidget *parent = 0);
    ~ViewForm();

Q_SIGNALS:
    void loadProgress(int progress);
    void loadfinished(bool);

public slots:
    void loadweb(bool c);
    void setFinished(bool);
    void setProgress(int progress);
    void handleAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth);

private:
    Ui::ViewForm *ui;
    QWebEnginePage *webpage;

};

#endif // VIEWFORM_H
