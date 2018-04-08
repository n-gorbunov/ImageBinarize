#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imageviewer.h"
#include <Image.h>

class BitmapView;
class CompareView;

class ImageViewer : public QMainWindow
{
	Q_OBJECT
public:
	enum Mode
	{
		View = 0,
		Compare
	};

	ImageViewer(QWidget *parent = 0);
	~ImageViewer();

private slots:
	void onOpenForCompare();
	void onOpenFile();
	void onViewHistogram();

private:
	void updateUi();

private:
	Ui::ImageViewer _ui;
	CompareView *_compareView;
	BitmapView *_imageView;
	Mode _mode;

	ImageBinarize::Image _left;
	ImageBinarize::Image _right;
};
