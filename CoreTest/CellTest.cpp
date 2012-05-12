#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cell.h"

using namespace Theseus::Core;

class CellTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		cell = new Cell();
	}

	virtual void TearDown()
	{
		delete cell;
	}

	Cell* cell;
};

TEST_F(CellTest, Initialize)
{
	EXPECT_FALSE(cell->isPathOpen(North));
	EXPECT_FALSE(cell->isPathOpen(East));
	EXPECT_FALSE(cell->isPathOpen(South));
	EXPECT_FALSE(cell->isPathOpen(West));
}

TEST_F(CellTest, OpenPaths)
{
	ASSERT_FALSE(cell->isPathOpen(North));
	cell->openPath(North);
	EXPECT_TRUE(cell->isPathOpen(North));

	ASSERT_FALSE(cell->isPathOpen(East));
	cell->openPath(East);
	EXPECT_TRUE(cell->isPathOpen(East));

	ASSERT_FALSE(cell->isPathOpen(South));
	cell->openPath(South);
	EXPECT_TRUE(cell->isPathOpen(South));

	ASSERT_FALSE(cell->isPathOpen(West));
	cell->openPath(West);
	EXPECT_TRUE(cell->isPathOpen(West));
}