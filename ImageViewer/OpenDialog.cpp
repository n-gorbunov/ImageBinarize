#include "OpenDialog.h"

#include <QtCore/QSettings>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFileDialog>

OpenDialog::OpenDialog(QWidget* parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	this->_ui.setupUi(this);

	QObject::connect(this->_ui.browseOriginalPath, &QPushButton::clicked, this, &OpenDialog::onBrowseOriginal);
	QObject::connect(this->_ui.browseProcessedPath, &QPushButton::clicked, this, &OpenDialog::onBrowseProcessed);
	QObject::connect(this->_ui.buttonBox, &QDialogButtonBox::accepted, this, &OpenDialog::onAccepted);
	QObject::connect(this->_ui.buttonBox, &QDialogButtonBox::rejected, this, &OpenDialog::reject);
}

OpenDialog::~OpenDialog()
{

}

QString OpenDialog::originalPath() const
{
	return this->_ui.originalPath->text();
}

QString OpenDialog::processedPath() const
{
	return this->_ui.processedPath->text();
}

void OpenDialog::onBrowseOriginal()
{
	QSettings settings;
	QString path = QFileDialog::getOpenFileName(this, tr("Choose original image file"), settings.value("OriginalFile", "").toString(), "*.*");

	if (!path.isEmpty()) {
		this->_ui.originalPath->setText(path);
	}
}

void OpenDialog::onBrowseProcessed()
{
	QSettings settings;
	QString path = QFileDialog::getOpenFileName(this, tr("Choose processed image file"), settings.value("ProcessedFile", "").toString(), "*.*");

	if (!path.isEmpty()) {
		this->_ui.processedPath->setText(path);
	}
}

void OpenDialog::onAccepted()
{
	this->saveRUD();
	this->accept();
}

void OpenDialog::saveRUD()
{
	QSettings settings;
	settings.setValue("OriginalFile", this->_ui.originalPath->text());
	settings.setValue("ProcessedFile", this->_ui.processedPath->text());
}