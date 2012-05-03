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
	, _maze(NULL), _plot(NULL)
{
	ui.setupUi(this);

	QLabel* label = new QLabel();
	label->setText("<space> - Create new maze | <q> - Quit");
	ui.statusBar->addWidget(label);

	_scene = new QGraphicsScene();
	ui.graphicsView->setScene(_scene);
	ui.graphicsView->scale(5.f,5.f);

	createMaze();
}

ViewerQt::~ViewerQt()
{
	cleanup();
}

void ViewerQt::cleanup()
{
	if (_maze)
	{
		delete _maze;
		_maze = NULL;
	}

	if (_plot) 
	{
		delete _plot;
		_plot = NULL;
	}
}

void ViewerQt::createMaze()
{
	cleanup();

	_maze = new Maze(ui.width->value(), ui.height->value());

	ConfiguratorDepthFirst conf;
	conf.RandomTraverse = ui.shuffle->checkState();
	GeneratorDepthFirst::generate(_maze, conf);

	_plot = Plotter::plot(_maze);

	drawMaze();
}

void ViewerQt::drawMaze()
{
	_scene->clear();

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
