/********************************************************************************
** Form generated from reading UI file 'viewerqt.ui'
**
** Created: Thu 3. May 14:42:20 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERQT_H
#define UI_VIEWERQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerQtClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QSpinBox *width;
    QSpinBox *height;
    QLabel *label;
    QCheckBox *shuffle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewerQtClass)
    {
        if (ViewerQtClass->objectName().isEmpty())
            ViewerQtClass->setObjectName(QString::fromUtf8("ViewerQtClass"));
        ViewerQtClass->resize(693, 501);
        ViewerQtClass->setDockOptions(QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(ViewerQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(130, 10, 551, 421));
        width = new QSpinBox(centralWidget);
        width->setObjectName(QString::fromUtf8("width"));
        width->setGeometry(QRect(40, 20, 41, 22));
        width->setMinimum(2);
        width->setValue(20);
        height = new QSpinBox(centralWidget);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(80, 20, 41, 22));
        height->setMinimum(2);
        height->setValue(12);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 21, 21));
        shuffle = new QCheckBox(centralWidget);
        shuffle->setObjectName(QString::fromUtf8("shuffle"));
        shuffle->setGeometry(QRect(10, 50, 111, 17));
        shuffle->setChecked(true);
        ViewerQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewerQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 21));
        ViewerQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewerQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViewerQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewerQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViewerQtClass->setStatusBar(statusBar);

        retranslateUi(ViewerQtClass);

        QMetaObject::connectSlotsByName(ViewerQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerQtClass)
    {
        ViewerQtClass->setWindowTitle(QApplication::translate("ViewerQtClass", "Theseus", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewerQtClass", "Size", 0, QApplication::UnicodeUTF8));
        shuffle->setText(QApplication::translate("ViewerQtClass", "Shuffle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewerQtClass: public Ui_ViewerQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERQT_H
