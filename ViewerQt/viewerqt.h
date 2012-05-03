#ifndef VIEWERQT_H
#define VIEWERQT_H

#include <QtGui/QMainWindow>
#include "ui_viewerqt.h"

namespace Theseus { namespace Core {
	class Maze;
	class Plotter;
}}

class ViewerQt : public QMainWindow
{
	Q_OBJECT

public:
	ViewerQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ViewerQt();

protected:
	virtual void keyPressEvent(QKeyEvent* event);

private:
	void createMaze();
	void drawMaze();
	void drawPixel(size_t x, size_t y);
	void moveAvatar(size_t x, size_t y);

	void cleanup();

private:
	Ui::ViewerQtClass ui;
	QGraphicsScene* _scene;

	Theseus::Core::Maze* _maze;
	Theseus::Core::Plotter* _plot;

	size_t _avatarX;
	size_t _avatarY;

};

#endif // VIEWERQT_H
