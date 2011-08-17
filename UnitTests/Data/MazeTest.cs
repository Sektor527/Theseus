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
			var maze = new Maze(4, 6);

			Assert.AreEqual(4, maze.Size.X);
			Assert.AreEqual(6, maze.Size.Y);

			Assert.AreEqual(4*6, maze.Cells.Count);
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

		[Test]
		public void CellNeighbors()
		{
			Maze maze = new Maze(3, 3);

			foreach (Cell cell in maze.Cells)
			{
				Assert.Contains(cell.North, cell.Neighbors);
				Assert.Contains(cell.East, cell.Neighbors);
				Assert.Contains(cell.South, cell.Neighbors);
				Assert.Contains(cell.West, cell.Neighbors);

				Location loc = maze.Location(cell);

				if (loc.X == 0)
					Assert.IsNull(cell.West);
				else
					Assert.AreEqual(maze.Cell(loc.X - 1, loc.Y), cell.West);

				if (loc.X == maze.Size.X - 1)
					Assert.IsNull(cell.East);
				else
					Assert.AreEqual(maze.Cell(loc.X + 1, loc.Y), cell.East);

				if (loc.Y == 0)
					Assert.IsNull(cell.North);
				else
					Assert.AreEqual(maze.Cell(loc.X, loc.Y - 1), cell.North);

				if (loc.Y == maze.Size.Y - 1)
					Assert.IsNull(cell.South);
				else
					Assert.AreEqual(maze.Cell(loc.X, loc.Y + 1), cell.South);
			}
		}

		[Test]
		public void InitialWalls()
		{
			Maze maze = new Maze(3, 3);

			foreach (Cell cell in maze.Cells)
			{
				Assert.IsFalse(cell.IsPath(Cell.Direction.North));
				Assert.IsFalse(cell.IsPath(Cell.Direction.East));
				Assert.IsFalse(cell.IsPath(Cell.Direction.South));
				Assert.IsFalse(cell.IsPath(Cell.Direction.West));
			}
		}

		[Test]
		public void CreatePathUsingCell()
		{
			Maze maze = new Maze(3,3);

			Cell from = maze.Cell(1, 1);
			Cell to = maze.Cell(2, 1);

			Cell.CreatePath(from, to);

			Assert.IsTrue(from.IsPath(Cell.Direction.East));
			Assert.IsTrue(to.IsPath(Cell.Direction.West));

			Assert.IsFalse(from.IsPath(Cell.Direction.North));
			Assert.IsFalse(from.IsPath(Cell.Direction.South));
			Assert.IsFalse(from.IsPath(Cell.Direction.West));

			Assert.IsFalse(to.IsPath(Cell.Direction.North));
			Assert.IsFalse(to.IsPath(Cell.Direction.East));
			Assert.IsFalse(to.IsPath(Cell.Direction.South));
		}

		[Test, ExpectedException(typeof(ArgumentException))]
		public void CreatePathUsingNonNeighborCell()
		{
			Maze maze = new Maze(3, 3);

			Cell from = maze.Cell(1, 1);
			Cell to = maze.Cell(2, 2);

			Cell.CreatePath(from, to);
		}

		[Test]
		public void CreatePathUsingDirection()
		{
			Maze maze = new Maze(3, 3);

			Cell from = maze.Cell(1, 1);
			Cell to = maze.Cell(2, 1);

			Cell.CreatePath(from, Cell.Direction.East);

			Assert.IsTrue(from.IsPath(Cell.Direction.East));
			Assert.IsTrue(to.IsPath(Cell.Direction.West));

			Assert.IsFalse(from.IsPath(Cell.Direction.North));
			Assert.IsFalse(from.IsPath(Cell.Direction.South));
			Assert.IsFalse(from.IsPath(Cell.Direction.West));

			Assert.IsFalse(to.IsPath(Cell.Direction.North));
			Assert.IsFalse(to.IsPath(Cell.Direction.East));
			Assert.IsFalse(to.IsPath(Cell.Direction.South));
		}
	}
}
