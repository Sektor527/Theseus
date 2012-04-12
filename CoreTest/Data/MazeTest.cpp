#include "gtest/gtest.h"
#include "data/maze.h"
#include "data/cell.h"

TEST(MazeConstruction, CorrectSize)
{
	Maze* maze = new Maze(4,6);
	
	ASSERT_EQ(4, maze->getSizeWidth());
	ASSERT_EQ(6, maze->getSizeHeight());

	delete maze;
}

TEST(MazeConstruction, ZeroWidth)
{
	Maze* maze = new Maze(0, 6);

	ASSERT_EQ(1, maze->getSizeWidth());
	ASSERT_EQ(6, maze->getSizeHeight());

	delete maze;
}

TEST(MazeConstruction, ZeroHeight)
{
	Maze* maze = new Maze(4, 0);

	ASSERT_EQ(4, maze->getSizeWidth());
	ASSERT_EQ(1, maze->getSizeHeight());

	delete maze;
}

TEST(MazeConstruction, AllCells)
{
	Maze* maze = new Maze(4, 6);

	for (size_t h = 0; h < maze->getSizeHeight(); ++h)
	{
		for (size_t w = 0; w < maze->getSizeWidth(); ++w)
		{
			Cell* cell = maze->getCell(w,h);
			ASSERT_TRUE(cell != NULL);
		}
	}

	ASSERT_EQ(NULL, maze->getCell(-2, 3));
	ASSERT_EQ(NULL, maze->getCell(500, 3));
	ASSERT_EQ(NULL, maze->getCell(2, -2));
	ASSERT_EQ(NULL, maze->getCell(2, 500));

	delete maze;
}

TEST(MazeConstruction, InitialNeighbors)
{
	int width = 6;
	int height = 4;

	Maze* maze = new Maze(width, height);

	for (size_t h = 0; h < maze->getSizeHeight(); ++h)
	{
		for (size_t w = 0; w < maze->getSizeWidth(); ++w)
		{
			Cell* cell = maze->getCell(w,h);

			if (h == 0)
				ASSERT_EQ(NULL, cell->getNorth());
			else
				ASSERT_EQ(maze->getCell(w, h-1), cell->getNorth());

			if (h == height - 1)
				ASSERT_EQ(NULL, cell->getSouth());
			else
				ASSERT_EQ(maze->getCell(w, h+1), cell->getSouth());

			if (w == 0)
				ASSERT_EQ(NULL, cell->getWest());
			else
				ASSERT_EQ(maze->getCell(w-1, h), cell->getWest());

			if (w == width - 1)
				ASSERT_EQ(NULL, cell->getEast());
			else
				ASSERT_EQ(maze->getCell(w+1, h), cell->getEast());
		}
	}

	delete maze;
}

TEST(MazeConstruction, InitialWalls)
{
	Maze* maze = new Maze(4, 6);

	for (size_t h = 0; h < maze->getSizeHeight(); ++h)
	{
		for (size_t w = 0; w < maze->getSizeWidth(); ++w)
		{
			Cell* cell = maze->getCell(w, h);
			ASSERT_FALSE(cell->isOpenNorth());
			ASSERT_FALSE(cell->isOpenEast());
			ASSERT_FALSE(cell->isOpenSouth());
			ASSERT_FALSE(cell->isOpenWest());
		}
	}

	delete maze;
}

TEST(MazeConstruction, EntranceAndExit)
{
	Maze* maze = new Maze(4, 6);

	ASSERT_EQ(maze->getEntrance(), maze->getCell(0,0));
	ASSERT_EQ(maze->getExit(), maze->getCell(maze->getSizeWidth() - 1, maze->getSizeHeight() - 1));

	delete maze;
}