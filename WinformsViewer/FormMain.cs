using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Theseus.Data;
using Theseus.Generators;
using WinformsViewer.Generators;
using Theseus.Plotter;

namespace WinformsViewer
{
	public partial class FormMain : Form
	{
		private Maze _maze;

		private const int Offset = 10;
		private const int Thickness = 3;

		public FormMain()
		{
			InitializeComponent();
		}

		private void FormMain_Load(object sender, EventArgs e)
		{
		}

		private void canvas_Paint(object sender, PaintEventArgs e)
		{
			if (_maze == null) return;

			byte[][] plot = Plotter.Plot(_maze);

			using (Graphics graphics = e.Graphics)
			{
				for (byte y = 0; y < plot[0].Length; ++y)
				{
					for (byte x = 0; x < plot.Length; ++x)
					{
						// Color
						Color color;
						switch (plot[x][y])
						{
							case 0: // Empty space
								color = Color.White;
								break;
							case 1: // Wall
								color = Color.Black;
								break;
							case 2: // Entrance
								color = Color.YellowGreen;
								break;
							case 3: // Exit
								color = Color.YellowGreen;
								break;
							default:
								color = Color.White;
								break;
						}

						// Position
						int posX = Offset + (x * Thickness);
						int posY = Offset + (y * Thickness);

						using (SolidBrush brush = new SolidBrush(color))
							graphics.FillRectangle(brush, posX, posY, Thickness, Thickness);
					}
				}
			}
		}

		private void depthFirstToolStripMenuItem_Click(object sender, EventArgs e)
		{
			FormGenerate form = new FormGenerate();
			DialogResult res = form.ShowDialog();
			if (res == DialogResult.Cancel) return;

			_maze = form.Maze;

			canvas.Refresh();
		}
	}
}
