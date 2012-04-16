using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WinformsViewer.Generators
{
	public partial class PanelGeneratorDepthFirst : System.Windows.Forms.UserControl
	{
		public PanelGeneratorDepthFirst()
		{
			InitializeComponent();
		}

		public bool Random { get { return checkBox1.Checked; } }
	}
}
