using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Theseus.Data;

namespace WinformsViewer.UserControl
{
	internal class Avatar
	{
		public Location Location { get; set; }

		public Avatar(Location location)
		{
			Location = location;
		}
	}
}
