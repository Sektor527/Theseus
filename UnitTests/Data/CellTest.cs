using NUnit.Framework;
using Theseus.Data;

namespace UnitTests.Data
{
	[TestFixture]
	class CellTest
	{
		[Test]
		public void CreateCell()
		{
			var cell = new Cell();
			Assert.IsNull(cell.North);
			Assert.IsNull(cell.East);
			Assert.IsNull(cell.South);
			Assert.IsNull(cell.West);
		}

		[Test]
		public void CreatePathWithDefaultDirection()
		{
			// Left to right (East <-> West)
			{
				var from = new Cell();
				var to = new Cell();

				Cell.CreatePath(from, Cell.Direction.East, to);

				Assert.AreSame(to, from.East);
				Assert.AreSame(from, to.West);

				Assert.IsNull(from.North);
				Assert.IsNull(from.South);
				Assert.IsNull(from.West);

				Assert.IsNull(to.North);
				Assert.IsNull(to.East);
				Assert.IsNull(to.South);
			}

			// Right to left (West <-> East)
			{
				var from = new Cell();
				var to = new Cell();

				Cell.CreatePath(from, Cell.Direction.West, to);

				Assert.AreSame(to, from.West);
				Assert.AreSame(from, to.East);

				Assert.IsNull(from.North);
				Assert.IsNull(from.East);
				Assert.IsNull(from.South);

				Assert.IsNull(to.North);
				Assert.IsNull(to.South);
				Assert.IsNull(to.West);
			}

			// Top to bottom (South <-> North)
			{
				var from = new Cell();
				var to = new Cell();

				Cell.CreatePath(from, Cell.Direction.South, to);

				Assert.AreSame(to, from.South);
				Assert.AreSame(from, to.North);

				Assert.IsNull(from.North);
				Assert.IsNull(from.East);
				Assert.IsNull(from.West);

				Assert.IsNull(to.East);
				Assert.IsNull(to.South);
				Assert.IsNull(to.West);
			}

			// Bottom to top (North <-> South)
			{
				var from = new Cell();
				var to = new Cell();

				Cell.CreatePath(from, Cell.Direction.North, to);

				Assert.AreSame(to, from.North);
				Assert.AreSame(from, to.South);

				Assert.IsNull(from.East);
				Assert.IsNull(from.South);
				Assert.IsNull(from.West);

				Assert.IsNull(to.North);
				Assert.IsNull(to.East);
				Assert.IsNull(to.West);
			}
		}

		[Test]
		public void CreatePathWithCustomDirection()
		{
			var from = new Cell();
			var to = new Cell();

			Cell.CreatePath(from, Cell.Direction.East, to, Cell.Direction.North);

			Assert.AreSame(to, from.East);
			Assert.AreSame(from, to.North);

			Assert.IsNull(from.North);
			Assert.IsNull(from.South);
			Assert.IsNull(from.West);

			Assert.IsNull(to.East);
			Assert.IsNull(to.South);
			Assert.IsNull(to.West);
		}
	}
}
