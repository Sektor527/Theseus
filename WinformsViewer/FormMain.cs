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
		private Plot _plot;

		private Graphics _graphics;

		private const int Offset = 10;
		private const int Thickness = 3;

		public FormMain()
		{
			InitializeComponent();
		}

		private void canvas_Paint(object sender, PaintEventArgs e)
		{
			_graphics = canvas.CreateGraphics();

			if (_maze == null) return;

			for (int y = 0; y < _plot.Size.Y; ++y)
			{
				for (int x = 0; x < _plot.Size.X; ++x)
				{
					// Color
					Color color;
					switch (_plot.Image[x][y])
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

					Location avatarLocation = _avatar.Location;
					if (avatarLocation.Equals(new Location(x, y)))
						color = Color.Blue;

					DrawBlock(x, y, color);
				}
			}
		}

		private void DrawBlock(int x, int y, Color color)
		{
			// Position
			int posX = Offset + (x * Thickness);
			int posY = Offset + (y * Thickness);

			using (SolidBrush brush = new SolidBrush(color))
				_graphics.FillRectangle(brush, posX, posY, Thickness, Thickness);
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

			_plot = Plotter.Plot(_maze);

			Location entrance = Plotter.TranslateLocation(_maze.Location(_maze.Entrance));
			_avatar = new Avatar(new Location(entrance.X, entrance.Y - 1));

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
					if (_avatar.Location.Y > 0 && _plot.Image[_avatar.Location.X][_avatar.Location.Y - 1] == Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X, _avatar.Location.Y - 1);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.D:
					if (_avatar.Location.X < _plot.Size.X && _plot.Image[_avatar.Location.X + 1][_avatar.Location.Y] == Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X + 1, _avatar.Location.Y);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.S:
					if (_avatar.Location.Y < _plot.Size.Y && _plot.Image[_avatar.Location.X][_avatar.Location.Y + 1] == Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X, _avatar.Location.Y + 1);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.A:
					if (_avatar.Location.X > 0 && _plot.Image[_avatar.Location.X - 1][_avatar.Location.Y] == Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X - 1, _avatar.Location.Y);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
			}
			return false;
		}
	}
}
