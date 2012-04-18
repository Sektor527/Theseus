#ifndef VIEWERQT_H
#define VIEWERQT_H

#include <QtGui/QMainWindow>
#include "ui_viewerqt.h"

class ConfiguratorModel;

class ViewerQt : public QMainWindow
{
	Q_OBJECT

public:
	ViewerQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ViewerQt();

private:
	Ui::ViewerQtClass ui;
};

#endif // VIEWERQT_H
