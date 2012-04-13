using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Theseus.ManagedCore;

namespace WinformsViewer.UserControl
{
	internal struct Location
	{
		public Location(uint x, uint y)
		{
			X = x;
			Y = y;
		}

		public uint X;
		public uint Y;

		public override bool Equals(object obj)
		{
			if (obj == null) return false;
			if (obj.GetType() != typeof(Location)) return false;

			Location other = (Location)obj;

			return X == other.X && Y == other.Y;
		}
	}

	internal class Avatar
	{
		public Location Location { get; set; }

		public Avatar(Location location)
		{
			Location = location;
		}
	}
}
