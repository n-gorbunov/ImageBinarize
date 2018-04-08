#pragma once

#include <QtWidgets/QDialog>
#include "ui_OpenForCompareDialog.h"

class OpenForCompareDialog : public QDialog
{
	Q_OBJECT
public:
	explicit OpenForCompareDialog(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	~OpenForCompareDialog();

	QString originalPath() const;
	QString processedPath() const;

private slots:
	void onBrowseOriginal();
	void onBrowseProcessed();
	void onAccepted();

private:
	void saveRUD();

private:
	Ui::OpenForCompareDialog _ui;
};



