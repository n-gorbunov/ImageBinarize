#include "imageviewer.h"

#include <QtCore/QByteArray>
#include <QtCore/QFileInfo>
#include <QtCore/QSettings>
#include <QtGui/QMouseEvent>
#include <QtGui/QPixmap>
#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFileDialog>

//	ImageBinarize headers
#include <ImageHistogram.h>

#include "BitmapView.h"
#include "CompareView.h"
#include "OpenForCompareDialog.h"
#include "HistogramDialog.h"

ImageViewer::ImageViewer(QWidget *parent)
	: QMainWindow(parent)
{
	this->_ui.setupUi(this);

	this->_compareView = new CompareView(this);
	this->_imageView = new BitmapView(this);

	this->_ui.switcher->addWidget(this->_compareView);
	this->_ui.switcher->addWidget(this->_imageView);
	this->_mode = ImageViewer::View;

	QObject::connect(this->_ui.actionOpen, &QAction::triggered, this, &ImageViewer::onOpenFile);
	QObject::connect(this->_ui.actionCompare, &QAction::triggered, this, &ImageViewer::onOpenForCompare);
	QObject::connect(this->_ui.actionExit, &QAction::triggered, QApplication::instance(), &QApplication::quit);
	QObject::connect(this->_ui.actionHistogram, &QAction::triggered, this, &ImageViewer::onViewHistogram);

	QCoreApplication::instance()->installEventFilter(this);

	this->updateUi();
}

ImageViewer::~ImageViewer()
{
}

void ImageViewer::onOpenForCompare()
{
	OpenForCompareDialog openDialog(this);
	int result = openDialog.exec();

	if (result == QDialog::Accepted) {
		QString leftImagePath = openDialog.originalPath();
		QString rightImagePath = openDialog.processedPath();

		if (!QFile::exists(leftImagePath))
			return;

		if (!QFile::exists(rightImagePath))
			return;

		QFileInfo leftFi(leftImagePath);
		QFileInfo rightFi(rightImagePath);
		this->setWindowTitle(leftFi.fileName() + " / " + rightFi.fileName());

		this->_left.loadFromFile(leftImagePath.toStdString());
		if (this->_left.isNull())
			return;

		this->_right.loadFromFile(rightImagePath.toStdString());
		if (this->_right.isNull())
			return;

		this->_compareView->setLeftImage(this->_left);
		this->_compareView->setRightImage(this->_right);

		this->_mode = ImageViewer::Compare;
		this->updateUi();
	}
}

void ImageViewer::onOpenFile()
{
	QSettings settings;
	QString path = QFileDialog::getOpenFileName(this, tr("Choose image file"), settings.value("OriginalFile", "").toString(), "*.*");

	if (!path.isEmpty()) {
		if (!QFile::exists(path))
			return;

		QFileInfo fi(path);
		this->setWindowTitle(fi.fileName());

		this->_left.loadFromFile(path.toStdString());
		if (this->_left.isNull())
			return;

		this->_imageView->setImage(this->_left);

		this->_mode = ImageViewer::View;
		this->updateUi();
	}
}

void ImageViewer::onViewHistogram()
{
	if (this->_left.isNull())
		return;

	ImageBinarize::ImageHistogram hist(this->_left);

	HistogramDialog histogramDialog;
	histogramDialog.setViewData(hist);

	int result = histogramDialog.exec();
	if (result == QDialog::Accepted) {
	}
}

void ImageViewer::updateUi()
{
	if (this->_mode == ImageViewer::View) {
		this->_ui.switcher->setCurrentIndex(1);
	}
	else {
		this->_ui.switcher->setCurrentIndex(0);
	}
}