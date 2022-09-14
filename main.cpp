#include "home.h"
#include <QFile>
/*#include <QApplication>*/
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleSheetFile(":/qss/style.qss");
    styleSheetFile.open(QFile::ReadOnly);

    // Apply the loaded stylesheet
    QString stylesheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(stylesheet);
    Home window;
    window.show();
//    w.setWindowTitle("DownloadPolice++");
    return app.exec();
}
