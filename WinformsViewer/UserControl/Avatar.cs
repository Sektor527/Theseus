using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Theseus.Data;

namespace WinformsViewer.UserControl
{
	internal class Avatar
	{
		public Cell Cell { get; private set; }

		public Avatar(Cell entrance)
		{
			Cell = entrance;
		}

		public void Move(Cell.Direction direction)
		{
			switch (direction)
			{
				case Cell.Direction.North:
					if (Cell.NorthOpen) Cell = Cell.North;
					break;
				case Cell.Direction.East:
					if (Cell.EastOpen) Cell = Cell.East;
					break;
				case Cell.Direction.South:
					if (Cell.SouthOpen) Cell = Cell.South;
					break;
				case Cell.Direction.West:
					if (Cell.WestOpen) Cell = Cell.West;
					break;
			}
		}
	}
}
