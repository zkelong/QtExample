#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>

class ColorMaker : public QObject
{
    Q_OBJECT

public:
    ColorMaker(QObject *parent = 0);
    ~ColorMaker();

signals:
    void colorChanged(const QColor & color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();
};

#endif // COLORMAKER_H
