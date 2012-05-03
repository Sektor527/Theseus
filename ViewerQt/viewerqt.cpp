#include "viewerqt.h"
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QLabel>

#include "Data/Maze.h"
#include "Generators/GeneratorDepthFirst.h"
#include "Plotter/Plotter.h"

using namespace Theseus::Core;

ViewerQt::ViewerQt(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	QLabel* label = new QLabel();
	label->setText("<space> - Create new maze | <q> - Quit");
	ui.statusBar->addWidget(label);

	ui.graphicsView->scale(3.f,3.f);

	createMaze();
}

ViewerQt::~ViewerQt()
{

}

void ViewerQt::createMaze()
{
	_maze = new Maze(100, 60);
	ConfiguratorDepthFirst conf;
	conf.RandomTraverse = true;
	GeneratorDepthFirst::generate(_maze, conf);

	_scene = new QGraphicsScene();
	ui.graphicsView->setScene(_scene);


	_plot = Plotter::plot(_maze);

	QPen pen;
	pen.setStyle(Qt::NoPen);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);

	for (int y = 0; y < _plot->getSizeHeight(); ++y)
	{
		for (int x = 0; x < _plot->getSizeWidth(); ++x)
		{
			if (_plot->getPixel(x,y) == Plotter::Pixels::Entrance)
			{
				_avatarX = x;
				_avatarY = y;
			}

			drawPixel(x, y);
		}
	}
}

void ViewerQt::keyPressEvent(QKeyEvent* event)
{
	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_Space)
		createMaze();

	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_Q)
		close();

	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_W)
		moveAvatar(_avatarX, _avatarY-1);

	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_A)
		moveAvatar(_avatarX-1, _avatarY);

	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_S)
		moveAvatar(_avatarX, _avatarY+1);

	if (event->type() == QEvent::KeyPress && event->key() == Qt::Key_D)
		moveAvatar(_avatarX+1, _avatarY);
}

void ViewerQt::moveAvatar(size_t x, size_t y)
{
	if (_plot->getPixel(x, y) != Plotter::Pixels::Space) return;

	size_t oldX = _avatarX;
	size_t oldY = _avatarY;
	_avatarX = x;
	_avatarY = y;
	drawPixel(oldX, oldY);
	drawPixel(_avatarX, _avatarY);
}

void ViewerQt::drawPixel(size_t x, size_t y)
{
	QPen pen;
	pen.setStyle(Qt::NoPen);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);

	switch (_plot->getPixel(x, y))
	{
	case Plotter::Pixels::Space:
		brush.setColor(QColor("White"));
		break;

	case Plotter::Pixels::Wall:
		brush.setColor(QColor("Black"));
		break;

	case Plotter::Pixels::Entrance:
	case Plotter::Pixels::Exit:
		brush.setColor(QColor("YellowGreen"));
		break;

	default:
		brush.setColor(QColor("White"));
		break;
	}

	if (_avatarX == x && _avatarY == y)
		brush.setColor(QColor("Red"));

	QGraphicsRectItem* rect = new QGraphicsRectItem(x, y, 1, 1);
	rect->setPen(pen);
	rect->setBrush(brush);

	_scene->addItem(rect);
}