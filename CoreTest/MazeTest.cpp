#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "maze.h"

using namespace Theseus::Core;
using ::testing::_;
using ::testing::ReturnNew;

class MazeTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		maze = new Maze(20, 10);
	}

	virtual void TearDown()
	{
		delete maze;
	}

	Maze* maze;
};

TEST_F(MazeTest, Initialize)
{
	// Maze size
	EXPECT_EQ(20, maze->getSizeWidth());
	EXPECT_EQ(10, maze->getSizeHeight());

	// Cells
	for (size_t y = 0; y < maze->getSizeHeight(); ++y)
	{
		for (size_t x = 0; x < maze->getSizeWidth(); ++x)
		{
			EXPECT_NE(static_cast<Cell*>(0), maze->getCell(x,y));
			EXPECT_FALSE(maze->isPathOpen(maze->getCell(x,y),North));
			EXPECT_FALSE(maze->isPathOpen(maze->getCell(x,y),East));
			EXPECT_FALSE(maze->isPathOpen(maze->getCell(x,y),South));
			EXPECT_FALSE(maze->isPathOpen(maze->getCell(x,y),West));
		}
	}

	// Entrance and exit
	EXPECT_EQ(maze->getEntrance(), maze->getCell(0,0));
	EXPECT_EQ(maze->getExit(), maze->getCell(maze->getSizeWidth() - 1, maze->getSizeHeight() -1));
}

TEST_F(MazeTest, InitializeIncorrectSize)
{
	Maze* zeroWidth = new Maze(0, 10);
	EXPECT_EQ(1, zeroWidth->getSizeWidth());
	EXPECT_EQ(10, zeroWidth->getSizeHeight());

	Maze* zeroHeight = new Maze(10, 0);
	EXPECT_EQ(10, zeroHeight->getSizeWidth());
	EXPECT_EQ(1, zeroHeight->getSizeHeight());

	delete zeroWidth;
	delete zeroHeight;
}

TEST_F(MazeTest, Neighbors)
{
	Cell* from = maze->getCell(2,2);

	EXPECT_EQ(maze->getCellNeighbor(from, North), maze->getCell(2, 1));
	EXPECT_EQ(maze->getCellNeighbor(from, East), maze->getCell(3,2));
	EXPECT_EQ(maze->getCellNeighbor(from, South), maze->getCell(2,3));
	EXPECT_EQ(maze->getCellNeighbor(from, West), maze->getCell(1, 2));
}

TEST_F(MazeTest, OpenPaths)
{
	Cell* from = maze->getCell(2,2);
	Cell* toNorth = maze->getCellNeighbor(from, North);
	Cell* toEast = maze->getCellNeighbor(from, East);
	Cell* toSouth = maze->getCellNeighbor(from, South);
	Cell* toWest = maze->getCellNeighbor(from, West);

	ASSERT_FALSE(maze->isPathOpen(from, North));
	maze->openPath(from, toNorth);
	EXPECT_TRUE(maze->isPathOpen(from, North));
	EXPECT_TRUE(maze->isPathOpen(toNorth, South));

	ASSERT_FALSE(maze->isPathOpen(from, East));
	maze->openPath(from, toEast);
	EXPECT_TRUE(maze->isPathOpen(from, East));
	EXPECT_TRUE(maze->isPathOpen(toEast, West));

	ASSERT_FALSE(maze->isPathOpen(from, South));
	maze->openPath(from, toSouth);
	EXPECT_TRUE(maze->isPathOpen(from, South));
	EXPECT_TRUE(maze->isPathOpen(toSouth, North));

	ASSERT_FALSE(maze->isPathOpen(from, West));
	maze->openPath(from, toWest);
	EXPECT_TRUE(maze->isPathOpen(from, West));
	EXPECT_TRUE(maze->isPathOpen(toWest, East));
}

TEST_F(MazeTest, OpenPathsToVoid)
{
	size_t top = 0;
	size_t left = 0;
	size_t right = maze->getSizeWidth() - 1;
	size_t bottom = maze->getSizeHeight() - 1;

	// North border
	maze->openPath(maze->getCell(5, top), North);
	EXPECT_FALSE(maze->isPathOpen(maze->getCell(5, top), North));

	// South border
	maze->openPath(maze->getCell(5, bottom), South);
	EXPECT_FALSE(maze->isPathOpen(maze->getCell(5, bottom), South));

	// East border
	maze->openPath(maze->getCell(right, 5), East);
	EXPECT_FALSE(maze->isPathOpen(maze->getCell(right, 5), East));

	// West border
	maze->openPath(maze->getCell(left, 5), West);
	EXPECT_FALSE(maze->isPathOpen(maze->getCell(left, 5), West));
}

TEST_F(MazeTest, PlotSize)
{
	EXPECT_EQ(20 * 2 + 1, maze->getPlotWidth());
	EXPECT_EQ(10 * 2 + 1, maze->getPlotHeight());
}

TEST_F(MazeTest, InitialPixels)
{
	size_t numSpaces = 0;
	size_t numEntrances = 0;
	size_t numExits = 0;

	for (size_t y = 0; y < maze->getPlotHeight(); ++y)
	{
		for (size_t x = 0; x < maze->getPlotWidth(); ++x)
		{
			Pixel p = maze->getPlotPixel(x, y);
			EXPECT_GE(p, Space);
			EXPECT_LE(p, Void);

			switch (p)
			{
			case Space:
				numSpaces++;
				break;
			case Entrance:
				numEntrances++;
				break;
			case Exit:
				numExits++;
				break;
			}
		}
	}

	EXPECT_EQ(maze->getSizeWidth() * maze->getSizeHeight(), numSpaces);
	EXPECT_EQ(1, numExits);
	EXPECT_EQ(1, numEntrances);
}