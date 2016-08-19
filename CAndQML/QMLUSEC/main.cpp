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
C++ 类型注册为 QML 类型:
分四步：
    实现 C++ 类
    注册 QML 类型
    在 QML 中导入类型
    在 QML 创建由 C++ 导出的类型的实例并使用
*/
