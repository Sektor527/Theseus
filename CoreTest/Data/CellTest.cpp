#include "gtest/gtest.h"
#include "data/Cell.h"

using namespace Theseus::Core;

class CellTest : public ::testing::Test {
};

TEST_F(CellTest, DefaultNeighbors)
{
	Cell* cell = new Cell();

	EXPECT_EQ(NULL, cell->getNorth());
	EXPECT_EQ(NULL, cell->getEast());
	EXPECT_EQ(NULL, cell->getSouth());
	EXPECT_EQ(NULL, cell->getWest());

	EXPECT_FALSE(cell->isOpenNorth());
	EXPECT_FALSE(cell->isOpenEast());
	EXPECT_FALSE(cell->isOpenSouth());
	EXPECT_FALSE(cell->isOpenWest());

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

	EXPECT_EQ(north, cell->getNorth());
	EXPECT_EQ(east, cell->getEast());
	EXPECT_EQ(south, cell->getSouth());
	EXPECT_EQ(west, cell->getWest());

	EXPECT_EQ(4, cell->getNeighbors().size());
	EXPECT_EQ(north, cell->getNeighbors()[0]);
	EXPECT_EQ(east, cell->getNeighbors()[1]);
	EXPECT_EQ(south, cell->getNeighbors()[2]);
	EXPECT_EQ(west, cell->getNeighbors()[3]);

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

	EXPECT_TRUE(cell->isOpenNorth());
	EXPECT_TRUE(cell->isOpenEast());
	EXPECT_TRUE(cell->isOpenSouth());
	EXPECT_TRUE(cell->isOpenWest());

	cell->setOpenNorth(false);
	cell->setOpenEast(false);
	cell->setOpenSouth(false);
	cell->setOpenWest(false);

	EXPECT_FALSE(cell->isOpenNorth());
	EXPECT_FALSE(cell->isOpenEast());
	EXPECT_FALSE(cell->isOpenSouth());
	EXPECT_FALSE(cell->isOpenWest());

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

	EXPECT_TRUE(from->isOpenNorth());
	EXPECT_TRUE(to->isOpenSouth());
}

TEST_F(CellPathTest, PathToEastCell)
{
	from->setEast(to);
	to->setWest(from);

	Cell::createPath(from, to);

	EXPECT_TRUE(from->isOpenEast());
	EXPECT_TRUE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToSouthCell)
{
	from->setSouth(to);
	to->setNorth(from);

	Cell::createPath(from, to);

	EXPECT_TRUE(from->isOpenSouth());
	EXPECT_TRUE(to->isOpenNorth());
}

TEST_F(CellPathTest, PathToWestCell)
{
	from->setWest(to);
	to->setEast(from);

	Cell::createPath(from, to);

	EXPECT_TRUE(from->isOpenWest());
	EXPECT_TRUE(to->isOpenEast());
}

TEST_F(CellPathTest, NonNeighboringCells)
{
	Cell::createPath(from, to);
	
	EXPECT_FALSE(from->isOpenNorth());
	EXPECT_FALSE(from->isOpenEast());
	EXPECT_FALSE(from->isOpenSouth());
	EXPECT_FALSE(from->isOpenWest());

	EXPECT_FALSE(to->isOpenNorth());
	EXPECT_FALSE(to->isOpenEast());
	EXPECT_FALSE(to->isOpenSouth());
	EXPECT_FALSE(to->isOpenWest());
}

TEST_F(CellPathTest, NullParametersCells)
{
	Cell::createPath(from, NULL);

	EXPECT_FALSE(from->isOpenNorth());
	EXPECT_FALSE(from->isOpenEast());
	EXPECT_FALSE(from->isOpenSouth());
	EXPECT_FALSE(from->isOpenWest());

	Cell::createPath(NULL, to);

	EXPECT_FALSE(to->isOpenNorth());
	EXPECT_FALSE(to->isOpenEast());
	EXPECT_FALSE(to->isOpenSouth());
	EXPECT_FALSE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToNorthDirection)
{
	from->setNorth(to);
	to->setSouth(from);

	Cell::createPath(from, Cell::North);

	EXPECT_TRUE(from->isOpenNorth());
	EXPECT_TRUE(to->isOpenSouth());
}

TEST_F(CellPathTest, PathToEastDirection)
{
	from->setEast(to);
	to->setWest(from);

	Cell::createPath(from, Cell::East);

	EXPECT_TRUE(from->isOpenEast());
	EXPECT_TRUE(to->isOpenWest());
}

TEST_F(CellPathTest, PathToSouthDirection)
{
	from->setSouth(to);
	to->setNorth(from);

	Cell::createPath(from, Cell::South);

	EXPECT_TRUE(from->isOpenSouth());
	EXPECT_TRUE(to->isOpenNorth());
}

TEST_F(CellPathTest, PathToWestDirection)
{
	from->setWest(to);
	to->setEast(from);

	Cell::createPath(from, Cell::West);

	EXPECT_TRUE(from->isOpenWest());
	EXPECT_TRUE(to->isOpenEast());
}

TEST_F(CellPathTest, NoNeighborCell)
{
	Cell::createPath(from, Cell::North);
	Cell::createPath(from, Cell::East);
	Cell::createPath(from, Cell::South);
	Cell::createPath(from, Cell::West);

	EXPECT_FALSE(from->isOpenNorth());
	EXPECT_FALSE(from->isOpenEast());
	EXPECT_FALSE(from->isOpenSouth());
	EXPECT_FALSE(from->isOpenWest());
}

TEST_F(CellPathTest, NullParametersDirection)
{
	Cell::createPath(NULL, Cell::North);
	Cell::createPath(NULL, Cell::East);
	Cell::createPath(NULL, Cell::South);
	Cell::createPath(NULL, Cell::West);

	EXPECT_FALSE(from->isOpenNorth());
	EXPECT_FALSE(from->isOpenEast());
	EXPECT_FALSE(from->isOpenSouth());
	EXPECT_FALSE(from->isOpenWest());
}