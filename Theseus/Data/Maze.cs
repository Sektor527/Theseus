using System;
using System.Collections.Generic;

namespace Theseus.Data
{
	struct Size
	{
		public Size(int x, int y)
		{
			X = x;
			Y = y;
		}
		public int X;
		public int Y;
	}

	struct Location
	{
		public Location(int x, int y)
		{
			X = x;
			Y = y;
		}

		public int X;
		public int Y;
	}

	internal class Maze
	{
		private readonly Cell[][] _cells;
		public Cell Entrance { get; internal set; }
		public Cell Exit { get; internal set; }

		public Maze(int sizeX, int sizeY)
		{
			if (sizeX <= 0 || sizeY <= 0) throw new ArgumentOutOfRangeException(String.Format("Incorrect size specified to construct maze: {0} x {1}", sizeX, sizeY));

			Size = new Size(sizeX, sizeY);

			// Create cells
			_cells = new Cell[sizeX][];
			for (int x = 0; x < sizeX; ++x)
			{
				_cells[x] = new Cell[sizeY];
				for (int y = 0; y < sizeY; ++y)
					_cells[x][y] = new Cell();
			}

			// Link cells
			for (int x = 0; x < sizeX; ++x)
			{
				for (int y = 0; y < sizeY; ++y)
				{
					Cell cell = _cells[x][y];

					if (x > 0) cell.West = _cells[x - 1][y];
					if (x < sizeX - 1) cell.East = _cells[x + 1][y];
					if (y > 0) cell.North = _cells[x][y - 1];
					if (y < sizeY - 1) cell.South = _cells[x][y + 1];
				}
			}

			// Set default entrance and exit
			Entrance = _cells[0][0];
			Exit = _cells[sizeX - 1][sizeY - 1];
		}

		public Size Size { private set; get; }

		public List<Cell> Cells
		{
			get
			{
				List<Cell> result = new List<Cell>(Size.X * Size.Y);
				for (int x = 0; x < Size.X; ++x)
				{
					result.AddRange(_cells[x]);
				}
				return result;
			}
		}

		public Cell Cell(int x, int y)
		{
			return _cells[x][y];
		}

		public Location Location(Cell cell)
		{
			for (int x = 0; x < Size.X; ++x)
			{
				for (int y = 0; y < Size.Y; ++y)
				{
					if (_cells[x][y] == cell)
						return new Location(x, y);
				}
			}

			throw new ArgumentException("Cell could not be found in maze");
		}

		public void Reset()
		{
			foreach (Cell cell in Cells)
			{
				cell.NorthOpen = false;
				cell.EastOpen = false;
				cell.SouthOpen = false;
				cell.WestOpen = false;
			}
		}
		public byte[][] Plot()
		{
			byte[][] plot = new byte[Size.X * 2 + 1][];
			for (int x = 0; x < Size.X * 2 + 1; ++x)
			{
				plot[x] = new byte[Size.Y * 2 + 1];
				for (int y = 0; y < Size.Y * 2 + 1; ++y)
				{
					if (y % 2 == 0) // Horizontal wall line
					{
						if (y == Size.Y * 2) // Last horizontal line
						{
							plot[x][y] = 1;
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// Corner points are always filled
							plot[x][y] = 1;
						}
						else // Vertical room line
						{
							// North-south passages
							Cell cell = Cell((x - 1) / 2, y / 2);
							if (cell.NorthOpen)
								plot[x][y] = 0;
							else
								plot[x][y] = 1;
						}
					}
					else // Horizontal room line
					{
						if (x == Size.X * 2) // Last vertical line
						{
							plot[x][y] = 1;
						}
						else if (x % 2 == 0) // Vertical wall line
						{
							// East-west passages
							Cell cell = Cell(x / 2, (y - 1) / 2);
							if (cell.WestOpen)
								plot[x][y] = 0;
							else
								plot[x][y] = 1;
						}
						else // Vertical room line
						{
							// Rooms
							plot[x][y] = 0;
						}
					}
				}
			}

			int plotX;
			int plotY;

			// Entrance
			plotX = Location(Entrance).X * 2 + 1;
			plotY = Location(Entrance).Y * 2 + 1;

			if (Entrance.North == null)
			{
				plot[plotX][plotY - 1] = 2;
			}
			else if (Entrance.South == null)
			{
				plot[plotX][plotY + 1] = 2;
			}
			else if (Entrance.West == null)
			{
				plot[plotX - 1][plotY] = 2;
			}
			else if (Entrance.East == null)
			{
				plot[plotX + 1][plotY] = 2;
			}

			// Exit
			plotX = Location(Exit).X * 2 + 1;
			plotY = Location(Exit).Y * 2 + 1;

			if (Exit.North == null)
			{
				plot[plotX][plotY - 1] = 3;
			}
			else if (Exit.South == null)
			{
				plot[plotX][plotY + 1] = 3;
			}
			else if (Exit.West == null)
			{
				plot[plotX - 1][plotY] = 3;
			}
			else if (Exit.East == null)
			{
				plot[plotX + 1][plotY] = 3;
			}

			return plot;
		}
	}
}
