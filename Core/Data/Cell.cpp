#include "Cell.h"
#include <cstdlib>

Cell::Cell()
: _north(NULL), _east(NULL), _south(NULL), _west(NULL)
, _openNorth(false), _openEast(false), _openSouth(false), _openWest(false)
{

}

void Cell::setNorth(Cell* cell) { _north = cell; }
void Cell::setEast(Cell* cell) { _east = cell; }
void Cell::setSouth(Cell* cell) { _south = cell; }
void Cell::setWest(Cell* cell) { _west = cell; }

Cell* Cell::getNorth() const { return _north; }
Cell* Cell::getEast() const { return _east; }
Cell* Cell::getSouth() const { return _south; }
Cell* Cell::getWest() const { return _west; }

std::vector<Cell*> Cell::getNeighbors() const
{ 
	std::vector<Cell*> result; 
	result.push_back(_north);
	result.push_back(_east);
	result.push_back(_south);
	result.push_back(_west);
	return result;
}

void Cell::setOpenNorth(bool open) { _openNorth = open; }
void Cell::setOpenEast(bool open) { _openEast = open; }
void Cell::setOpenSouth(bool open) { _openSouth = open; }
void Cell::setOpenWest(bool open) { _openWest = open; }

bool Cell::isOpenNorth() const { return _openNorth; }
bool Cell::isOpenEast() const { return _openEast; }
bool Cell::isOpenSouth() const { return _openSouth; }
bool Cell::isOpenWest() const { return _openWest; }

void Cell::createPath(Cell* from, Cell* to)
{
	if (from == NULL || to == NULL) return;

	if (from->getNorth() == to)
	{
		from->setOpenNorth(true);
		to->setOpenSouth(true);
	}

	if (from->getEast() == to)
	{
		from->setOpenEast(true);
		to->setOpenWest(true);
	}

	if (from->getSouth() == to)	
	{
		from->setOpenSouth(true);
		to->setOpenNorth(true);
	}

	if (from->getWest() == to)
	{
		from->setOpenWest(true);
		to->setOpenEast(true);
	}
}

void Cell::createPath(Cell* from, Direction direction)
{
	if (from == NULL) return;

	Cell* to = NULL;
	switch (direction)
	{
	case North:
		to = from->getNorth();
		break;

	case East:
		to = from->getEast();
		break;

	case South:
		to = from->getSouth();
		break;

	case West:
		to = from->getWest();
		break;
	}

	if (to == NULL) return;
		
	createPath(from, to);
}