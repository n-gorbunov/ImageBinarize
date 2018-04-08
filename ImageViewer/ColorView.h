#pragma once

#include <QtWidgets/QWidget>

class ColorView : public QWidget
{
	Q_OBJECT

public:
	explicit ColorView(QWidget *parent = nullptr);
	~ColorView();

	void setColor(const QColor& value);
	QColor color() const;

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	QColor _color;
};