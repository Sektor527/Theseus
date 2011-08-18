using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Theseus.Data;

namespace Theseus.Generators
{
	public struct ConfiguratorDepthFirst
	{
		public bool RandomTraverse;
	}

	public static class GeneratorDepthFirst
	{
		private static Maze _maze;
		private static ConfiguratorDepthFirst _configurator;

		private static readonly Random Rnd = new Random((int)DateTime.Now.Ticks);
		private static List<Cell> _visited;

		public static void Generate(Maze maze, ConfiguratorDepthFirst configurator)
		{
			// Initialize
			_configurator = configurator;
			_maze = maze;
			_visited = new List<Cell>(maze.Size.X * maze.Size.Y);

			Visit(maze.Exit);
		}

		private static void Visit(Cell cell)
		{
			Stack<Cell> running = new Stack<Cell>(_maze.Size.X * _maze.Size.Y);

			_visited.Add(cell);

			running.Push(cell);
			while (running.Count > 0)
			{
				Cell current = running.Peek();

				List<Cell> neighbors = current.Neighbors;
				if (_configurator.RandomTraverse)
					neighbors.Shuffle();

				bool finished = true;
				foreach (Cell neighbor in neighbors)
				{
					if (neighbor == null) continue;
					if (_visited.Contains(neighbor)) continue;

					finished = false;

					Cell.CreatePath(current, neighbor);
					running.Push(neighbor);
					_visited.Add(neighbor);
					break;
				}

				if (finished)
					running.Pop();
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
