using System;
using System.Collections.Generic;

namespace Theseus.Data
{
	public struct Size
	{
		public Size(int x, int y)
		{
			X = x;
			Y = y;
		}
		public int X;
		public int Y;
	}

	public struct Location
	{
		public Location(int x, int y)
		{
			X = x;
			Y = y;
		}

		public int X;
		public int Y;
	}

	public class Maze
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

		public override bool Equals(object obj)
		{
			if (obj == null) return false;
			if (!(obj is Maze)) return false;

			Maze other = obj as Maze;

			if (Size.X != other.Size.X || Size.Y != other.Size.Y) return false;

			for (int x = 0; x < Size.X; ++x)
			{
				for (int y = 0; y < Size.Y; ++y)
				{
					if (Cell(x, y) == Entrance && other.Cell(x, y) != other.Entrance) return false;
					if (Cell(x, y) == Exit && other.Cell(x, y) != other.Exit) return false;

					if (Cell(x, y).NorthOpen != other.Cell(x, y).NorthOpen) return false;
					if (Cell(x, y).EastOpen != other.Cell(x, y).EastOpen) return false;
					if (Cell(x, y).SouthOpen != other.Cell(x, y).SouthOpen) return false;
					if (Cell(x, y).WestOpen != other.Cell(x, y).WestOpen) return false;
				}
			}

			return true;
		}
	}
}
