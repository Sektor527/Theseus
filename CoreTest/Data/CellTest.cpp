#include "gtest/gtest.h"
#include "data/Cell.h"

using namespace Theseus::Core;

TEST(CellDefaultValues, Neighbors)
{
	Cell* cell = new Cell();

	ASSERT_EQ(NULL, cell->getNorth());
	ASSERT_EQ(NULL, cell->getEast());
	ASSERT_EQ(NULL, cell->getSouth());
	ASSERT_EQ(NULL, cell->getWest());

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	delete cell;
}

TEST(CellNeighbors, CellSettersAndGetters)
{
	Cell* cell = new Cell();
	Cell* north = new Cell();
	Cell* east = new Cell();
	Cell* south = new Cell();
	Cell* west = new Cell();

	cell->setNorth(north);
	cell->setEast(east);
	cell->setSouth(south);
	cell->setWest(west);

	ASSERT_EQ(north, cell->getNorth());
	ASSERT_EQ(east, cell->getEast());
	ASSERT_EQ(south, cell->getSouth());
	ASSERT_EQ(west, cell->getWest());

	ASSERT_EQ(4, cell->getNeighbors().size());
	ASSERT_EQ(north, cell->getNeighbors()[0]);
	ASSERT_EQ(east, cell->getNeighbors()[1]);
	ASSERT_EQ(south, cell->getNeighbors()[2]);
	ASSERT_EQ(west, cell->getNeighbors()[3]);

	delete cell;
	delete north;
	delete east;
	delete south;
	delete west;
}

TEST(CellNeighbors, OpenSettersAndGetters)
{
	Cell* cell = new Cell();

	cell->setOpenNorth(true);
	cell->setOpenEast(true);
	cell->setOpenSouth(true);
	cell->setOpenWest(true);

	ASSERT_TRUE(cell->isOpenNorth());
	ASSERT_TRUE(cell->isOpenEast());
	ASSERT_TRUE(cell->isOpenSouth());
	ASSERT_TRUE(cell->isOpenWest());

	cell->setOpenNorth(false);
	cell->setOpenEast(false);
	cell->setOpenSouth(false);
	cell->setOpenWest(false);

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	delete cell;
}

TEST(CreatePathCellToCell,North)
{
	Cell* start = new Cell();
	Cell* north = new Cell();

	start->setNorth(north);
	north->setSouth(start);

	Cell::createPath(start, north);

	ASSERT_TRUE(start->isOpenNorth());
	ASSERT_TRUE(north->isOpenSouth());

	delete start;
	delete north;
}

TEST(CreatePathCellToCell,East)
{
	Cell* start = new Cell();
	Cell* east = new Cell();

	start->setEast(east);
	east->setWest(start);

	Cell::createPath(start, east);

	ASSERT_TRUE(start->isOpenEast());
	ASSERT_TRUE(east->isOpenWest());

	delete start;
	delete east;
}

TEST(CreatePathCellToCell,South)
{
	Cell* start = new Cell();
	Cell* south = new Cell();

	start->setSouth(south);
	south->setNorth(start);

	Cell::createPath(start, south);

	ASSERT_TRUE(start->isOpenSouth());
	ASSERT_TRUE(south->isOpenNorth());

	delete start;
	delete south;
}

TEST(CreatePathCellToCell,West)
{
	Cell* start = new Cell();
	Cell* west = new Cell();

	start->setWest(west);
	west->setEast(start);

	Cell::createPath(start, west);

	ASSERT_TRUE(start->isOpenWest());
	ASSERT_TRUE(west->isOpenEast());

	delete start;
	delete west;
}

TEST(CreatePathCellToCell, NonNeighboringCells)
{
	Cell* start = new Cell();
	Cell* end = new Cell();

	Cell::createPath(start, end);
	
	ASSERT_FALSE(start->isOpenNorth());
	ASSERT_FALSE(start->isOpenEast());
	ASSERT_FALSE(start->isOpenSouth());
	ASSERT_FALSE(start->isOpenWest());

	ASSERT_FALSE(end->isOpenNorth());
	ASSERT_FALSE(end->isOpenEast());
	ASSERT_FALSE(end->isOpenSouth());
	ASSERT_FALSE(end->isOpenWest());

	delete start;
	delete end;
}

TEST(CreatePathCellToCell, NullParameters)
{
	Cell* cell = new Cell();

	Cell::createPath(cell, NULL);

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	Cell::createPath(NULL, cell);

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	delete cell;
}

TEST(CreatePathCellToDirection, North)
{
	Cell* start = new Cell();
	Cell* north = new Cell();

	start->setNorth(north);
	north->setSouth(start);

	Cell::createPath(start, Cell::North);

	ASSERT_TRUE(start->isOpenNorth());
	ASSERT_TRUE(north->isOpenSouth());

	delete start;
	delete north;
}

TEST(CreatePathCellToDirection,East)
{
	Cell* start = new Cell();
	Cell* east = new Cell();

	start->setEast(east);
	east->setWest(start);

	Cell::createPath(start, Cell::East);

	ASSERT_TRUE(start->isOpenEast());
	ASSERT_TRUE(east->isOpenWest());

	delete start;
	delete east;
}

TEST(CreatePathCellToDirection,South)
{
	Cell* start = new Cell();
	Cell* south = new Cell();

	start->setSouth(south);
	south->setNorth(start);

	Cell::createPath(start, Cell::South);

	ASSERT_TRUE(start->isOpenSouth());
	ASSERT_TRUE(south->isOpenNorth());

	delete start;
	delete south;
}

TEST(CreatePathCellToDirection,West)
{
	Cell* start = new Cell();
	Cell* west = new Cell();

	start->setWest(west);
	west->setEast(start);

	Cell::createPath(start, Cell::West);

	ASSERT_TRUE(start->isOpenWest());
	ASSERT_TRUE(west->isOpenEast());

	delete start;
	delete west;
}

TEST(CreatePathCellToDirection, NoNeighborCell)
{
	Cell* cell = new Cell();

	Cell::createPath(cell, Cell::North);
	Cell::createPath(cell, Cell::East);
	Cell::createPath(cell, Cell::South);
	Cell::createPath(cell, Cell::West);

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	delete cell;
}

TEST(CreatePathCellToDirection, NullParameters)
{
	Cell* cell = new Cell();

	Cell::createPath(NULL, Cell::North);
	Cell::createPath(NULL, Cell::East);
	Cell::createPath(NULL, Cell::South);
	Cell::createPath(NULL, Cell::West);

	ASSERT_FALSE(cell->isOpenNorth());
	ASSERT_FALSE(cell->isOpenEast());
	ASSERT_FALSE(cell->isOpenSouth());
	ASSERT_FALSE(cell->isOpenWest());

	delete cell;
}