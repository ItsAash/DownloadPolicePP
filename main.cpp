#include "home.h"
#include <QFile>
/*#include <QApplication>*/
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleSheetFile(":/qss/style.qss");
    styleSheetFile.open(QFile::ReadOnly);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/image/splashscreen.png"));
    splash->show();

    // Apply the loaded stylesheet
    QString stylesheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(stylesheet);
    Home window;

    QTimer::singleShot(3000, splash, SLOT(close()));
    QTimer::singleShot(3000, &window, SLOT(show()));

//    window.show();
//    w.setWindowTitle("DownloadPolice++");
    return app.exec();
}
