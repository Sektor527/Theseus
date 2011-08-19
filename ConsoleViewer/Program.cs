﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Theseus.Data;
using Theseus.Generators;
using Theseus.Plotter;

namespace ConsoleViewer
{
	class Program
	{
		static void Main(string[] args)
		{
			int sizeX = 20, sizeY = 10;

			if (args.Length == 1)
			{
				int arg;
				if (int.TryParse(args[0], out arg))
				{
					sizeX = arg;
					sizeY = arg;
				}
			}
			else if (args.Length >= 2)
			{
				int arg1;
				int arg2;
				if (!int.TryParse(args[0], out arg1))
				{
					sizeX = arg1;
				}
				if (!int.TryParse(args[1], out arg2))
				{
					sizeY = arg2;
				}
			}

			Maze maze = new Maze(sizeX, sizeY);
			ConfiguratorDepthFirst conf = new ConfiguratorDepthFirst { RandomTraverse = true };

			bool quit = false;
			while (!quit)
			{
				maze.Reset();
				GeneratorDepthFirst.Generate(maze, conf);

				Console.Clear();
				Draw(maze);
				DrawLegend();

				ConsoleKeyInfo key = Console.ReadKey();
				if (key.Key == ConsoleKey.Escape || key.Key == ConsoleKey.Q) quit = true;
			}

		}

		private static void Draw(Maze maze)
		{
			Plot plot = Plotter.Plot(maze);
			for (byte y = 0; y < plot.Size.Y; ++y)
			{
				for (byte x = 0; x < plot.Size.X; ++x)
				{
					char c;
					switch (plot.Image[x][y])
					{
						case Pixels.Space:
							c = ' ';
							break;
						case Pixels.Wall:
							c = '*';
							break;
						case Pixels.Entrance:
						case Pixels.Exit:
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

		private static void DrawLegend()
		{
			Console.WriteLine();
			Console.WriteLine("<space> - new maze; <q> - quit");
		}
	}
}
