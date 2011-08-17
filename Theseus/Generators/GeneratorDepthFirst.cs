using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Theseus.Data;

namespace Theseus.Generators
{
	static class GeneratorDepthFirst
	{
		private static readonly Random Rnd = new Random((int)DateTime.Now.Ticks);
		private static List<Cell> _visited;

		private static Maze _maze;

		public static void Generate(Maze maze)
		{
			// Initialize
			_maze = maze;
			_visited = new List<Cell>(maze.Size.X * maze.Size.Y);

			// Choose start cell
			Cell exit = maze.Cell(Rnd.Next(maze.Size.X - 1), maze.Size.Y - 1);

			// Recursively go through cells and link them up with one another
			Visit(exit);
		}

		private static void Visit(Cell cell)
		{
			_visited.Add(cell);

			// TODO: randomize order of Neighbors to make an interesting maze
			foreach (Cell neighbor in cell.Neighbors)
			{
				if (neighbor == null) continue;
				if (_visited.Contains(neighbor)) continue;

				Cell.CreatePath(cell, neighbor);
				Visit(neighbor);
			}
		}
	}
}
