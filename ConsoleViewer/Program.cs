using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Theseus.Data;
using Theseus.Generators;

namespace ConsoleViewer
{
	class Program
	{
		static void Main(string[] args)
		{
			Maze maze = new Maze(6, 4);

			GeneratorDepthFirst.Generate(maze);
			Draw(maze.Plot());

			Console.ReadKey();
		}

		private static void Draw(byte[][] plot)
		{
			for (byte y = 0; y < plot[0].Length; ++y)
			{
				for (byte x = 0; x < plot.Length; ++x)
				{
					char c;
					switch (plot[x][y])
					{
						case 0:	// Empty space
							c = ' ';
							break;
						case 1:	// Wall
							c = '*';
							break;
						case 2: // Entrance
						case 3: // Exit
							c = '.';
							break;
						default:
							c = ' ';
							break;
					}
					Console.Write(c);
				}
				Console.WriteLine();
			}
		}
	}
}
