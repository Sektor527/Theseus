#ifndef VIEWERQT_H
#define VIEWERQT_H

#include <QtGui/QMainWindow>
#include "ui_viewerqt.h"

namespace Theseus { namespace Core {
	class Maze;
}}

class ViewerQt : public QMainWindow
{
	Q_OBJECT

public:
	ViewerQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ViewerQt();

private:
	void createMaze();

private:
	Ui::ViewerQtClass ui;

	Theseus::Core::Maze* _maze;
};

#endif // VIEWERQT_H
