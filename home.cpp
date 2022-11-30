#include "home.h"
#include "./ui_home.h"
#include <QFileDialog>
#include <QDir>
#include <QPixmap>
#include <string>
#include <iostream>
#include "thread.h"

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
//    QPixmap pix(":/image/logo@3x.png");
//    //int w = ui->top_logo_label->width();
//    //int h = ui->top_logo_label->height();
//    //ui->top_logo_label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
//    ui->logo_label->setPixmap(pix.scaled(1113,222));
//    ui->home_pb->setIcon(QIcon(":/image/home@3x.png"));
//    ui->download->setIcon(QIcon(":/image/home@3x.png"));
//    ui->aboutus_pb->setIcon(QIcon(":/image/home@3x.png"));


    QPixmap pix(":/image/../images/about us v2@3x.png");
    int w = ui ->label_aboutus_pic ->width();
    int h = ui ->label_aboutus_pic ->height();
    ui->label_aboutus_pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    //ui->label_aboutus_pic->setPixmap(pix.scaled(w,h,Qt ::KeepAspectRatio));

    QPixmap pix1(":/image/../images/template@3x.png");
    ui->label_bg->setPixmap(pix1.scaled(2400,1200,Qt::KeepAspectRatio));
    ui->label_bg_2->setPixmap(pix1.scaled(2400,1200,Qt::KeepAspectRatio));

    thread = new Thread;
    connect(thread, SIGNAL(numberChanged(double, double, double, double)),
            this, SLOT(onNumberChanged(double, double, double, double)));
    connect(thread, SIGNAL(idIsOne()), this, SLOT(ifIdIsOne()));
    connect(thread, SIGNAL(success()), this, SLOT(onSuccess()));
    connect(thread, SIGNAL(failure()), this, SLOT(onFailure()));
}

QString Home::url = "";
QString Home::directory = "";
QString Home::fname = "";


int Home::controlUploadIndex = 4;
int Home::controlDownloadIndex = 4;


Home::~Home()
{
    delete ui;
}

void Home::setDirectory(const QString &value)
{
    this->directory = value;
}

std::string Home::getDirectory() const
{
    return this->directory.toStdString();
}


void Home::setUrl(const QString &value)
{
    this->url = value;
}

void Home::setFname(const QString &value)
{
    this->fname = value;
}


