#include "lotterydemo.h"
#include <QtWidgets/QApplication>
#include "qDebug2Logcat.h"

int main(int argc, char *argv[])
{
    installLogcatMessageHandler("yourLogTag");
    QApplication a(argc, argv);
    LotteryDemo w;
#ifdef Q_OS_ANDROID
    w.showMaximized();
#else
    w.showHead();
#endif //
    return a.exec();
}
