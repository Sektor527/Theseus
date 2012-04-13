// ManagedCore.h

#pragma once

using namespace System;

namespace Theseus { 
	namespace Core {
		class Maze;
		class Cell;
		class Plotter;
		struct ConfiguratorDepthFirst;
	}	

namespace ManagedCore {

	public ref class Cell
	{
	public:
		Cell(Core::Cell* cell);
		~Cell();

	internal:
		Core::Cell* getCell();

	private:
		Core::Cell* _cell;
	};

	public ref class Maze
	{
	public:
		Maze(unsigned int width, unsigned int height);
		~Maze();

		Cell^ getEntrance();
		Cell^ getExit();

	internal:
		Core::Maze* getMaze();

	private:
		Core::Maze* _maze;
	};

	public ref class ConfiguratorDepthFirst
	{
	public:
		ConfiguratorDepthFirst();

		property bool RandomTraverse
		{
			bool get();
			void set(bool value);
		}

	internal:
		Core::ConfiguratorDepthFirst* getConfigurator();

	private:
		Core::ConfiguratorDepthFirst* _configurator;
	};

	public ref class GeneratorDepthFirst
	{
	public:
		static void generate(Maze^ maze, ConfiguratorDepthFirst^ configurator);
	};

	public ref class Plotter
	{
	public:
		enum class Pixels
		{
			Space = 0,
			Wall,
			Entrance,
			Exit,

			Void = 255
		};

	public:
		static Plotter^ plot(Maze^ maze);
		~Plotter();

		unsigned int getSizeWidth();
		unsigned int getSizeHeight();
		Pixels getPixel(unsigned int x, unsigned int y);

	private:
		Plotter(Core::Plotter* plotter);
		Core::Plotter* _plotter;
	};
}}