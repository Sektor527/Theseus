#include "gtest/gtest.h"
#include "data/Cell.h"

using namespace Theseus::Core;

class CellTest : public ::testing::Test {
};

TEST_F(CellTest, DefaultNeighbors)
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

TEST_F(CellTest, NeighborSettersAndGetters)
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

TEST_F(CellTest, NeighborOpenSettersAndGetters)
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

class CellPathTest : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		from = new Cell();
		to = new Cell();
	}

	virtual void TearDown()
	{
		delete from;
		delete to;
	}

	Cell* from;
	Cell* to;
};

TEST_F(CellPathTest, PathToNorthCell)
{
	from->setNorth(to);
	to->setSouth(from);

	Cell::createPath(from, to);

	ASSERT_TRUE(from->isOpenNorth());
	ASSERT_TRUE(to->isOpenSouth());
}

TEST_F(CellPathTest, PathToEastCell)
{
	from->setEast(to);
	to->setWest(from);

	Cell::createPath(from, to);

	ASSERT_TRUE(from->isOpenEast());
	ASSERT_TRUE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToSouthCell)
{
	from->setSouth(to);
	to->setNorth(from);

	Cell::createPath(from, to);

	ASSERT_TRUE(from->isOpenSouth());
	ASSERT_TRUE(to->isOpenNorth());
}

TEST_F(CellPathTest, PathToWestCell)
{
	from->setWest(to);
	to->setEast(from);

	Cell::createPath(from, to);

	ASSERT_TRUE(from->isOpenWest());
	ASSERT_TRUE(to->isOpenEast());
}

TEST_F(CellPathTest, NonNeighboringCells)
{
	Cell::createPath(from, to);
	
	ASSERT_FALSE(from->isOpenNorth());
	ASSERT_FALSE(from->isOpenEast());
	ASSERT_FALSE(from->isOpenSouth());
	ASSERT_FALSE(from->isOpenWest());

	ASSERT_FALSE(to->isOpenNorth());
	ASSERT_FALSE(to->isOpenEast());
	ASSERT_FALSE(to->isOpenSouth());
	ASSERT_FALSE(to->isOpenWest());
}

TEST_F(CellPathTest, NullParametersCells)
{
	Cell::createPath(from, NULL);

	ASSERT_FALSE(from->isOpenNorth());
	ASSERT_FALSE(from->isOpenEast());
	ASSERT_FALSE(from->isOpenSouth());
	ASSERT_FALSE(from->isOpenWest());

	Cell::createPath(NULL, to);

	ASSERT_FALSE(to->isOpenNorth());
	ASSERT_FALSE(to->isOpenEast());
	ASSERT_FALSE(to->isOpenSouth());
	ASSERT_FALSE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToNorthDirection)
{
	from->setNorth(to);
	to->setSouth(from);

	Cell::createPath(from, Cell::North);

	ASSERT_TRUE(from->isOpenNorth());
	ASSERT_TRUE(to->isOpenSouth());
}

TEST_F(CellPathTest, PathToEastDirection)
{
	from->setEast(to);
	to->setWest(from);

	Cell::createPath(from, Cell::East);

	ASSERT_TRUE(from->isOpenEast());
	ASSERT_TRUE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToSouthDirection)
{
	from->setSouth(to);
	to->setNorth(from);

	Cell::createPath(from, Cell::South);

	ASSERT_TRUE(from->isOpenSouth());
	ASSERT_TRUE(to->isOpenNorth());
}

TEST_F(CellPathTest, PathToWestDirection)
{
	from->setWest(to);
	to->setEast(from);

	Cell::createPath(from, Cell::West);

	ASSERT_TRUE(from->isOpenWest());
	ASSERT_TRUE(to->isOpenEast());
}

TEST_F(CellPathTest, NoNeighborCell)
{
	Cell::createPath(from, Cell::North);
	Cell::createPath(from, Cell::East);
	Cell::createPath(from, Cell::South);
	Cell::createPath(from, Cell::West);

	ASSERT_FALSE(from->isOpenNorth());
	ASSERT_FALSE(from->isOpenEast());
	ASSERT_FALSE(from->isOpenSouth());
	ASSERT_FALSE(from->isOpenWest());
}

TEST_F(CellPathTest, NullParametersDirection)
{
	Cell::createPath(NULL, Cell::North);
	Cell::createPath(NULL, Cell::East);
	Cell::createPath(NULL, Cell::South);
	Cell::createPath(NULL, Cell::West);

	ASSERT_FALSE(from->isOpenNorth());
	ASSERT_FALSE(from->isOpenEast());
	ASSERT_FALSE(from->isOpenSouth());
	ASSERT_FALSE(from->isOpenWest());
}