#include "HistogramView.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>

#include <algorithm>

//	DEBUG
//#include <QDebug>
//	END DEBUG

HistogramView::HistogramView(QWidget *parent)
	: QWidget(parent)
	, _color(QColor::fromRgb(0, 0, 0))
	, _backgroundColor(QColor::fromRgb(0xFF, 0xFF, 0xFF))
{
	this->setFixedSize(256, 100);
	this->_data.fill(0);

	QCoreApplication::instance()->installEventFilter(this);
}

HistogramView::~HistogramView()
{
}

void HistogramView::setColor(const QColor& value)
{
	if (this->_color == value)
		return;

	this->_color = value;
	this->repaint();
}

QColor HistogramView::color() const
{
	return this->_color;
}

void HistogramView::setBackgroundColor(const QColor& value)
{
	if (this->_backgroundColor == value)
		return;

	this->_backgroundColor = value;
	this->repaint();
}

QColor HistogramView::backgroundColor() const
{
	return this->_backgroundColor;
}

void HistogramView::setViewData(const std::array<uint64_t, 256>& data)
{
	this->_data = data;
	this->repaint();
}

uint32_t HistogramView::at(unsigned int index) const
{
	return this->_data.at(index);
}

bool HistogramView::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseMove) {
		QMouseEvent* mouseMoveEvent = static_cast<QMouseEvent*>(event);

		QPoint cursorPos = this->mapFromGlobal(QCursor::pos());
		if (this->rect().contains(cursorPos)) {
			emit this->indexChanged(cursorPos.x());
		}
	}

	return false;
}

//	TODO: переделать построение гистограммы для лучшей наглядности
void HistogramView::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	painter.fillRect(0, 0, width(), height(), this->_backgroundColor);

	if (this->_data.empty())
		return;

	uint64_t total = 0;
	uint64_t max = 0;
	uint64_t average = 0;

	for (unsigned int i = 0; i < this->_data.size(); ++i) {
		total += this->_data[i];
		if (this->_data[i] > max)
			max = this->_data[i];
	}

	average = total / this->_data.size();

	//qDebug() << "total: " << total;
	//qDebug() << "max: " << max;
	//qDebug() << "average: " << average;

	//	TODO: implement stretching widget
	//	qreal barWidth = width() / (qreal)this->_data.size();

	double factor = static_cast<double>(this->height()) / max;
	for (unsigned int i = 0; i < this->_data.size(); ++i) {
		int h = factor * this->_data[i];
		painter.fillRect(i, height() - h, 1, h, this->_color);
	}
}

