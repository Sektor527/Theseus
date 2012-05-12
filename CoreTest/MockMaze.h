#pragma once
#include "gmock/gmock.h"
#include "maze.h"

using namespace Theseus::Core;

class MockMaze : public Maze
{
public:
	MockMaze(size_t width, size_t height) : Maze(width, height) {}

	MOCK_METHOD3(openPath,void(size_t,size_t,Direction));
};