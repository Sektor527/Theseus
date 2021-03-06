#include "GeneratorDepthFirst.h"
#include "../Maze.h"
#include "../Cell.h"
#include <stack>
#include <algorithm>
#include <time.h>

namespace Theseus { namespace Core {

void GeneratorDepthFirst::generate(Maze* maze, const ConfiguratorDepthFirst& configurator)
{
	GeneratorDepthFirst generator;
	generator._configurator = configurator;
	generator._maze = maze;

	srand((unsigned int)time(NULL));

	generator.visit(maze->getExit());
}

void GeneratorDepthFirst::visit(Cell* cell)
{
	std::stack<Cell*> running;
	
	_visitedCells.push_back(cell);
	running.push(cell);
	while (running.size() > 0)
	{
		Cell* current = running.top();

		std::vector<Cell*> neighbors;
		neighbors.push_back(_maze->getCellNeighbor(current,North));
		neighbors.push_back(_maze->getCellNeighbor(current,East));
		neighbors.push_back(_maze->getCellNeighbor(current,South));
		neighbors.push_back(_maze->getCellNeighbor(current,West));
		if (_configurator.RandomTraverse)
			shuffle(neighbors);

		bool finished = true;
		for (std::vector<Cell*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
		{
			Cell* neighbor = *it;

			if (neighbor == NULL) continue;
			if (std::find(_visitedCells.begin(), _visitedCells.end(), neighbor) != _visitedCells.end()) continue;

			finished = false;

			_maze->openPath(current, neighbor);
			running.push(neighbor);
			_visitedCells.push_back(neighbor);
			break;
		}

		if (finished)
			running.pop();
	}
}

void shuffle(std::vector<Cell*>& cells)
{
	size_t n = cells.size();
	while (n > 1)
	{
		n--;
		size_t k = rand() % (n+1);
		Cell* cell = cells[k];
		cells[k] = cells[n];
		cells[n] = cell;
	}
}

}}