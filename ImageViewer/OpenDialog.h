#pragma once

#include <QtWidgets/QDialog>
#include "ui_opendialog.h"

class OpenDialog : public QDialog
{
	Q_OBJECT
public:
	explicit OpenDialog(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	~OpenDialog();

	QString originalPath() const;
	QString processedPath() const;

private slots:
	void onBrowseOriginal();
	void onBrowseProcessed();
	void onAccepted();

private:
	void saveRUD();

private:
	Ui::OpenDialog _ui;
};



