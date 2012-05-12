#include "Cell.h"

using namespace Theseus::Core;

Cell::Cell(void)
{
	for (size_t i = 0; i < 4; ++i)
		_openPaths[i] = false;
}

Cell::~Cell(void)
{
}

void Cell::openPath(Direction dir)
{
	_openPaths[dir] = true;
}

bool Cell::isPathOpen(Direction dir) const
{
	return _openPaths[dir];
}