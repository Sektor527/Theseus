#include "gtest/gtest.h"

#include "Data/Maze.h"
#include "Plotter/Plotter.h"

using namespace Theseus::Core;

TEST(Plotter,CorrectSizes)
{
	Maze* maze = new Maze(4,6);
	Plotter* plot = Plotter::plot(maze);

	ASSERT_EQ(9, plot->getSizeWidth());
	ASSERT_EQ(13, plot->getSizeHeight());

	delete maze;
	delete plot;
}

TEST(Plotter,ContainsBasicElements)
{
	Maze* maze = new Maze(2,2);
	Plotter* plot = Plotter::plot(maze);

	size_t foundSpace = 0;
	size_t foundWall = 0;
	size_t foundEntrance = 0;
	size_t foundExit = 0;
	size_t foundOther = 0;

	for (size_t h = 0; h < plot->getSizeHeight(); ++h)
	{
		for (size_t w = 0; w < plot->getSizeWidth(); ++w)
		{
			switch (plot->getPixel(w, h))
			{
			case Plotter::Space:
				foundSpace++;
				break;
			case Plotter::Wall:
				foundWall++;
				break;
			case Plotter::Entrance:
				foundEntrance++;
				break;
			case Plotter::Exit:
				foundExit++;
				break;
			default:
				foundOther++;
				break;
			}
		}
	}

	ASSERT_GT(foundSpace, 0);
	ASSERT_GT(foundWall, 0);

	ASSERT_EQ(foundEntrance, 1);
	ASSERT_EQ(foundExit, 1);

	ASSERT_EQ(foundOther, 0);

	delete maze;
	delete plot;
}

TEST(Plotter,MazeBorders)
{
	Maze* maze = new Maze(3, 3);
	Plotter* plot = Plotter::plot(maze);

	// Top border
	for (size_t x = 0; x < plot->getSizeWidth(); ++x)
	{
		if (x == 1)
			ASSERT_EQ(Plotter::Entrance, plot->getPixel(x, 0));
		else
			ASSERT_EQ(Plotter::Wall, plot->getPixel(x, 0));
	}

	// Bottom border
	for (size_t x = 0; x < plot->getSizeWidth(); ++x)
	{
		if (x == plot->getSizeWidth() - 2)
			ASSERT_EQ(Plotter::Exit, plot->getPixel(x, plot->getSizeHeight()-1));
		else
			ASSERT_EQ(Plotter::Wall, plot->getPixel(x, plot->getSizeHeight()-1));
	}

	// Left border
	for (size_t y = 0; y < plot->getSizeHeight(); ++y)
		ASSERT_EQ(Plotter::Wall, plot->getPixel(0, y));

	// Right border
	for (size_t y = 0; y < plot->getSizeHeight(); ++y)
		ASSERT_EQ(Plotter::Wall, plot->getPixel(plot->getSizeWidth()-1, y));

	delete maze;
	delete plot;
}

TEST(Plotter,EntranceAndExitPlacement)
{
	Maze* maze = new Maze(3, 3);
	Plotter* plot = Plotter::plot(maze);

	ASSERT_EQ(Plotter::Entrance, plot->getPixel(1, 0));
	ASSERT_EQ(Plotter::Exit, plot->getPixel(plot->getSizeWidth()-2,plot->getSizeHeight()-1));

	delete maze;
	delete plot;
}