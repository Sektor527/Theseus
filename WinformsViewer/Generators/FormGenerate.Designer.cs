namespace WinformsViewer.Generators
{
	partial class FormGenerate
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
			System.Windows.Forms.Label label2;
			System.Windows.Forms.Label label3;
			this.comboAlgorithm = new System.Windows.Forms.ComboBox();
			this.numWidth = new System.Windows.Forms.NumericUpDown();
			this.numHeight = new System.Windows.Forms.NumericUpDown();
			this.groupSettings = new System.Windows.Forms.GroupBox();
			this.btnCreate = new System.Windows.Forms.Button();
			this.btnCancel = new System.Windows.Forms.Button();
			this.panelAlgorithmSettings = new WinformsViewer.Generators.PanelGeneratorDepthFirst();
			label2 = new System.Windows.Forms.Label();
			label3 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.numWidth)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.numHeight)).BeginInit();
			this.groupSettings.SuspendLayout();
			this.SuspendLayout();
			// 
			// label2
			// 
			label2.AutoSize = true;
			label2.Location = new System.Drawing.Point(13, 14);
			label2.Name = "label2";
			label2.Size = new System.Drawing.Size(35, 13);
			label2.TabIndex = 2;
			label2.Text = "Width";
			// 
			// label3
			// 
			label3.AutoSize = true;
			label3.Location = new System.Drawing.Point(121, 14);
			label3.Name = "label3";
			label3.Size = new System.Drawing.Size(38, 13);
			label3.TabIndex = 3;
			label3.Text = "Height";
			// 
			// comboAlgorithm
			// 
			this.comboAlgorithm.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboAlgorithm.FormattingEnabled = true;
			this.comboAlgorithm.Items.AddRange(new object[] {
            "Depth First",
            "None"});
			this.comboAlgorithm.Location = new System.Drawing.Point(9, 0);
			this.comboAlgorithm.Name = "comboAlgorithm";
			this.comboAlgorithm.Size = new System.Drawing.Size(121, 21);
			this.comboAlgorithm.TabIndex = 0;
			this.comboAlgorithm.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
			// 
			// numWidth
			// 
			this.numWidth.Location = new System.Drawing.Point(54, 12);
			this.numWidth.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
			this.numWidth.Name = "numWidth";
			this.numWidth.Size = new System.Drawing.Size(61, 20);
			this.numWidth.TabIndex = 4;
			this.numWidth.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
			// 
			// numHeight
			// 
			this.numHeight.Location = new System.Drawing.Point(165, 12);
			this.numHeight.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
			this.numHeight.Name = "numHeight";
			this.numHeight.Size = new System.Drawing.Size(61, 20);
			this.numHeight.TabIndex = 5;
			this.numHeight.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
			// 
			// groupSettings
			// 
			this.groupSettings.Controls.Add(this.panelAlgorithmSettings);
			this.groupSettings.Controls.Add(this.comboAlgorithm);
			this.groupSettings.Location = new System.Drawing.Point(12, 38);
			this.groupSettings.Name = "groupSettings";
			this.groupSettings.Size = new System.Drawing.Size(214, 183);
			this.groupSettings.TabIndex = 6;
			this.groupSettings.TabStop = false;
			// 
			// btnCreate
			// 
			this.btnCreate.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.btnCreate.Location = new System.Drawing.Point(12, 227);
			this.btnCreate.Name = "btnCreate";
			this.btnCreate.Size = new System.Drawing.Size(75, 23);
			this.btnCreate.TabIndex = 7;
			this.btnCreate.Text = "Create";
			this.btnCreate.UseVisualStyleBackColor = true;
			this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
			// 
			// btnCancel
			// 
			this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnCancel.Location = new System.Drawing.Point(150, 227);
			this.btnCancel.Name = "btnCancel";
			this.btnCancel.Size = new System.Drawing.Size(75, 23);
			this.btnCancel.TabIndex = 8;
			this.btnCancel.Text = "Cancel";
			this.btnCancel.UseVisualStyleBackColor = true;
			// 
			// panelAlgorithmSettings
			// 
			this.panelAlgorithmSettings.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
									| System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.panelAlgorithmSettings.Location = new System.Drawing.Point(6, 25);
			this.panelAlgorithmSettings.Name = "panelAlgorithmSettings";
			this.panelAlgorithmSettings.Size = new System.Drawing.Size(202, 152);
			this.panelAlgorithmSettings.TabIndex = 1;
			// 
			// FormGenerate
			// 
			this.AcceptButton = this.btnCreate;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.CancelButton = this.btnCancel;
			this.ClientSize = new System.Drawing.Size(237, 262);
			this.Controls.Add(this.btnCancel);
			this.Controls.Add(this.btnCreate);
			this.Controls.Add(this.groupSettings);
			this.Controls.Add(this.numHeight);
			this.Controls.Add(this.numWidth);
			this.Controls.Add(label3);
			this.Controls.Add(label2);
			this.Name = "FormGenerate";
			this.Text = "FormGenerate";
			this.Load += new System.EventHandler(this.FormGenerate_Load);
			((System.ComponentModel.ISupportInitialize)(this.numWidth)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.numHeight)).EndInit();
			this.groupSettings.ResumeLayout(false);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ComboBox comboAlgorithm;
		private System.Windows.Forms.NumericUpDown numWidth;
		private System.Windows.Forms.NumericUpDown numHeight;
		private System.Windows.Forms.GroupBox groupSettings;
		private WinformsViewer.Generators.PanelGeneratorDepthFirst panelAlgorithmSettings;
		private System.Windows.Forms.Button btnCreate;
		private System.Windows.Forms.Button btnCancel;
	}
}