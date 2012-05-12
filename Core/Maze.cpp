#include "Maze.h"
#include "Cell.h"

using namespace Theseus::Core;

Maze::Maze(size_t width, size_t height)
: _width(width), _height(height)
, _entrance(0), _exit(0)
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

			std::map<Direction, Cell*> neighbors;
			neighbors[North] = h > 0 ? getCell(w,h-1) : NULL;
			neighbors[East] =  w < _width - 1 ? getCell(w+1,h) : NULL;
			neighbors[South] = h < _height - 1 ? getCell(w,h+1) : NULL;
			neighbors[West] = w > 0 ? getCell(w-1,h) : NULL;

			_neighbors[cell] = neighbors;
		}
	}

	// Entrance and exit
	_entrance = getCell(0,0);
	_exit = getCell(getSizeWidth() - 1, getSizeHeight() - 1);
}

Maze::~Maze(void)
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

Cell* Maze::getCellNeighbor(Cell* cell, Direction direction) const
{
	return _neighbors.find(cell)->second.find(direction)->second;
}

void Maze::openPath(Cell* from, Direction dir)
{
	if (getCellNeighbor(from, dir) == NULL) return;

	from->openPath(dir);

	switch (dir)
	{
	case North:
		getCellNeighbor(from, dir)->openPath(South);
		break;
	case East:
		getCellNeighbor(from, dir)->openPath(West);
		break;
	case South:
		getCellNeighbor(from, dir)->openPath(North);
		break;
	case West:
		getCellNeighbor(from, dir)->openPath(East);
		break;
	}
}

void Maze::openPath(Cell* from, Cell* to)
{
	if (getCellNeighbor(from, North) == to) openPath(from, North);
	if (getCellNeighbor(from, East) == to) openPath(from, East);
	if (getCellNeighbor(from, South) == to) openPath(from, South);
	if (getCellNeighbor(from, West) == to) openPath(from, West);
}

bool Maze::isPathOpen(Cell* cell, Theseus::Core::Direction dir) const
{
	return cell->isPathOpen(dir);
}

bool Maze::isPathOpen(Cell* from, Cell* to) const
{
	if (getCellNeighbor(from, North) == to) return from->isPathOpen(North);
	if (getCellNeighbor(from, East) == to) return from->isPathOpen(East);
	if (getCellNeighbor(from, South) == to) return from->isPathOpen(South);
	if (getCellNeighbor(from, West) == to) return from->isPathOpen(West);

	return false;
}

size_t Maze::getPlotWidth() const
{
	return _width * 2 + 1;
}

size_t Maze::getPlotHeight() const
{
	return _height * 2 + 1;
}

Pixel Maze::getPlotPixel(size_t x, size_t y) const
{
	// Dead spaces
	if (x % 2 == 0 && y % 2 == 0)
		return Wall;

  // Rooms
	if (x % 2 != 0 && y % 2 != 0)
		return Space;

	// North border
	if (y == 0)
	{
		if (getCell((x - 1) / 2, 0) == getEntrance()) return Entrance;
		if (getCell((x - 1) / 2, 0) == getExit()) return Exit;
		return Wall;
	}

	// West border
	if (x == 0)
	{
		if (y != 1)
		{
			// Entrance or exit, but only if not also at North border
			if (getCell(0, (y - 1) / 2) == getEntrance()) return Entrance;
			if (getCell(0, (y - 1) / 2) == getExit()) return Exit;
		}
		return Wall;
	}

	// South border
	if (y == getPlotHeight() - 1)
	{
		if (getCell((x - 1) / 2, (y - 2) / 2) == getEntrance()) return Entrance;
		if (getCell((x - 1) / 2, (y - 2) / 2) == getExit()) return Exit;
		return Wall;
	}

	// East border
	if (x == getPlotWidth() - 1)
	{
		if (y != getPlotHeight() - 2)
		{
			// Entrance or exit, but only if not also at South border
			if (getCell((x - 2) / 2, (y - 1) / 2) == getEntrance()) return Entrance;
			if (getCell((x - 2) / 2, (y - 1) / 2) == getExit()) return Exit;
		}
		return Wall;
	}

	// North-south intersections
	if (x % 2 != 0)
		return getCell((x - 1) / 2, y / 2)->isPathOpen(North) ? Space : Wall;

	// East-west intersections
	if (y % 2 != 0)
		return getCell(x / 2, (y - 1) / 2)->isPathOpen(West) ? Space : Wall;

	return Void;
}