#include "CompareView.h"

#include <QtGui/QMouseEvent>

CompareView::CompareView(QWidget *parent)
	: QSplitter(parent)
{
	
	this->_leftView = new BitmapView();
	this->_rightView = new BitmapView();

	this->addWidget(this->_leftView);
	this->addWidget(this->_rightView);

	QCoreApplication::instance()->installEventFilter(this);
}

CompareView::~CompareView()
{
}

void CompareView::setLeftImage(const ImageBinarize::Image &value)
{
	this->_leftImage = value;
	this->_leftView->setImage(this->_leftImage);
}

ImageBinarize::Image& CompareView::leftImage()
{
	return this->_leftImage;
}

void CompareView::setRightImage(const ImageBinarize::Image &value)
{
	this->_rightImage = value;
	this->_rightView->setImage(this->_rightImage);
}

ImageBinarize::Image& CompareView::rightImage()
{
	return this->_rightImage;
}

bool CompareView::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseMove) {
		QMouseEvent* mouseMoveEvent = static_cast<QMouseEvent*>(event);

		QPoint cursorPos = QCursor::pos();
		QPoint originalPos = this->_leftView->mapToBitmap(cursorPos);
		QPoint processedPos = this->_rightView->mapToBitmap(cursorPos);
		if (!originalPos.isNull() || !processedPos.isNull()) {
			if (!originalPos.isNull()) {
				this->_leftView->updateInfo(originalPos);
				this->_rightView->updateInfo(originalPos);
			}
			else if (!processedPos.isNull()) {
				this->_leftView->updateInfo(processedPos);
				this->_rightView->updateInfo(processedPos);
			}
		}
	}

	return false;
}
