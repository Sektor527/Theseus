// ManagedCore.h

#pragma once

using namespace System;

namespace Theseus { 
	namespace Core {
		class Maze;
		class Cell;
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
		enum class Pixels
		{
			Space = 0,
			Wall,
			Entrance,
			Exit,

			Void = 255
		};

	public:
		Maze(unsigned int width, unsigned int height);
		~Maze();

		Cell^ getEntrance();
		Cell^ getExit();

		unsigned int getPlotWidth();
		unsigned int getPlotHeight();
		Pixels getPlotPixel(unsigned int x, unsigned int y);

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
}}