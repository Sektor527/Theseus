#include "viewerqt.h"
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>

#include "Data/Maze.h"
#include "Generators/GeneratorDepthFirst.h"
#include "Plotter/Plotter.h"

using namespace Theseus::Core;

ViewerQt::ViewerQt(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

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

	QGraphicsScene* scene = new QGraphicsScene();

	Plotter* plot = Plotter::plot(_maze);

	QPen pen;
	pen.setStyle(Qt::NoPen);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);

	for (int y = 0; y < plot->getSizeHeight(); ++y)
	{
		for (int x = 0; x < plot->getSizeWidth(); ++x)
		{
			switch (plot->getPixel(x, y))
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
			
			QGraphicsRectItem* rect = new QGraphicsRectItem(x, y, 1, 1);
			rect->setPen(pen);
			rect->setBrush(brush);

			scene->addItem(rect);
		}
	}

	ui.graphicsView->setScene(scene);
}