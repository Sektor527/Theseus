// This is the main DLL file.

#include "stdafx.h"

#include "ManagedCore.h"
#include "Data/Maze.h"
#include "Data/Cell.h"
#include "Plotter/Plotter.h"
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

	//////////////////////////////////////////////////////////////////////////
	// Plotter
	Plotter^ Plotter::plot(Maze^ maze)
	{
		Core::Plotter* plotter = Core::Plotter::plot(maze->getMaze());

		Plotter^ wrapper = gcnew Plotter(plotter);
		return wrapper;
	}

	Plotter::Plotter(Core::Plotter* plotter)
	{
		_plotter = plotter;
	}

	Plotter::~Plotter()
	{
		delete _plotter;
	}

	unsigned int Plotter::getSizeWidth()
	{
		return _plotter->getSizeWidth();
	}

	unsigned int Plotter::getSizeHeight()
	{
		return _plotter->getSizeHeight();
	}

	Plotter::Pixels Plotter::getPixel(unsigned int x, unsigned int y)
	{
		return (Plotter::Pixels)_plotter->getPixel(x, y);
	}
}}