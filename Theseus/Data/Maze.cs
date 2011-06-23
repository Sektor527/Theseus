using System;

namespace Theseus.Data
{
	internal class Maze
	{
		private readonly Cell[][] _cells;

		public Maze(int sizeX, int sizeY)
		{
			if (sizeX <= 0 || sizeY <= 0) throw new ArgumentOutOfRangeException(String.Format("Incorrect size specified to construct maze: {0} x {1}", sizeX, sizeY));

			_cells = new Cell[sizeX][];
			for (int x = 0; x < sizeX; ++x)
			{
				_cells[x] = new Cell[sizeY];
				for (int y = 0; y < sizeY; ++y)
					_cells[x][y] = new Cell();
			}
		}

		public Cell Cell(int x, int y)
		{
			return _cells[x][y];
		}
	}
}
