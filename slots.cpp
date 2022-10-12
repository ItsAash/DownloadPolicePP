#include "home.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

void Home::on_browse_pb_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Open a folder",QDir::homePath());
    QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks;
    ui->directoryInput->setText(dir);
    this->setDirectory(dir);
//    qDebug() << this->directory;
}



void Home::on_download_pb_clicked()
{
    this->setFname(ui->fnameInput->text());
    this->setUrl(ui->urlInput->text());
    qDebug() << "Download Clicked";


    ui->download_pb->setDisabled(true);
    thread->start();
}

void Home::onNumberChanged(double fileSize, double progressValue, double downSpeedInBytes, double upSpeedInBytes)
{
//    ui->fileSize->setText(this->convertFileSize(fileSize));

//    QString convertedSpeed = this->convertSpeed(downSpeedInBytes);

//    QString convertedUploadSpeed = this->convertSpeed(upSpeedInBytes);
//    ui->progressBar->setValue(progressValue);
//    ui->downloadSpeed->setText(convertedSpeed);

//    ui->uploadSpeed->setText(convertedUploadSpeed);
}

void Home::ifIdIsOne()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
    ui->download_pb->setDisabled(false);
//    ui->stackedWidget->setCurrentIndex(0);
}
void Home::onSuccess()
{
//    this->resetWindow();
//    ui->stackedWidget->setCurrentIndex(0);
}
void Home::onFailure()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
    ui->download_pb->setDisabled(false);
//    ui->stackedWidget->setCurrentIndex(0);
}
