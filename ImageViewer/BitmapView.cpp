#include "BitmapView.h"

#include <QtCore/QFile>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <qdebug.h>

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

void BitmapView::updateInfo(const QPoint &pos)
{
	if (this->_image.isNull())
		return;

	ImageBinarize::Color pixelColor = this->_image.pixelColor(pos.x(), pos.y());
	QColor color = QColor::fromRgb(pixelColor.red(), pixelColor.green(), pixelColor.blue());
	if (color.isValid()) {
		this->_ui.coords->setText(QString("%1, %2").arg(pos.x()).arg(pos.y()));
		this->_ui.color->setText(color.name(QColor::HexRgb));
	}
	else {
		this->_ui.coords->setText("");
		this->_ui.color->setText("");
	}
}

void BitmapView::setImage(const ImageBinarize::Image &image)
{
	this->_image = image;
	this->refreshPixmap();
}

const ImageBinarize::Image& BitmapView::image() const
{
	return this->_image;
}

void BitmapView::refreshPixmap()
{
	if (this->_image.isNull())
		return;

	//	TODO: переделать по-нормальному
	Mat src = this->_image.asOpenCVMat();
	Mat dest;
	cvtColor(src, dest, CV_BGR2RGB);

	QImage img = QImage((uchar*)dest.data, dest.cols, dest.rows, dest.step, QImage::Format_RGB888);
	this->_ui.pixmap->setPixmap(QPixmap::fromImage(img));
	this->update();
}