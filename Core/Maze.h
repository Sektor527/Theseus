#pragma once
#include <vector>
#include <map>
#include "Direction.h"
#include "Pixel.h"

namespace Theseus { namespace Core {

class Cell;

class Maze
{
public:
	Maze(size_t width, size_t height);
	virtual ~Maze();

	size_t getSizeWidth() const;
	size_t getSizeHeight() const;

	Cell* getCell(size_t x, size_t y) const;
	Cell* getEntrance() const;
	Cell* getExit() const;

	Cell* getCellNeighbor(Cell* from, Direction direction) const;

	void openPath(Cell* from, Direction dir);
	void openPath(Cell* from, Cell* to);
	bool isPathOpen(Cell* cell, Direction dir) const;
	bool isPathOpen(Cell* from, Cell* to) const;

	size_t getPlotWidth() const;
	size_t getPlotHeight() const;
	Pixel getPlotPixel(size_t x, size_t y) const;

private:
	size_t _width, _height;
	std::vector<Cell*> _cells;

	std::map<Cell*, std::map<Direction, Cell*>> _neighbors;

	Cell* _entrance;
	Cell* _exit;
};

}}