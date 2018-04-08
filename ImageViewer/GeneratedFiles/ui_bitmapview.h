/********************************************************************************
** Form generated from reading UI file 'bitmapview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BITMAPVIEW_H
#define UI_BITMAPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BitmapView
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QLabel *pixmap;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *coords;
    QLabel *color;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *BitmapView)
    {
        if (BitmapView->objectName().isEmpty())
            BitmapView->setObjectName(QStringLiteral("BitmapView"));
        BitmapView->resize(317, 494);
        verticalLayout = new QVBoxLayout(BitmapView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        scrollArea = new QScrollArea(BitmapView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        pixmap = new QLabel();
        pixmap->setObjectName(QStringLiteral("pixmap"));
        pixmap->setGeometry(QRect(0, 0, 313, 454));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pixmap->sizePolicy().hasHeightForWidth());
        pixmap->setSizePolicy(sizePolicy);
        pixmap->setMinimumSize(QSize(200, 200));
        pixmap->setCursor(QCursor(Qt::CrossCursor));
        pixmap->setScaledContents(false);
        pixmap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollArea->setWidget(pixmap);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        coords = new QLineEdit(BitmapView);
        coords->setObjectName(QStringLiteral("coords"));
        coords->setMaximumSize(QSize(100, 16777215));
        coords->setReadOnly(true);

        horizontalLayout->addWidget(coords);

        color = new QLabel(BitmapView);
        color->setObjectName(QStringLiteral("color"));
        color->setMinimumSize(QSize(100, 20));
        color->setMaximumSize(QSize(100, 20));
        color->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(color);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BitmapView);

        QMetaObject::connectSlotsByName(BitmapView);
    } // setupUi

    void retranslateUi(QWidget *BitmapView)
    {
        BitmapView->setWindowTitle(QString());
        pixmap->setText(QString());
        color->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BitmapView: public Ui_BitmapView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITMAPVIEW_H
