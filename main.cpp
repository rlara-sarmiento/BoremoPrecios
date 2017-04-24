#include <QtGui/QApplication>
#include "BoremoPrecios.h"


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	BoremoPrecios boremoprecios;
	boremoprecios.show();
	return app.exec();
}
