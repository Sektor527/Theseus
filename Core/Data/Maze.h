#pragma once
#include <vector>

namespace Theseus { namespace Core {

class Cell;

class Maze
{
public:
	Maze(size_t width, size_t height);
	~Maze();

	// Get dimensions
	size_t getSizeWidth() const;
	size_t getSizeHeight() const;

	// Get cells
	Cell* getCell(size_t x, size_t y) const;
	Cell* getEntrance() const;
	Cell* getExit() const;

	// Reset all paths to closed
	void reset();

private:
	size_t _width, _height;
	std::vector<Cell*> _cells;

	Cell* _entrance;
	Cell* _exit;
};

}}