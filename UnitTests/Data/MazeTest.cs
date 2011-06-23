using System;
using NUnit.Framework;
using Theseus.Data;

namespace UnitTests.Data
{
	[TestFixture]
	class MazeTest
	{
		[Test]
		public void CreateEmptyMaze()
		{
			var maze = new Maze(5, 5);

			for (int x = 0; x < 5; ++x)
			{
				for (int y = 0; y < 5; ++y)
				{
					var cell = maze.Cell(x, y);
					Assert.IsNull(cell.North);
					Assert.IsNull(cell.East);
					Assert.IsNull(cell.South);
					Assert.IsNull(cell.West);
				}
			}
		}

		[Test, ExpectedException(typeof(ArgumentOutOfRangeException))]
		public void CreateMazeWithZeroDimensions()
		{
			var maze = new Maze(0, 0);
		}

		[Test, ExpectedException(typeof(ArgumentOutOfRangeException))]
		public void CreateMazeWithZeroXDimension()
		{
			var maze = new Maze(0, 5);
		}

		[Test, ExpectedException(typeof(ArgumentOutOfRangeException))]
		public void CreateMazeWithZeroYDimension()
		{
			var maze = new Maze(5, 0);
		}

		[Test, ExpectedException(typeof(ArgumentOutOfRangeException))]
		public void CreateMazeWithNegativeDimensions()
		{
			var maze = new Maze(-5, -5);
		}
	}
}
