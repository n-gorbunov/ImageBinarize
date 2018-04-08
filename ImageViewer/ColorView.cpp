#include "ColorView.h"

#include <QtGui/QPainter>
#include <QtGui/QLinearGradient>

ColorView::ColorView(QWidget *parent)
	: QWidget(parent)
	, _color(QColor::fromRgb(0xFF, 0xFF, 0xFF))
{
	this->setFixedSize(256, 20);
}

ColorView::~ColorView()
{
}

void ColorView::setColor(const QColor& value)
{
	if (this->_color == value)
		return;

	this->_color = value;
	this->repaint();
}

QColor ColorView::color() const
{
	return this->_color;
}

void ColorView::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	QLinearGradient gradient(0, 0, width(), 0);
	gradient.setColorAt(0, Qt::black);
	gradient.setColorAt(1, this->_color);
	painter.fillRect(0, 0, width(), height(), gradient);
}

