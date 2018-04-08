/********************************************************************************
** Form generated from reading UI file 'OpenForCompareDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENFORCOMPAREDIALOG_H
#define UI_OPENFORCOMPAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OpenForCompareDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *originalLabel;
    QLineEdit *originalPath;
    QPushButton *browseOriginalPath;
    QLabel *processedLabel;
    QLineEdit *processedPath;
    QPushButton *browseProcessedPath;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenForCompareDialog)
    {
        if (OpenForCompareDialog->objectName().isEmpty())
            OpenForCompareDialog->setObjectName(QStringLiteral("OpenForCompareDialog"));
        OpenForCompareDialog->setWindowModality(Qt::WindowModal);
        OpenForCompareDialog->resize(450, 120);
        OpenForCompareDialog->setMinimumSize(QSize(400, 80));
        OpenForCompareDialog->setMaximumSize(QSize(450, 120));
        gridLayout = new QGridLayout(OpenForCompareDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        originalLabel = new QLabel(OpenForCompareDialog);
        originalLabel->setObjectName(QStringLiteral("originalLabel"));

        gridLayout->addWidget(originalLabel, 0, 0, 1, 1);

        originalPath = new QLineEdit(OpenForCompareDialog);
        originalPath->setObjectName(QStringLiteral("originalPath"));

        gridLayout->addWidget(originalPath, 0, 1, 1, 1);

        browseOriginalPath = new QPushButton(OpenForCompareDialog);
        browseOriginalPath->setObjectName(QStringLiteral("browseOriginalPath"));

        gridLayout->addWidget(browseOriginalPath, 0, 2, 1, 1);

        processedLabel = new QLabel(OpenForCompareDialog);
        processedLabel->setObjectName(QStringLiteral("processedLabel"));

        gridLayout->addWidget(processedLabel, 1, 0, 1, 1);

        processedPath = new QLineEdit(OpenForCompareDialog);
        processedPath->setObjectName(QStringLiteral("processedPath"));

        gridLayout->addWidget(processedPath, 1, 1, 1, 1);

        browseProcessedPath = new QPushButton(OpenForCompareDialog);
        browseProcessedPath->setObjectName(QStringLiteral("browseProcessedPath"));

        gridLayout->addWidget(browseProcessedPath, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(OpenForCompareDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);


        retranslateUi(OpenForCompareDialog);

        QMetaObject::connectSlotsByName(OpenForCompareDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenForCompareDialog)
    {
        OpenForCompareDialog->setWindowTitle(QApplication::translate("OpenForCompareDialog", "Select image files", Q_NULLPTR));
        originalLabel->setText(QApplication::translate("OpenForCompareDialog", "Original:", Q_NULLPTR));
        browseOriginalPath->setText(QApplication::translate("OpenForCompareDialog", "Browse...", Q_NULLPTR));
        processedLabel->setText(QApplication::translate("OpenForCompareDialog", "Processed:", Q_NULLPTR));
        browseProcessedPath->setText(QApplication::translate("OpenForCompareDialog", "Browse...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpenForCompareDialog: public Ui_OpenForCompareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFORCOMPAREDIALOG_H
