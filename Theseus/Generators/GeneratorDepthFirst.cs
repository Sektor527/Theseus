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

		public static void Generate(Maze maze, bool random)
		{
			// Initialize
			_maze = maze;
			_visited = new List<Cell>(maze.Size.X * maze.Size.Y);

			// Recursively go through cells and link them up with one another
			Visit(maze.Exit, random);
		}

		private static void Visit(Cell cell, bool random)
		{
			_visited.Add(cell);

			List<Cell> neighbors = cell.Neighbors;
			if (random)
				neighbors.Shuffle();

			foreach (Cell neighbor in neighbors)
			{
				if (neighbor == null) continue;
				if (_visited.Contains(neighbor)) continue;

				Cell.CreatePath(cell, neighbor);
				Visit(neighbor, random);
			}
		}

		private static void Shuffle<T>(this IList<T> list)
		{
			int n = list.Count;
			while (n > 1)
			{
				n--;
				int k = Rnd.Next(n + 1);
				T value = list[k];
				list[k] = list[n];
				list[n] = value;
			}
		}
	}
}
