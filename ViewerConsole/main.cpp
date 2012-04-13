#include <cstdlib>
#include <iostream>
#include "Data/Maze.h"
#include "Generators/GeneratorDepthFirst.h"
#include "Plotter/Plotter.h"

using namespace Theseus::Core;

void outputClear();
void outputMaze(Maze* maze);
void outputLegend();

int main(int argc, char** argv)
{
	// Determine size of maze
	size_t sizeX = 8, sizeY = 5;

	if (argc == 2)
	{
		sizeX = sizeY = atoi(argv[1]);
	}
	else if (argc >= 3)
	{
		sizeX = atoi(argv[1]);
		sizeY = atoi(argv[2]);
	}

	// Generate maze
	Maze* maze = new Maze(sizeX, sizeY);

	ConfiguratorDepthFirst conf;
	conf.RandomTraverse = true;
	GeneratorDepthFirst::generate(maze, conf);

	// Plot maze
	Plotter* plot = Plotter::plot(maze);

	for (size_t y = 0; y < plot->getSizeHeight(); ++y)
	{
		for (size_t x = 0; x < plot->getSizeWidth(); ++x)
		{
			char c;
			switch (plot->getPixel(x, y))
			{
			case Plotter::Wall:
				c = '*';
				break;
			case Plotter::Space:
			case Plotter::Entrance:
			case Plotter::Exit:
			default:
				c = ' ';
				break;
			}
			std::cout << c << c;
		}
		std::cout << std::endl;
	}
}