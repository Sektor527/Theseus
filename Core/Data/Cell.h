#pragma once
#include <vector>

class Cell
{
public:
	Cell();
	~Cell();

	// Directions
	enum Direction
	{
		North, East, South, West
	};

	// Neighbor getters and setters
	void setNorth(Cell* cell);
	void setEast(Cell* cell);
	void setSouth(Cell* cell);
	void setWest(Cell* cell);

	Cell* getNorth() const;
	Cell* getEast() const;
	Cell* getSouth() const;
	Cell* getWest() const;

	std::vector<Cell*> getNeighbors() const;

	// Neighbor open getters and setters
	void setOpenNorth(bool open);
	void setOpenEast(bool open);
	void setOpenSouth(bool open);
	void setOpenWest(bool open);

	bool isOpenNorth() const;
	bool isOpenEast() const;
	bool isOpenSouth() const;
	bool isOpenWest() const;

	// Open a path between two cells
	static void createPath(Cell* from, Cell* to);

	// Open a path from a cell to a direction
	static void createPath(Cell* from, Direction direction);

private:
	Cell* _north;
	Cell* _east;
	Cell* _south;
	Cell* _west;

	bool _openNorth;
	bool _openEast;
	bool _openSouth;
	bool _openWest;
};