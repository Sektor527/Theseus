namespace WinformsViewer
{
	partial class FormMain
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.Windows.Forms.Label label3;
			System.Windows.Forms.Label label2;
			this.canvas = new System.Windows.Forms.Panel();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.splitContainer1 = new System.Windows.Forms.SplitContainer();
			this.btnCreate = new System.Windows.Forms.Button();
			this.groupSettings = new System.Windows.Forms.GroupBox();
			this.comboAlgorithm = new System.Windows.Forms.ComboBox();
			this.numHeight = new System.Windows.Forms.NumericUpDown();
			this.numWidth = new System.Windows.Forms.NumericUpDown();
			this.panelAlgorithmSettings = new WinformsViewer.Generators.PanelGeneratorDepthFirst();
			label3 = new System.Windows.Forms.Label();
			label2 = new System.Windows.Forms.Label();
			this.splitContainer1.Panel1.SuspendLayout();
			this.splitContainer1.Panel2.SuspendLayout();
			this.splitContainer1.SuspendLayout();
			this.groupSettings.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.numHeight)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.numWidth)).BeginInit();
			this.SuspendLayout();
			// 
			// label3
			// 
			label3.AutoSize = true;
			label3.Location = new System.Drawing.Point(4, 31);
			label3.Name = "label3";
			label3.Size = new System.Drawing.Size(38, 13);
			label3.TabIndex = 9;
			label3.Text = "Height";
			// 
			// label2
			// 
			label2.AutoSize = true;
			label2.Location = new System.Drawing.Point(3, 7);
			label2.Name = "label2";
			label2.Size = new System.Drawing.Size(35, 13);
			label2.TabIndex = 8;
			label2.Text = "Width";
			// 
			// canvas
			// 
			this.canvas.BackColor = System.Drawing.Color.White;
			this.canvas.Dock = System.Windows.Forms.DockStyle.Fill;
			this.canvas.Location = new System.Drawing.Point(0, 0);
			this.canvas.Name = "canvas";
			this.canvas.Size = new System.Drawing.Size(590, 398);
			this.canvas.TabIndex = 0;
			this.canvas.Paint += new System.Windows.Forms.PaintEventHandler(this.canvas_Paint);
			// 
			// menuStrip1
			// 
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(794, 24);
			this.menuStrip1.TabIndex = 1;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// splitContainer1
			// 
			this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
			this.splitContainer1.Location = new System.Drawing.Point(0, 24);
			this.splitContainer1.Name = "splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this.splitContainer1.Panel1.Controls.Add(this.canvas);
			// 
			// splitContainer1.Panel2
			// 
			this.splitContainer1.Panel2.Controls.Add(this.btnCreate);
			this.splitContainer1.Panel2.Controls.Add(this.groupSettings);
			this.splitContainer1.Panel2.Controls.Add(this.numHeight);
			this.splitContainer1.Panel2.Controls.Add(this.numWidth);
			this.splitContainer1.Panel2.Controls.Add(label3);
			this.splitContainer1.Panel2.Controls.Add(label2);
			this.splitContainer1.Size = new System.Drawing.Size(794, 398);
			this.splitContainer1.SplitterDistance = 590;
			this.splitContainer1.TabIndex = 3;
			// 
			// btnCreate
			// 
			this.btnCreate.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.btnCreate.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.btnCreate.Location = new System.Drawing.Point(4, 363);
			this.btnCreate.Name = "btnCreate";
			this.btnCreate.Size = new System.Drawing.Size(193, 23);
			this.btnCreate.TabIndex = 13;
			this.btnCreate.Text = "Create";
			this.btnCreate.UseVisualStyleBackColor = true;
			this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
			// 
			// groupSettings
			// 
			this.groupSettings.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
									| System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.groupSettings.Controls.Add(this.panelAlgorithmSettings);
			this.groupSettings.Controls.Add(this.comboAlgorithm);
			this.groupSettings.Location = new System.Drawing.Point(7, 61);
			this.groupSettings.Name = "groupSettings";
			this.groupSettings.Size = new System.Drawing.Size(190, 296);
			this.groupSettings.TabIndex = 12;
			this.groupSettings.TabStop = false;
			// 
			// comboAlgorithm
			// 
			this.comboAlgorithm.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.comboAlgorithm.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboAlgorithm.FormattingEnabled = true;
			this.comboAlgorithm.Items.AddRange(new object[] {
            "Depth First",
            "None"});
			this.comboAlgorithm.Location = new System.Drawing.Point(9, 0);
			this.comboAlgorithm.Name = "comboAlgorithm";
			this.comboAlgorithm.Size = new System.Drawing.Size(173, 21);
			this.comboAlgorithm.TabIndex = 0;
			this.comboAlgorithm.SelectedIndexChanged += new System.EventHandler(this.comboAlgorithm_SelectedIndexChanged);
			// 
			// numHeight
			// 
			this.numHeight.Location = new System.Drawing.Point(45, 29);
			this.numHeight.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
			this.numHeight.Name = "numHeight";
			this.numHeight.Size = new System.Drawing.Size(88, 20);
			this.numHeight.TabIndex = 11;
			this.numHeight.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
			// 
			// numWidth
			// 
			this.numWidth.Location = new System.Drawing.Point(45, 5);
			this.numWidth.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
			this.numWidth.Name = "numWidth";
			this.numWidth.Size = new System.Drawing.Size(88, 20);
			this.numWidth.TabIndex = 10;
			this.numWidth.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
			// 
			// panelAlgorithmSettings
			// 
			this.panelAlgorithmSettings.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
									| System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.panelAlgorithmSettings.Location = new System.Drawing.Point(6, 25);
			this.panelAlgorithmSettings.Name = "panelAlgorithmSettings";
			this.panelAlgorithmSettings.Size = new System.Drawing.Size(178, 265);
			this.panelAlgorithmSettings.TabIndex = 1;
			// 
			// FormMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(794, 422);
			this.Controls.Add(this.splitContainer1);
			this.Controls.Add(this.menuStrip1);
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "FormMain";
			this.Text = "Theseus";
			this.Load += new System.EventHandler(this.FormMain_Load);
			this.splitContainer1.Panel1.ResumeLayout(false);
			this.splitContainer1.Panel2.ResumeLayout(false);
			this.splitContainer1.Panel2.PerformLayout();
			this.splitContainer1.ResumeLayout(false);
			this.groupSettings.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.numHeight)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.numWidth)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Panel canvas;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.SplitContainer splitContainer1;
		private System.Windows.Forms.GroupBox groupSettings;
		private WinformsViewer.Generators.PanelGeneratorDepthFirst panelAlgorithmSettings;
		private System.Windows.Forms.ComboBox comboAlgorithm;
		private System.Windows.Forms.NumericUpDown numHeight;
		private System.Windows.Forms.NumericUpDown numWidth;
		public System.Windows.Forms.Button btnCreate;

	}
}

