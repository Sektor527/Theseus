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
			Maze maze = new Maze(4,6);

			for (int x = 0; x < maze.Size.X * 2 + 1; ++x)
			{
				for (int y = 0; y < maze.Size.Y * 2 + 1; ++y)
				{
					if (y % 2 == 0) // Horizontal wall line
					{
						if (x % 2 == 0) // Vertical wall line
						{
							// Corner points are always filled
							Console.Write("*");
						}
						else // Vertical room line
						{
							// North-south passages
							Console.Write("*");
						}
					}
					else // Horizontal room line
					{
						if (x % 2 == 0) // Vertical wall line
						{
							// East-west passages
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
