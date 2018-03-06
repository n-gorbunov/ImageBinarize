#include "BitmapView.h"

#include <QtCore/QFile>
#include <QtWidgets\QLabel>
#include <QtWidgets\QLineEdit>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

BitmapView::BitmapView(QWidget* parent)
	: QWidget(parent)
	, _tracking(false)
{
	this->_ui.setupUi(this);
}

BitmapView::~BitmapView()
{
}

QPoint BitmapView::mapToBitmap(const QPoint &globalPos)
{
	QPoint pos = this->_ui.pixmap->mapFromGlobal(globalPos);
	if (!this->_ui.pixmap->rect().contains(pos))
		return QPoint();

	return pos;
}

bool BitmapView::contains(const QPoint &pos)
{
	return this->_ui.pixmap->rect().contains(pos);
}

//	remove
//QColor BitmapView::colorAt(const QPoint &pos)
//{
//	if (this->_image.isNull())
//		return QColor();
//	
//	if (!contains(pos))
//		return QColor();
//
//	return this->_image.pixelColor(pos);
//}

void BitmapView::updateInfo(const QPoint &pos)
{
	if (this->_image.isNull())
		return;

	QColor pixelColor = this->_image.pixelColor(pos);
	if (pixelColor.isValid()) {
		this->_ui.coords->setText(QString("%1, %2").arg(pos.x()).arg(pos.y()));
		this->_ui.color->setText(pixelColor.name(QColor::HexRgb));
	}
	else {
		this->_ui.coords->setText("");
		this->_ui.color->setText("");
	}
}

void BitmapView::fromFile(const QString &path)
{
	if (!QFile::exists(path))
		return;

	this->_image = QImage(path);
	this->refreshPixmap();
}

void BitmapView::fromOpenCVMat(const cv::Mat &src)
{
	Mat dest;
	cvtColor(src, dest, CV_BGR2RGB);

	this->_image = QImage((uchar*)dest.data, dest.cols, dest.rows, QImage::Format_RGB888);
	this->refreshPixmap();
}

void BitmapView::fromImage(const QImage &image)
{
	this->_image = image;
	this->refreshPixmap();
}

void BitmapView::refreshPixmap()
{
	if (this->_image.isNull())
		return;

	this->_ui.pixmap->setPixmap(QPixmap::fromImage(this->_image));
	this->update();
}