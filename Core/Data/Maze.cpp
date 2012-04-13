#include "Maze.h"

#include <cstdlib>
#include "Cell.h"

namespace Theseus { namespace Core {

Maze::Maze(size_t width, size_t height)
: _width(width), _height(height)
{
	if (_width == 0) _width = 1;
	if (_height == 0) _height = 1;

	// Create cells
	_cells.resize(_width * _height);
	for (size_t i = 0; i < _width * _height; ++i)
		_cells[i] = new Cell();

	// Link cells
	for (size_t h = 0; h < _height; ++h)
	{
		for (size_t w = 0; w < _width; ++w)
		{
			Cell* cell = getCell(w, h);

			if (w > 0) cell->setWest(getCell(w-1, h));
			if (w < _width - 1) cell->setEast(getCell(w+1, h));
			if (h > 0) cell->setNorth(getCell(w, h-1));
			if (h < _height - 1) cell->setSouth(getCell(w, h+1));
		}
	}

	// Set default entrance and exit
	_entrance = getCell(0,0);
	_exit = getCell(getSizeWidth() - 1, getSizeHeight() - 1);
}

Maze::~Maze()
{
	for (std::vector<Cell*>::iterator it = _cells.begin(); it != _cells.end(); ++it)
		delete *it;

	_cells.clear();

	_entrance = NULL;
	_exit = NULL;
}

size_t Maze::getSizeWidth() const
{
	return _width;
}

size_t Maze::getSizeHeight() const
{
	return _height;
}

Cell* Maze::getCell(size_t x, size_t y) const
{
	if (x >= _width) return NULL;
	if (y >= _height) return NULL;

	return _cells[y * _width + x];
}

Cell* Maze::getEntrance() const
{
	return _entrance;
}

Cell* Maze::getExit() const
{
	return _exit;
}

void Maze::reset()
{
	for (std::vector<Cell*>::iterator it = _cells.begin(); it != _cells.end(); ++it)
	{
		Cell* cell = *it;
		cell->setOpenNorth(false);
		cell->setOpenEast(false);
		cell->setOpenSouth(false);
		cell->setOpenWest(false);
	}
}

}}