#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>

class ColorMaker : public QObject
{
    Q_OBJECT
    Q_ENUMS(GenerateAlgorithm)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor timeColor READ timeColor)

public:
    ColorMaker(QObject *parent = 0);
    ~ColorMaker();

    enum GenerateAlgorithm{
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };

    QColor color() const;
    void setColor(const QColor & color);
    QColor timeColor() const;

    Q_INVOKABLE GenerateAlgorithm algorithm() const;
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm);
    //在定义一个类的成员函数时使用 Q_INVOKABLE 宏来修饰，就可以让该方法被元对象系统调用。这个宏必须放在返回类型前面。

signals:
    void colorChanged(const QColor & color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();

protected:
    void timerEvent(QTimerEvent *e);

private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTimer;
};

#endif // COLORMAKER_H
