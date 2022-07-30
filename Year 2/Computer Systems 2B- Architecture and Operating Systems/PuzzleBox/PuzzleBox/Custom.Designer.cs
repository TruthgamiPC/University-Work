namespace PuzzleBox
{
    partial class Custom
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
            this.lblCustom = new System.Windows.Forms.Label();
            this.nudCustomMultiplier = new System.Windows.Forms.NumericUpDown();
            this.btnStartCustom = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.nudCustomMultiplier)).BeginInit();
            this.SuspendLayout();
            // 
            // lblCustom
            // 
            this.lblCustom.AutoSize = true;
            this.lblCustom.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCustom.Location = new System.Drawing.Point(22, 16);
            this.lblCustom.Margin = new System.Windows.Forms.Padding(0);
            this.lblCustom.Name = "lblCustom";
            this.lblCustom.Size = new System.Drawing.Size(190, 25);
            this.lblCustom.TabIndex = 0;
            this.lblCustom.Text = "Grid multiplier (? x ?)";
            // 
            // nudCustomMultiplier
            // 
            this.nudCustomMultiplier.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nudCustomMultiplier.Location = new System.Drawing.Point(96, 55);
            this.nudCustomMultiplier.Margin = new System.Windows.Forms.Padding(0);
            this.nudCustomMultiplier.Maximum = new decimal(new int[] {
            15,
            0,
            0,
            0});
            this.nudCustomMultiplier.Minimum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.nudCustomMultiplier.Name = "nudCustomMultiplier";
            this.nudCustomMultiplier.Size = new System.Drawing.Size(42, 30);
            this.nudCustomMultiplier.TabIndex = 1;
            this.nudCustomMultiplier.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // btnStartCustom
            // 
            this.btnStartCustom.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStartCustom.Location = new System.Drawing.Point(27, 102);
            this.btnStartCustom.Name = "btnStartCustom";
            this.btnStartCustom.Size = new System.Drawing.Size(185, 47);
            this.btnStartCustom.TabIndex = 2;
            this.btnStartCustom.Text = "Start";
            this.btnStartCustom.UseVisualStyleBackColor = true;
            this.btnStartCustom.Click += new System.EventHandler(this.btnStartCustom_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(142, 57);
            this.label1.Margin = new System.Windows.Forms.Padding(0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(83, 25);
            this.label1.TabIndex = 3;
            this.label1.Text = "Max: 15";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(9, 57);
            this.label2.Margin = new System.Windows.Forms.Padding(0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 25);
            this.label2.TabIndex = 4;
            this.label2.Text = "Min: 3";
            // 
            // Custom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(234, 161);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnStartCustom);
            this.Controls.Add(this.nudCustomMultiplier);
            this.Controls.Add(this.lblCustom);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Custom";
            this.Text = "Custom game";
            this.Load += new System.EventHandler(this.Custom_Load);
            ((System.ComponentModel.ISupportInitialize)(this.nudCustomMultiplier)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label lblCustom;
		private System.Windows.Forms.NumericUpDown nudCustomMultiplier;
		private System.Windows.Forms.Button btnStartCustom;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}