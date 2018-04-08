/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionTreshold;
    QAction *actionCompare;
    QAction *actionHistogram;
    QAction *actionGrayscale;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *switcher;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInfo;
    QMenu *menuProcess;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->resize(600, 400);
        actionOpen = new QAction(ImageViewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(ImageViewer);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionTreshold = new QAction(ImageViewer);
        actionTreshold->setObjectName(QStringLiteral("actionTreshold"));
        actionCompare = new QAction(ImageViewer);
        actionCompare->setObjectName(QStringLiteral("actionCompare"));
        actionHistogram = new QAction(ImageViewer);
        actionHistogram->setObjectName(QStringLiteral("actionHistogram"));
        actionGrayscale = new QAction(ImageViewer);
        actionGrayscale->setObjectName(QStringLiteral("actionGrayscale"));
        centralWidget = new QWidget(ImageViewer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        switcher = new QStackedWidget(centralWidget);
        switcher->setObjectName(QStringLiteral("switcher"));

        verticalLayout->addWidget(switcher);

        ImageViewer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        ImageViewer->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionCompare);
        menuFile->addAction(actionExit);
        menuInfo->addAction(actionHistogram);
        menuProcess->addAction(actionGrayscale);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "Image Compare", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ImageViewer", "Open", Q_NULLPTR));
        actionExit->setText(QApplication::translate("ImageViewer", "Exit", Q_NULLPTR));
        actionTreshold->setText(QApplication::translate("ImageViewer", "Treshold", Q_NULLPTR));
        actionCompare->setText(QApplication::translate("ImageViewer", "Compare", Q_NULLPTR));
        actionHistogram->setText(QApplication::translate("ImageViewer", "Image Histogram", Q_NULLPTR));
        actionGrayscale->setText(QApplication::translate("ImageViewer", "Grayscale", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("ImageViewer", "File", Q_NULLPTR));
        menuInfo->setTitle(QApplication::translate("ImageViewer", "Info", Q_NULLPTR));
        menuProcess->setTitle(QApplication::translate("ImageViewer", "Process", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
