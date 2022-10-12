#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <string>
#include "./ui_home.h"
#include "thread.h"


namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT
public:
    static QString url;
    static QString directory;
    static QString fname;

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

public:
    std::string getDirectory() const;
    void setDirectory(const QString &value);
    void setFname(const QString &value);
    void setUrl(const QString &value);

    static int controlUploadIndex;
    static int controlDownloadIndex;

private slots:
    void onNumberChanged(double, double, double, double);
    void ifIdIsOne();
    void onSuccess();
    void onFailure();

    void on_browse_pb_clicked();
    void on_download_pb_clicked();

private:
    Ui::Home *ui;
    Thread *thread;
};

#endif // HOME_H
