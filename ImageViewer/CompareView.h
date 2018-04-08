#pragma once

#include <Image.h>
#include <QtWidgets/QSplitter>
#include "BitmapView.h"

class CompareView : public QSplitter
{
	Q_OBJECT
public:
	CompareView(QWidget *parent = 0);
	~CompareView();

	void setLeftImage(const ImageBinarize::Image &value);
	ImageBinarize::Image& leftImage();

	void setRightImage(const ImageBinarize::Image &value);
	ImageBinarize::Image& rightImage();

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	BitmapView *_leftView;
	BitmapView *_rightView;

	ImageBinarize::Image _leftImage;
	ImageBinarize::Image _rightImage;
};