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
using Theseus.Plotter;
using WinformsViewer.Generators;
using WinformsViewer.UserControl;
using Size = System.Drawing.Size;

namespace WinformsViewer
{
	public partial class FormMain : Form
	{
		private Maze _maze;
		private Avatar _avatar;

		private const int Offset = 10;
		private const int Thickness = 3;

		public FormMain()
		{
			InitializeComponent();
		}

		private void canvas_Paint(object sender, PaintEventArgs e)
		{
			if (_maze == null) return;

			Plot plot = Plotter.Plot(_maze);

			using (Graphics graphics = e.Graphics)
			{
				for (int y = 0; y < plot.Size.Y; ++y)
				{
					for (int x = 0; x < plot.Size.X; ++x)
					{
						// Color
						Color color;
						switch (plot.Image[x][y])
						{
							case Pixels.Space:
								color = Color.White;
								break;
							case Pixels.Wall:
								color = Color.Black;
								break;
							case Pixels.Entrance:
								color = Color.YellowGreen;
								break;
							case Pixels.Exit:
								color = Color.YellowGreen;
								break;
							default:
								color = Color.White;
								break;
						}

						Location avatarLocation = Plotter.TranslateLocation(_maze.Location(_avatar.Cell));
						if (avatarLocation.Equals(new Location(x, y)))
							color = Color.Blue;


						// Position
						int posX = Offset + (x * Thickness);
						int posY = Offset + (y * Thickness);

						using (SolidBrush brush = new SolidBrush(color))
							graphics.FillRectangle(brush, posX, posY, Thickness, Thickness);
					}
				}
			}
		}

		private void btnCreate_Click(object sender, EventArgs e)
		{
		int SizeX = (int)numWidth.Value;
		int SizeY = (int)numHeight.Value;

		_maze = new Maze(SizeX, SizeY);

			switch (comboAlgorithm.SelectedIndex)
			{
				case 0:
					ConfiguratorDepthFirst conf = new ConfiguratorDepthFirst { RandomTraverse = ((PanelGeneratorDepthFirst)panelAlgorithmSettings).Random };
					GeneratorDepthFirst.Generate(_maze, conf);
					break;
			}

			_avatar = new Avatar(_maze.Entrance);

			canvas.Refresh();
		}

		private void comboAlgorithm_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (panelAlgorithmSettings != null)
			{
				groupSettings.Controls.Remove(panelAlgorithmSettings);
				panelAlgorithmSettings.Dispose();
				panelAlgorithmSettings = null;
			}

			switch (comboAlgorithm.SelectedIndex)
			{
				case 0: // Depth First
					panelAlgorithmSettings = new PanelGeneratorDepthFirst();
					panelAlgorithmSettings.Location = new Point(6, 25);
					panelAlgorithmSettings.Name = "panelAlgorithmSettings";
					panelAlgorithmSettings.Size = new Size(202, 181);
					groupSettings.Controls.Add(panelAlgorithmSettings);
					break;
			}
		}

		private void FormMain_Load(object sender, EventArgs e)
		{
			comboAlgorithm.SelectedIndex = 0;
		}

		protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
		{
			switch (keyData)
			{
				case Keys.Space:
					btnCreate_Click(this, new EventArgs());
					return true;
				case Keys.Q:
					Close();
					return true;
				case Keys.W:
					_avatar.Move(Cell.Direction.North);
					canvas.Refresh();
					break;
				case Keys.D:
					_avatar.Move(Cell.Direction.East);
					canvas.Refresh();
					break;
				case Keys.S:
					_avatar.Move(Cell.Direction.South);
					canvas.Refresh();
					break;
				case Keys.A:
					_avatar.Move(Cell.Direction.West);
					canvas.Refresh();
					break;
			}
			return false;
		}
	}
}
