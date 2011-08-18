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

			Generate(maze);
			byte[][] plot = Plot(maze);
			Draw(plot, maze.Size);

			Console.ReadKey();
		}

		private static void Generate(Maze maze)
		{
			Cell start = maze.Cell(0, 0);
			Cell.CreatePath(start, Cell.Direction.South);
			Cell.CreatePath(maze.Cell(0, 1), maze.Cell(1, 1));
			Cell.CreatePath(maze.Cell(1, 1), maze.Cell(1, 2));
			Cell.CreatePath(maze.Cell(1, 1), maze.Cell(2, 1));
			Cell.CreatePath(maze.Cell(0, 1), maze.Cell(0, 2));
		}

		private static byte[][] Plot(Maze maze)
		{
			byte[][] plot = new byte[maze.Size.Y * 2 + 1][];
			for (int y = 0; y < maze.Size.Y*2 + 1; ++y)
			{
				plot[y] = new byte[maze.Size.X * 2 + 1];
				for (int x = 0; x < maze.Size.X*2 + 1; ++x)
				{
					if (y%2 == 0) // Horizontal wall line
					{
						if (y == maze.Size.Y*2) // Last horizontal line
						{
							plot[y][x] = 1; //Console.Write("*");
						}
						else if (x%2 == 0) // Vertical wall line
						{
							// Corner points are always filled
							plot[y][x] = 1; //Console.Write("*");
						}
						else // Vertical room line
						{
							// North-south passages
							Cell cell = maze.Cell((x - 1)/2, y/2);
							if (cell.NorthOpen)
								plot[y][x] = 0; //Console.Write(" ");
							else
								plot[y][x] = 1; //Console.Write("*");
						}
					}
					else // Horizontal room line
					{
						if (x == maze.Size.X*2) // Last vertical line
						{
							plot[y][x] = 1; //Console.Write("*");
						}
						else if (x%2 == 0) // Vertical wall line
						{
							// East-west passages
							Cell cell = maze.Cell(x/2, (y - 1)/2);
							if (cell.WestOpen)
								plot[y][x] = 0; //Console.Write("*");
							else
								plot[y][x] = 1; //Console.Write("*");
						}
						else // Vertical room line
						{
							// Rooms are always open
							plot[y][x] = 0; //Console.Write("*");
						}
					}
				}

				//Console.WriteLine();
			}

			return plot;
		}

		private static void Draw(byte[][] plot, Size size)
		{
			for (byte y = 0; y < plot.Length; ++y)
			{
				for (byte x = 0; x < plot[y].Length; ++x)
					Console.Write(plot[y][x] == 0 ? " " : "*");
				Console.WriteLine();
			}
		}
	}
}
