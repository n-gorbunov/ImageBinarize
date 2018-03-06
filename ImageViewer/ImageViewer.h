#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imageviewer.h"

class BitmapView;

class ImageViewer : public QMainWindow
{
	Q_OBJECT

public:
	ImageViewer(QWidget *parent = 0);
	~ImageViewer();

protected:
	bool eventFilter(QObject* object, QEvent* event);

private slots:
	void onOpenFile();

private:

private:
	Ui::ImageViewer _ui;
	BitmapView *_originalView;
	BitmapView *_processedView;

	QString _originalPath;
	QString _processedPath;
};
