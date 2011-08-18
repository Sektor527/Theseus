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
							// Rooms are always open
							plot[x][y] = 0;
						}
					}
				}
			}

			return plot;
		}
	}
}
