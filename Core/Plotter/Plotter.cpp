#include "Plotter.h"

#include "data/Maze.h"
#include "data/Cell.h"

namespace Theseus { namespace Core {

Plotter* Plotter::plot(Maze* maze)
{
	Plotter* result = new Plotter();

	size_t width = maze->getSizeWidth() * 2 + 1;
	size_t height = maze->getSizeHeight() * 2 + 1;

	char** plot = new char*[height];

	for (size_t y = 0; y < height; ++y)
	{
		plot[y] = new char[width];
		for (size_t x = 0; x < width; ++x)
		{
			plot[y][x] = (char)Void;

			if (y % 2 == 0) // Horizontal wall line
			{
				if (y == maze->getSizeHeight() * 2) // Last horizontal line
				{
					plot[y][x] = Wall;
				}
				else if (x % 2 == 0) // Vertical wall line
				{
					// Corner points are always filled
					plot[y][x] = Wall;
				}
				else // Vertical room line
				{
					// North-south passages
					Cell* cell = maze->getCell((x - 1) / 2, y / 2);
					if (cell->isOpenNorth())
						plot[y][x] = Space;
					else
						plot[y][x] = Wall;
				}
			}
			else // Horizontal room line
			{
				if (x == maze->getSizeWidth() * 2) // Last vertical line
				{
					plot[y][x] = Wall;
				}
				else if (x % 2 == 0) // Vertical wall line
				{
					Cell* cell = maze->getCell(x / 2, (y - 1) / 2);
					if (cell->isOpenWest())
						plot[y][x] = Space;
					else
						plot[y][x] = Wall;
				}
				else // Vertical room line
				{
					plot[y][x] = Space;
				}
			}
		}
	}

	// Entrance and exit
	for (size_t h = 0; h < maze->getSizeHeight(); ++h)
	{
		for (size_t w = 0; w < maze->getSizeWidth(); ++w)
		{
			Cell* cell = maze->getCell(w, h);
			if (cell != maze->getEntrance() && cell != maze->getExit()) continue;

			size_t plotX = w * 2 + 1;
			size_t plotY = h * 2 + 1;

			if (cell->getNorth() == NULL)
				plotY--;
			else if (cell->getWest() == NULL)
				plotX--;
			else if (cell->getSouth() == NULL)
				plotY++;
			else if (cell->getEast() == NULL)
				plotX++;

			if (cell == maze->getEntrance())
				plot[plotY][plotX] = Entrance;

			else if (cell == maze->getExit())
				plot[plotY][plotX] = Exit;
		}
	}

	result->_width = width;
	result->_height = height;
	result->_plot = plot;
	return result;
}

Plotter::~Plotter()
{
	for (size_t y = 0; y < _height; ++y)
	{
		delete[] _plot[y];
	}

	delete[] _plot;
}

size_t Plotter::getSizeWidth() const
{
	return _width;
}

size_t Plotter::getSizeHeight() const
{
	return _height;
}

char Plotter::getPixel(size_t x, size_t y) const
{
	return _plot[y][x];
}

}}