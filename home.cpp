#include "home.h"
#include "./ui_home.h"
#include<QFileDialog>
#include<QDir>

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logo@3x.png");
    //int w = ui->top_logo_label->width();
    //int h = ui->top_logo_label->height();
    //ui->top_logo_label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->logo_label->setPixmap(pix.scaled(1113,222));
    ui->home_pb->setIcon(QIcon(":/image/home@3x.png"));
    ui->download->setIcon(QIcon(":/image/home@3x.png"));
    ui->aboutus_pb->setIcon(QIcon(":/image/home@3x.png"));
}

Home::~Home()
{
    delete ui;
}


void Home::on_browse_pb_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Open a folder",QDir::homePath());
    QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks;
    ui->dir_path->setText(dir);
}
