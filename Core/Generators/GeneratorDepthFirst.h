#pragma once
#include <vector>

namespace Theseus { namespace Core {

class Maze;
class Cell;

struct ConfiguratorDepthFirst
{
	bool RandomTraverse;
};

class GeneratorDepthFirst
{
public:
	static void generate(Maze* maze, const ConfiguratorDepthFirst& configurator);
	~GeneratorDepthFirst() {};

private:
	GeneratorDepthFirst() {};
	void visit(Cell* cell);

private:
	Maze* _maze;
	ConfiguratorDepthFirst _configurator;

	std::vector<Cell*> _visitedCells;
};

void shuffle(std::vector<Cell*>& cells);

}}