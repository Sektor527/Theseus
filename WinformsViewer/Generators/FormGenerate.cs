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
using Size = System.Drawing.Size;

namespace WinformsViewer.Generators
{
	public partial class FormGenerate : Form
	{
		public FormGenerate()
		{
			InitializeComponent();
		}

		public int SizeX { get { return (int)numWidth.Value; } }
		public int SizeY { get { return (int)numHeight.Value; } }
		public UserControl Settings { get { return panelAlgorithmSettings; } }

		private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
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

		public Maze Maze { get; private set; }

		private void btnCreate_Click(object sender, EventArgs e)
		{
			Maze = new Maze(SizeX, SizeY);

			switch (comboAlgorithm.SelectedIndex)
			{
				case 0:
					ConfiguratorDepthFirst conf = new ConfiguratorDepthFirst { RandomTraverse = ((PanelGeneratorDepthFirst)panelAlgorithmSettings).Random };
					GeneratorDepthFirst.Generate(Maze, conf);
					break;
			}

		}

		private void FormGenerate_Load(object sender, EventArgs e)
		{
			comboAlgorithm.SelectedIndex = 0;
		}
	}
}
