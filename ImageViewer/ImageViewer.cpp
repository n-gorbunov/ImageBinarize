#include "imageviewer.h"

#include <QtCore/QByteArray>
#include <QtCore/QFileInfo>
#include <QtGui/QMouseEvent>
#include <QtGui/QPixmap>
#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>

#include "BitmapView.h"
#include "OpenDialog.h"

ImageViewer::ImageViewer(QWidget *parent)
	: QMainWindow(parent)
{
	this->_ui.setupUi(this);

	this->_originalView = new BitmapView();
	this->_processedView = new BitmapView();

	this->_ui.splitter->addWidget(this->_originalView);
	this->_ui.splitter->addWidget(this->_processedView);

	QObject::connect(this->_ui.actionOpen, &QAction::triggered, this, &ImageViewer::onOpenFile);
	QObject::connect(this->_ui.actionExit, &QAction::triggered, QApplication::instance(), &QApplication::quit);

	QCoreApplication::instance()->installEventFilter(this);
}

ImageViewer::~ImageViewer()
{
}

bool ImageViewer::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseMove) {
		QMouseEvent* mouseMoveEvent = static_cast<QMouseEvent*>(event);

		QPoint cursorPos = QCursor::pos();
		QPoint originalPos = this->_originalView->mapToBitmap(cursorPos);
		QPoint processedPos = this->_processedView->mapToBitmap(cursorPos);
		if (!originalPos.isNull() || !processedPos.isNull()) {
			if (!originalPos.isNull()) {
				this->_originalView->updateInfo(originalPos);
				this->_processedView->updateInfo(originalPos);
			} else if (!processedPos.isNull()) {
				this->_originalView->updateInfo(processedPos);
				this->_processedView->updateInfo(processedPos);
			}
		}
	}

	return false;
}

void ImageViewer::onOpenFile()
{
	OpenDialog openDialog(this);
	int result = openDialog.exec();

	if (result == QDialog::Accepted) {
		this->_originalPath = openDialog.originalPath();
		this->_processedPath = openDialog.processedPath();

		this->_originalView->fromFile(this->_originalPath);
		this->_processedView->fromFile(this->_processedPath);

		this->_originalView->adjustSize();
		this->_processedView->adjustSize();
	}
}
