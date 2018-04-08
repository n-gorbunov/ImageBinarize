#include "OpenForCompareDialog.h"

#include <QtCore/QSettings>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFileDialog>

OpenForCompareDialog::OpenForCompareDialog(QWidget* parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	this->_ui.setupUi(this);

	QObject::connect(this->_ui.browseOriginalPath, &QPushButton::clicked, this, &OpenForCompareDialog::onBrowseOriginal);
	QObject::connect(this->_ui.browseProcessedPath, &QPushButton::clicked, this, &OpenForCompareDialog::onBrowseProcessed);
	QObject::connect(this->_ui.buttonBox, &QDialogButtonBox::accepted, this, &OpenForCompareDialog::onAccepted);
	QObject::connect(this->_ui.buttonBox, &QDialogButtonBox::rejected, this, &OpenForCompareDialog::reject);
}

OpenForCompareDialog::~OpenForCompareDialog()
{

}

QString OpenForCompareDialog::originalPath() const
{
	return this->_ui.originalPath->text();
}

QString OpenForCompareDialog::processedPath() const
{
	return this->_ui.processedPath->text();
}

void OpenForCompareDialog::onBrowseOriginal()
{
	QSettings settings;
	QString path = QFileDialog::getOpenFileName(this, tr("Choose original image file"), settings.value("OriginalFile", "").toString(), "*.*");

	if (!path.isEmpty()) {
		this->_ui.originalPath->setText(path);
	}
}

void OpenForCompareDialog::onBrowseProcessed()
{
	QSettings settings;
	QString path = QFileDialog::getOpenFileName(this, tr("Choose processed image file"), settings.value("ProcessedFile", "").toString(), "*.*");

	if (!path.isEmpty()) {
		this->_ui.processedPath->setText(path);
	}
}

void OpenForCompareDialog::onAccepted()
{
	this->saveRUD();
	this->accept();
}

void OpenForCompareDialog::saveRUD()
{
	QSettings settings;
	settings.setValue("OriginalFile", this->_ui.originalPath->text());
	settings.setValue("ProcessedFile", this->_ui.processedPath->text());
}