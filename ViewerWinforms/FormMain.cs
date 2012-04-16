using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Theseus.ManagedCore;
using WinformsViewer.Generators;
using WinformsViewer.UserControl;
using Size = System.Drawing.Size;

namespace WinformsViewer
{
	public partial class FormMain : Form
	{
		private Maze _maze;
		private Avatar _avatar;
		private Plotter _plot;

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

			for (uint y = 0; y < _plot.getSizeHeight(); ++y)
			{
				for (uint x = 0; x < _plot.getSizeWidth(); ++x)
				{
					// Color
					Color color;
					switch (_plot.getPixel(x,y))
					{
						case Plotter.Pixels.Space:
							color = Color.White;
							break;
						case Plotter.Pixels.Wall:
							color = Color.Black;
							break;
						case Plotter.Pixels.Entrance:
							color = Color.YellowGreen;
							break;
						case Plotter.Pixels.Exit:
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

		private void DrawBlock(uint x, uint y, Color color)
		{
			// Position
			uint posX = Offset + (x * Thickness);
			uint posY = Offset + (y * Thickness);

			using (SolidBrush brush = new SolidBrush(color))
				_graphics.FillRectangle(brush, posX, posY, Thickness, Thickness);
		}

		private void btnCreate_Click(object sender, EventArgs e)
		{
			uint SizeX = (uint)numWidth.Value;
			uint SizeY = (uint)numHeight.Value;

			_maze = new Maze(SizeX, SizeY);

			switch (comboAlgorithm.SelectedIndex)
			{
				case 0:
					ConfiguratorDepthFirst conf = new ConfiguratorDepthFirst { RandomTraverse = ((PanelGeneratorDepthFirst)panelAlgorithmSettings).Random };
					GeneratorDepthFirst.generate(_maze, conf);
					break;
			}

			_plot = Plotter.plot(_maze);

			_avatar = new Avatar(findEntrance());

			canvas.Refresh();
		}

		private Location findEntrance()
		{
			for (uint y = 0; y < _plot.getSizeHeight(); ++y)
			{
				for (uint x = 0; x < _plot.getSizeWidth(); ++x)
				{
					if (_plot.getPixel(x, y) == Plotter.Pixels.Entrance)
						return new Location(x, y);
				}
			}

			return new Location(0, 0);
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
					if (_avatar.Location.Y > 0 && _plot.getPixel(_avatar.Location.X, _avatar.Location.Y - 1) == Plotter.Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X, _avatar.Location.Y - 1);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.D:
					if (_avatar.Location.X < _plot.getSizeWidth() && _plot.getPixel(_avatar.Location.X + 1, _avatar.Location.Y) == Plotter.Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X + 1, _avatar.Location.Y);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.S:
					if (_avatar.Location.Y < _plot.getSizeHeight() && _plot.getPixel(_avatar.Location.X, _avatar.Location.Y + 1) == Plotter.Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X, _avatar.Location.Y + 1);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
				case Keys.A:
					if (_avatar.Location.X > 0 && _plot.getPixel(_avatar.Location.X - 1, _avatar.Location.Y) == Plotter.Pixels.Space)
					{
						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.White);

						_avatar.Location = new Location(_avatar.Location.X - 1, _avatar.Location.Y);

						DrawBlock(_avatar.Location.X, _avatar.Location.Y, Color.Blue);
					}
					break;
			}
			return false;
		}

		private static Location TranslateLocation(Location mazeLocation)
		{
			Location plotLocation = new Location();

			plotLocation.X = mazeLocation.X * 2 + 1;
			plotLocation.Y = mazeLocation.Y * 2 + 1;

			return plotLocation;
		}
	}
}
