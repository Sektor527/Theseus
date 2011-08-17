using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Theseus.Data;

namespace ConsoleViewer
{
	class Program
	{
		static void Main(string[] args)
		{
			Maze maze = new Maze(4, 6);

			Cell start = maze.Cell(0, 0);
			Cell.CreatePath(start, Cell.Direction.South);
			Cell.CreatePath(maze.Cell(0, 1), maze.Cell(1, 1));

			for (int y = 0; y < maze.Size.Y * 2 + 1; ++y)
			{
				for (int x = 0; x < maze.Size.X * 2 + 1; ++x)
				{
					if (y % 2 == 0) // Horizontal wall line
					{
						if (y == maze.Size.Y * 2) // Last horizontal line
						{
							Console.Write("*");
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// Corner points are always filled
							Console.Write("*");
						}
						else // Vertical room line
						{
							// North-south passages
							Cell cell = maze.Cell((x - 1) / 2, y / 2);
							if (cell.NorthOpen)
								Console.Write(" ");
							else
								Console.Write("*");
						}
					}
					else // Horizontal room line
					{
						if (x == maze.Size.X * 2) // Last vertical line
						{
							Console.Write("*");
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// East-west passages
							Cell cell = maze.Cell(x / 2, (y - 1) / 2);
							if (cell.WestOpen)
								Console.Write(" ");
							else
								Console.Write("*");
						}
						else // Vertical room line
						{
							// Rooms are always open
							Console.Write(" ");
						}
					}
				}

				Console.WriteLine();
			}
			Console.ReadKey();
		}
	}
}
