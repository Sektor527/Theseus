#include <cstdlib>
#include <iostream>
#include "Maze.h"
#include "Generators/GeneratorDepthFirst.h"

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
	for (size_t y = 0; y < maze->getPlotHeight(); ++y)
	{
		for (size_t x = 0; x < maze->getPlotWidth(); ++x)
		{
			char c;
			switch (maze->getPlotPixel(x, y))
			{
			case Wall:
				c = '*';
				break;
			case Space:
			case Entrance:
			case Exit:
			default:
				c = ' ';
				break;
			}
			std::cout << c << c;
		}
		std::cout << std::endl;
	}
}