#pragma once

#include <QtGui\QColor>
#include <QtGui\QImage>
#include "ui_bitmapview.h"

#include <opencv2\core\mat.hpp>

class BitmapView : public QWidget
{
	Q_OBJECT

public:
	explicit BitmapView(QWidget* parent = 0);
	~BitmapView();

	QPoint mapToBitmap(const QPoint &globalPos);

	bool contains(const QPoint &pos);

	void updateInfo(const QPoint &pos);

	void fromFile(const QString &path);
	void fromOpenCVMat(const cv::Mat &src);
	void fromImage(const QImage &image);

private:
	void refreshPixmap();

private:
	Ui::BitmapView _ui;
	QImage _image;
	bool _tracking;
};