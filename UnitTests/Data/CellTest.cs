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
	}
}
