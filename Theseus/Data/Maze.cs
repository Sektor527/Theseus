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
	}
}
