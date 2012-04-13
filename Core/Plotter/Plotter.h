#pragma once

namespace Theseus { namespace Core {

class Maze;

class Plotter
{
public:
	enum Pixels
	{
		Space = 0,
		Wall,
		Entrance,
		Exit,

		Void = 255
	};

	static Plotter* plot(Maze* maze);
	~Plotter();

	size_t getSizeWidth() const;
	size_t getSizeHeight() const;
	char getPixel(size_t x, size_t y) const;

private:
	Plotter() {};

private:
	size_t _width, _height;
	char** _plot;
};

}}