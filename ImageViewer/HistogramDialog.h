#pragma once

#include <QtWidgets/QDialog>
#include "ui_HistogramDialog.h"
#include <ImageHistogram.h>

class ColorView;
class HistogramView;

class HistogramDialog : public QDialog
{
	Q_OBJECT
public:
	enum Channel {
		GrayscaleChannel,
		RedChannel,
		GreenChannel,
		BlueChannel
	};

	explicit HistogramDialog(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	~HistogramDialog();

	void setHistogramm();
	void setViewData(const ImageBinarize::ImageHistogram& value);
	void setChannel(Channel channel);

private slots:
	void onChannelChanged();
	void onIndexChanged(unsigned int index);

private:
	void refreshUi();

private:
	Ui::HistogramDialog _ui;
	HistogramView* _histogramView;
	ColorView* _colorView;
	Channel _channel;
	ImageBinarize::ImageHistogram _histogram;
};



