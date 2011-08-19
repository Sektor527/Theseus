﻿using Theseus.Data;

namespace Theseus.Plotter
{
	public static class Plotter
	{
		public static byte[][] Plot(Maze maze)
		{
			byte[][] plot = new byte[maze.Size.X * 2 + 1][];
			for (int x = 0; x < maze.Size.X * 2 + 1; ++x)
			{
				plot[x] = new byte[maze.Size.Y * 2 + 1];
				for (int y = 0; y < maze.Size.Y * 2 + 1; ++y)
				{
					if (y % 2 == 0) // Horizontal wall line
					{
						if (y == maze.Size.Y * 2) // Last horizontal line
						{
							plot[x][y] = Pixels.Wall;
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// Corner points are always filled
							plot[x][y] = Pixels.Wall;
						}
						else // Vertical room line
						{
							// North-south passages
							Cell cell = maze.Cell((x - 1) / 2, y / 2);
							if (cell.NorthOpen)
								plot[x][y] = Pixels.Space;
							else
								plot[x][y] = Pixels.Wall;
						}
					}
					else // Horizontal room line
					{
						if (x == maze.Size.X * 2) // Last vertical line
						{
							plot[x][y] = Pixels.Wall;
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// East-west passages
							Cell cell = maze.Cell(x / 2, (y - 1) / 2);
							if (cell.WestOpen)
								plot[x][y] = Pixels.Space;
							else
								plot[x][y] = Pixels.Wall;
						}
						else // Vertical room line
						{
							// Rooms
							plot[x][y] = Pixels.Space;
						}
					}
				}
			}

			int plotX;
			int plotY;

			// Entrance
			plotX = maze.Location(maze.Entrance).X * 2 + 1;
			plotY = maze.Location(maze.Entrance).Y * 2 + 1;

			if (maze.Entrance.North == null)
			{
				plot[plotX][plotY - 1] = Pixels.Entrance;
			}
			else if (maze.Entrance.South == null)
			{
				plot[plotX][plotY + 1] = Pixels.Entrance;
			}
			else if (maze.Entrance.West == null)
			{
				plot[plotX - 1][plotY] = Pixels.Entrance;
			}
			else if (maze.Entrance.East == null)
			{
				plot[plotX + 1][plotY] = Pixels.Entrance;
			}

			// Exit
			plotX = maze.Location(maze.Exit).X * 2 + 1;
			plotY = maze.Location(maze.Exit).Y * 2 + 1;

			if (maze.Exit.North == null)
			{
				plot[plotX][plotY - 1] = Pixels.Exit;
			}
			else if (maze.Exit.South == null)
			{
				plot[plotX][plotY + 1] = Pixels.Exit;
			}
			else if (maze.Exit.West == null)
			{
				plot[plotX - 1][plotY] = Pixels.Exit;
			}
			else if (maze.Exit.East == null)
			{
				plot[plotX + 1][plotY] = Pixels.Exit;
			}

			return plot;
		}
	}
}