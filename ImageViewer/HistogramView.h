#pragma once

#include <QtWidgets/QWidget>
#include <array>

class HistogramView : public QWidget
{
	Q_OBJECT

public:
	explicit HistogramView(QWidget *parent = nullptr);
	~HistogramView();

	void setColor(const QColor& value);
	QColor color() const;

	void setBackgroundColor(const QColor& value);
	QColor backgroundColor() const;

	void setViewData(const std::array<uint64_t, 256>& data);
	const std::array<uint64_t, 256> &data() const;

	uint32_t at(unsigned int index) const;

signals:
	void indexChanged(unsigned int index);

protected:
	bool eventFilter(QObject* object, QEvent* event);
	void paintEvent(QPaintEvent *event) override;

private:
	std::array<uint64_t, 256> _data;
	QColor _color;
	QColor _backgroundColor;
};