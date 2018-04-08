/********************************************************************************
** Form generated from reading UI file 'HistogramDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMDIALOG_H
#define UI_HISTOGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QRadioButton *grayscale;
    QRadioButton *redChannel;
    QRadioButton *greenChannel;
    QRadioButton *blueChannel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *histogramContainer;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLabel *index;
    QLabel *label_4;
    QLabel *pixelCount;

    void setupUi(QWidget *HistogramDialog)
    {
        if (HistogramDialog->objectName().isEmpty())
            HistogramDialog->setObjectName(QStringLiteral("HistogramDialog"));
        HistogramDialog->resize(278, 292);
        HistogramDialog->setMinimumSize(QSize(278, 292));
        HistogramDialog->setMaximumSize(QSize(278, 320));
        verticalLayout_3 = new QVBoxLayout(HistogramDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(HistogramDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        grayscale = new QRadioButton(HistogramDialog);
        grayscale->setObjectName(QStringLiteral("grayscale"));
        grayscale->setChecked(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, grayscale);

        redChannel = new QRadioButton(HistogramDialog);
        redChannel->setObjectName(QStringLiteral("redChannel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, redChannel);

        greenChannel = new QRadioButton(HistogramDialog);
        greenChannel->setObjectName(QStringLiteral("greenChannel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, greenChannel);

        blueChannel = new QRadioButton(HistogramDialog);
        blueChannel->setObjectName(QStringLiteral("blueChannel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, blueChannel);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        exitButton = new QPushButton(HistogramDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout->addWidget(exitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        histogramContainer = new QVBoxLayout();
        histogramContainer->setObjectName(QStringLiteral("histogramContainer"));

        verticalLayout_3->addLayout(histogramContainer);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(HistogramDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        index = new QLabel(HistogramDialog);
        index->setObjectName(QStringLiteral("index"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, index);

        label_4 = new QLabel(HistogramDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        pixelCount = new QLabel(HistogramDialog);
        pixelCount->setObjectName(QStringLiteral("pixelCount"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pixelCount);


        verticalLayout_3->addLayout(formLayout_2);


        retranslateUi(HistogramDialog);

        QMetaObject::connectSlotsByName(HistogramDialog);
    } // setupUi

    void retranslateUi(QWidget *HistogramDialog)
    {
        HistogramDialog->setWindowTitle(QApplication::translate("HistogramDialog", "Image Histogram", Q_NULLPTR));
        label->setText(QApplication::translate("HistogramDialog", "Channel", Q_NULLPTR));
        grayscale->setText(QApplication::translate("HistogramDialog", "GrayScale", Q_NULLPTR));
        redChannel->setText(QApplication::translate("HistogramDialog", "Red", Q_NULLPTR));
        greenChannel->setText(QApplication::translate("HistogramDialog", "Green", Q_NULLPTR));
        blueChannel->setText(QApplication::translate("HistogramDialog", "Blue", Q_NULLPTR));
        exitButton->setText(QApplication::translate("HistogramDialog", "Exit", Q_NULLPTR));
        label_2->setText(QApplication::translate("HistogramDialog", "Index:", Q_NULLPTR));
        index->setText(QApplication::translate("HistogramDialog", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("HistogramDialog", "Pixels:", Q_NULLPTR));
        pixelCount->setText(QApplication::translate("HistogramDialog", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HistogramDialog: public Ui_HistogramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMDIALOG_H
