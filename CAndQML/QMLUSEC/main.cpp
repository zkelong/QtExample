#include <QApplication>
#include <QQmlApplicationEngine>
#include "colormaker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ColorMaker>("ColorMaker", 1, 0, "ColorMaker");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


/*
 * http://blog.csdn.net/foruok/article/details/32698603
C++ ����ע��Ϊ QML ����:
���Ĳ���
    ʵ�� C++ ��
    ע�� QML ����
    �� QML �е�������
    �� QML ������ C++ ���������͵�ʵ����ʹ��
*/
