#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "aria2cpp.h"
class Thread : public QThread
{
    Q_OBJECT
    void run();

public:
    aria2cpp::Session *session;
public:
    Thread();
    ~Thread();
    int doDownload();
    int printInfo(aria2cpp::Session*);

signals:
    void numberChanged(double, double, double, double);
    void idIsOne();
    void success();
    void failure();

};

#endif // THREAD_H
