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


void Home::on_downloadPage_pb_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}
void Home::on_aboutus_pb_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}
void Home::on_home_pb_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}
void Home::on_home_pb_2_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void Home::on_download_pb_clicked()
{
    this->setFname(ui->fnameInput->text());
    this->setUrl(ui->urlInput->text());
    qDebug() << "Download Clicked";
    bool isDirectoryValid = checkDirectory(QString::fromStdString(getDirectory()));
    if(isDirectoryValid) {
        ui->download_pb->setDisabled(true);
        thread->start();
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
}

void Home::on_quitDownload_clicked()
{
    qDebug() << "Quit clicked";
    delete thread;
    QApplication::quit();
}

void Home::onNumberChanged(double fileSize, double progressValue, double downSpeedInBytes, double)
{
    ui->size_llineedit->setText(this->convertFileSize(fileSize));
    QString convertedSpeed = this->convertSpeed(downSpeedInBytes);
    ui->progressBar->setValue(progressValue);
    ui->speed_lineedit->setText(convertedSpeed);
}

void Home::ifIdIsOne()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
    ui->download_pb->setDisabled(false);
    ui->stackedWidget->setCurrentIndex(0);
}
void Home::onSuccess()
{
    this->resetWindow();
    ui->stackedWidget->setCurrentIndex(0);
}
void Home::onFailure()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
    ui->download_pb->setDisabled(false);
    ui->stackedWidget->setCurrentIndex(0);
}


void Home::resetWindow()
{
    ui->progressBar->setValue(100);
    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
    ui->download_pb->setDisabled(false);
    ui->progressBar->reset();
    ui->size_llineedit->setText("0 KB");
    ui->speed_lineedit->setText("0 Kb/s");
    ui->urlInput->setText("");
    ui->directoryInput->setText("");
    ui->fnameInput->setText("");
    ui->file_size->setText("");
    ui->speed->setText("");
    setUrl("");
    setDirectory("");
    setFname("");
}
