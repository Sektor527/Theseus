#include "gtest/gtest.h"

#include "Data/Maze.h"
#include "Data/Cell.h"
#include "Generators/GeneratorDepthFirst.h"

using namespace Theseus::Core;

TEST(GeneratorDepthFirst,ShuffleList)
{
	Cell* cell_1 = new Cell();
	Cell* cell_2 = new Cell();
	Cell* cell_3 = new Cell();
	Cell* cell_4 = new Cell();
	Cell* cell_5 = new Cell();

	std::vector<Cell*> list;

	list.push_back(cell_1);
	list.push_back(cell_2);
	list.push_back(cell_3);
	list.push_back(cell_4);
	list.push_back(cell_5);

	shuffle(list);

	// Same number of items
	ASSERT_EQ(5, list.size());
	
	// All items present
	bool found_1, found_2, found_3, found_4, found_5;
	for (std::vector<Cell*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		if (*it == cell_1) found_1 = true;
		if (*it == cell_2) found_2 = true;
		if (*it == cell_3) found_3 = true;
		if (*it == cell_4) found_4 = true;
		if (*it == cell_5) found_5 = true;
	}

	ASSERT_TRUE(found_1 && found_2 && found_3 && found_4 && found_5);

	// No item in same spot
	ASSERT_FALSE(cell_1 == list[0] && 
	             cell_2 == list[1] && 
							 cell_3 == list[2] && 
							 cell_4 == list[3] && 
	             cell_5 == list[4]);

	delete cell_1;
	delete cell_2;
	delete cell_3;
	delete cell_4;
	delete cell_5;
}

TEST(GeneratorDepthFirst,Generate)
{
	Maze* maze = new Maze(3, 3);

	ConfiguratorDepthFirst config;
	config.RandomTraverse = true;

	GeneratorDepthFirst::generate(maze, config);

	ASSERT_TRUE(maze->getCell(0, 0)->isOpenEast() || maze->getCell(0, 0)->isOpenSouth());
	ASSERT_TRUE(maze->getCell(1, 0)->isOpenWest() || maze->getCell(1, 0)->isOpenEast() || maze->getCell(1, 0)->isOpenSouth());
	ASSERT_TRUE(maze->getCell(2, 0)->isOpenWest() || maze->getCell(2, 0)->isOpenSouth());

	ASSERT_TRUE(maze->getCell(0, 1)->isOpenEast() || maze->getCell(0, 1)->isOpenNorth() || maze->getCell(0, 1)->isOpenSouth());
	ASSERT_TRUE(maze->getCell(1, 1)->isOpenWest() || maze->getCell(1, 1)->isOpenEast() || maze->getCell(1, 1)->isOpenNorth() || maze->getCell(1, 1)->isOpenSouth());
	ASSERT_TRUE(maze->getCell(2, 1)->isOpenWest() || maze->getCell(2, 1)->isOpenNorth() || maze->getCell(2, 1)->isOpenSouth());

	ASSERT_TRUE(maze->getCell(0, 2)->isOpenEast() || maze->getCell(0, 2)->isOpenNorth());
	ASSERT_TRUE(maze->getCell(1, 2)->isOpenWest() || maze->getCell(1, 2)->isOpenEast() || maze->getCell(1, 2)->isOpenNorth());
	ASSERT_TRUE(maze->getCell(2, 2)->isOpenWest() || maze->getCell(2, 2)->isOpenNorth());

	delete maze;
}