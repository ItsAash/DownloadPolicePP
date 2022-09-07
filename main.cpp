#include "mainwindow.h"
#include <QFile>
/*#include <QApplication>*/
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleSheetFile("./style.qss");
    styleSheetFile.open(QFile :: ReadOnly);
    QString stylesheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(stylesheet);

    MainWindow w;
    w.show();
    return app.exec();
}
