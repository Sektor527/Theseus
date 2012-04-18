/********************************************************************************
** Form generated from reading UI file 'viewerqt.ui'
**
** Created: Wed 18. Apr 16:29:10 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERQT_H
#define UI_VIEWERQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerQtClass
{
public:
    QWidget *centralWidget;
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
        ViewerQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewerQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 21));
        ViewerQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewerQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViewerQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        ViewerQtClass->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(ViewerQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViewerQtClass->setStatusBar(statusBar);

        retranslateUi(ViewerQtClass);

        QMetaObject::connectSlotsByName(ViewerQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerQtClass)
    {
        ViewerQtClass->setWindowTitle(QApplication::translate("ViewerQtClass", "Theseus", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewerQtClass: public Ui_ViewerQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERQT_H
