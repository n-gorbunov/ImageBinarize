#pragma once

#include <QtCore/QPoint>
#include <QtGui/QColor>
#include <Image.h>
#include "ui_bitmapview.h"

class BitmapView : public QWidget
{
	Q_OBJECT
public:
	explicit BitmapView(QWidget* parent = 0);
	~BitmapView();

	QPoint mapToBitmap(const QPoint &globalPos);
	bool contains(const QPoint &pos);
	void updateInfo(const QPoint &pos);

	void setImage(const ImageBinarize::Image &image);
	const ImageBinarize::Image &image() const;

private:
	void refreshPixmap();

private:
	Ui::BitmapView _ui;
	ImageBinarize::Image _image;
	bool _tracking;
};