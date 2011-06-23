using System;

namespace Theseus.Data
{
	class Cell
	{
		public enum Direction
		{
			North,
			East,
			South,
			West
		}

		public Cell North { get; set; }
		public Cell East { get; set; }
		public Cell South { get; set; }
		public Cell West { get; set; }

		private void SetPath(Direction dir, Cell to)
		{
			switch (dir)
			{
				case Direction.North:
					North = to;
					break;
				case Direction.East:
					East = to;
					break;
				case Direction.South:
					South = to;
					break;
				case Direction.West:
					West = to;
					break;
			}
		}

		public static void CreatePath(Cell from, Direction fromdir, Cell to)
		{
			Direction todir;
			switch (fromdir)
			{
				case Direction.North:
					CreatePath(from, fromdir, to, Direction.South);
					break;
				case Direction.South:
					CreatePath(from, fromdir, to, Direction.North);
					break;
				case Direction.East:
					CreatePath(from, fromdir, to, Direction.West);
					break;
				case Direction.West:
					CreatePath(from, fromdir, to, Direction.East);
					break;
			}
		}

		public static void CreatePath(Cell from, Direction fromdir, Cell to, Direction todir)
		{
			from.SetPath(fromdir, to);
			to.SetPath(todir, from);
		}
	}
}
