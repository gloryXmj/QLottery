#include "lotterydemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LotteryDemo w;
	w.show();
	return a.exec();
}
