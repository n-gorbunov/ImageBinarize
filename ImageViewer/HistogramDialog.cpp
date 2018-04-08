#include "HistogramDialog.h"

#include <QtCore/QSettings>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFileDialog>

//	ImageBinarize headers
#include <ImageHistogram.h>

#include "ColorView.h"
#include "HistogramView.h"

HistogramDialog::HistogramDialog(QWidget* parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
	, _histogramView(nullptr)
	, _colorView(nullptr)
	, _channel(GrayscaleChannel)
{
	this->_ui.setupUi(this);

	QObject::connect(this->_ui.grayscale, &QRadioButton::clicked, this, &HistogramDialog::onChannelChanged);
	QObject::connect(this->_ui.redChannel, &QRadioButton::clicked, this, &HistogramDialog::onChannelChanged);
	QObject::connect(this->_ui.greenChannel, &QRadioButton::clicked, this, &HistogramDialog::onChannelChanged);
	QObject::connect(this->_ui.blueChannel, &QRadioButton::clicked, this, &HistogramDialog::onChannelChanged);
	QObject::connect(this->_ui.exitButton, &QPushButton::clicked, this, &QDialog::accept);

	this->_histogramView = new HistogramView(this);
	this->_ui.histogramContainer->addWidget(this->_histogramView);
	QObject::connect(this->_histogramView, &HistogramView::indexChanged, this, &HistogramDialog::onIndexChanged);

	this->_colorView = new ColorView(this);
	this->_ui.histogramContainer->addWidget(this->_colorView);

	this->refreshUi();
}

void HistogramDialog::setViewData(const ImageBinarize::ImageHistogram& value)
{
	this->_histogram = value;
	this->refreshUi();
}

void HistogramDialog::setChannel(Channel channel)
{
	this->_channel = channel;
}

HistogramDialog::~HistogramDialog()
{

}

void HistogramDialog::onChannelChanged()
{
	QObject* radioButton = sender();
	if (!radioButton)
		return;

	QString name = radioButton->objectName();
	if (name == "grayscale") {
		this->_channel = HistogramDialog::GrayscaleChannel;
	}
	else if (name == "redChannel") {
		this->_channel = HistogramDialog::RedChannel;
	}
	else if (name == "greenChannel") {
		this->_channel = HistogramDialog::GreenChannel;
	}
	else if (name == "blueChannel") {
		this->_channel = HistogramDialog::BlueChannel;
	}

	this->refreshUi();
}

void HistogramDialog::onIndexChanged(unsigned int index)
{
	this->_ui.index->setText(QString("%1").arg(index));
	this->_ui.pixelCount->setText(QString("%1").arg(this->_histogramView->at(index)));
}

void HistogramDialog::refreshUi()
{
	switch (this->_channel) {
	case HistogramDialog::GrayscaleChannel:
		this->_histogramView->setViewData(this->_histogram.grayscale());
		this->_colorView->setColor(QColor::fromRgb(0xFF, 0xFF, 0xFF));
		break;
	case HistogramDialog::RedChannel:
		this->_histogramView->setViewData(this->_histogram.red());
		this->_colorView->setColor(QColor::fromRgb(0xFF, 0x0, 0x0));
		break;
	case HistogramDialog::GreenChannel:
		this->_histogramView->setViewData(this->_histogram.green());
		this->_colorView->setColor(QColor::fromRgb(0x0, 0xFF, 0x0));
		break;
	case HistogramDialog::BlueChannel:
		this->_histogramView->setViewData(this->_histogram.blue());
		this->_colorView->setColor(QColor::fromRgb(0x0, 0x0, 0xFF));
		break;
	}
}
