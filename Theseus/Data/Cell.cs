using System;
using System.Collections.Generic;

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

		public bool NorthOpen { get; set; }
		public bool EastOpen { get; set; }
		public bool SouthOpen { get; set; }
		public bool WestOpen { get; set; }

		public List<Cell> Neighbors
		{
			get
			{
				List<Cell> result = new List<Cell>(4) { North, East, South, West };
				return result;
			}
		}

		public static void CreatePath(Cell from, Cell to)
		{
			if (!from.Neighbors.Contains(to)) throw new ArgumentException();

			if (from.North == to)
			{
				from.NorthOpen = true;
				to.SouthOpen = true;
			}

			if (from.East == to)
			{
				from.EastOpen = true;
				to.WestOpen = true;
			}

			if (from.South == to)
			{
				from.SouthOpen = true;
				to.NorthOpen = true;
			}

			if (from.West == to)
			{
				from.WestOpen = true;
				to.EastOpen = true;
			}
		}

		public static void CreatePath(Cell from, Direction direction)
		{
			Cell to;

			switch (direction)
			{
				case Direction.North:
					to = from.North;
					from.NorthOpen = true;
					to.SouthOpen = true;
					break;

				case Direction.East:
					to = from.East;
					from.EastOpen = true;
					to.WestOpen = true;
					break;

				case Direction.South:
					to = from.South;
					from.SouthOpen = true;
					to.NorthOpen = true;
					break;

				case Direction.West:
					to = from.West;
					from.WestOpen = true;
					to.EastOpen = true;
					break;
			}
		}

		public bool IsPath(Direction direction)
		{
			switch (direction)
			{
				case Direction.North: return NorthOpen;
				case Direction.East: return EastOpen;
				case Direction.South: return SouthOpen;
				case Direction.West: return WestOpen;
				default: throw new InvalidOperationException("Unknown direction " + direction.ToString());
			}
		}
	}
}
