#include "viewerqt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ViewerQt w;
	w.show();
	return a.exec();
}
