#pragma once
#include "Direction.h"

namespace Theseus { namespace Core {

class Cell
{
public:
	Cell();
	virtual ~Cell();

	void openPath(Direction dir);
	bool isPathOpen(Direction dir) const;

private:
	bool _openPaths[4];
};

}}