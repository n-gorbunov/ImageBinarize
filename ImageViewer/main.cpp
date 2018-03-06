#include <QtCore/QTimer>
#include <QtWidgets/QApplication>
#include "ImageViewer.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QCoreApplication::setOrganizationName("n-gorbunov");
	QCoreApplication::setApplicationName("ImageBinarize");

	ImageViewer mainwindow;

	mainwindow.show();
	return app.exec();
}
