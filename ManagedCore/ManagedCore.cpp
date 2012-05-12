// This is the main DLL file.

#include "stdafx.h"

#include "ManagedCore.h"
#include "Maze.h"
#include "Cell.h"
#include "Generators/GeneratorDepthFirst.h"

namespace Theseus { namespace ManagedCore {

	//////////////////////////////////////////////////////////////////////////
	// Cell
	Cell::Cell(Core::Cell* cell)
	{
		_cell = cell;
	}

	Cell::~Cell()
	{
		delete _cell;
	}

	Core::Cell* Cell::getCell()
	{
		return _cell;
	}

	//////////////////////////////////////////////////////////////////////////
	// Maze
	Maze::Maze(unsigned int width, unsigned int height)
	{
		_maze = new Core::Maze(width, height);
	}

	Maze::~Maze()
	{
		delete _maze;
	}

	Cell^ Maze::getEntrance()
	{
		return gcnew Cell(_maze->getEntrance());
	}

	Cell^ Maze::getExit()
	{
		return gcnew Cell(_maze->getExit());
	}

	unsigned int Maze::getPlotWidth()
	{
		return _maze->getPlotWidth();
	}

	unsigned int Maze::getPlotHeight()
	{
		return _maze->getPlotHeight();
	}

	Maze::Pixels Maze::getPlotPixel(unsigned int x, unsigned int y)
	{
		return (Pixels)_maze->getPlotPixel(x, y);
	}

	Core::Maze* Maze::getMaze()
	{
		return _maze;
	}

	//////////////////////////////////////////////////////////////////////////
	// GeneratorDepthFirst
	ConfiguratorDepthFirst::ConfiguratorDepthFirst()
	{
		_configurator = new Core::ConfiguratorDepthFirst();
	}

	bool ConfiguratorDepthFirst::RandomTraverse::get()
	{
		return _configurator->RandomTraverse;
	}

	void ConfiguratorDepthFirst::RandomTraverse::set(bool value)
	{
		_configurator->RandomTraverse = value;
	}

	Core::ConfiguratorDepthFirst* ConfiguratorDepthFirst::getConfigurator()
	{
		return _configurator;
	}

	void GeneratorDepthFirst::generate(Maze^ maze, ConfiguratorDepthFirst^ configurator)
	{
		Core::GeneratorDepthFirst::generate(maze->getMaze(), *configurator->getConfigurator());
	}
}}