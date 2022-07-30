namespace PuzzleBox
{partial class game
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
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.originalImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Exit = new System.Windows.Forms.Button();
            this.restart = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.moves = new System.Windows.Forms.Label();
            this.time = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.onToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.colorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.tilesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.backgroundToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.onToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
			this.offToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.musicToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.onToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
			this.offToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
			// 
			// menuStrip1
			// 
			this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.optionsToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Padding = new System.Windows.Forms.Padding(4, 1, 0, 1);
			this.menuStrip1.Size = new System.Drawing.Size(685, 24);
			this.menuStrip1.TabIndex = 0;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// optionsToolStripMenuItem
			// 
			this.optionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.originalImageToolStripMenuItem,
			this.settingsToolStripMenuItem});
			this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
			this.optionsToolStripMenuItem.Size = new System.Drawing.Size(46, 22);
			this.optionsToolStripMenuItem.Text = "Tools";
			// 
			// originalImageToolStripMenuItem
			// 
			this.originalImageToolStripMenuItem.Name = "originalImageToolStripMenuItem";
			this.originalImageToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.originalImageToolStripMenuItem.Text = "Original image";
			this.originalImageToolStripMenuItem.Click += new System.EventHandler(this.originalImageToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this.settingsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.onToolStripMenuItem,
			this.musicToolStripMenuItem,
			this.colorsToolStripMenuItem});
			this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
			this.settingsToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.settingsToolStripMenuItem.Text = "Settings";
			// 
			// Exit
			// 
			this.Exit.BackColor = System.Drawing.Color.DarkRed;
            this.Exit.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.Exit.FlatAppearance.BorderSize = 2;
            this.Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Exit.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Exit.Location = new System.Drawing.Point(770, 582);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(160, 64);
            this.Exit.TabIndex = 2;
            this.Exit.Text = "EXIT";
            this.Exit.UseVisualStyleBackColor = false;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // restart
            // 
            this.restart.BackColor = System.Drawing.Color.White;
            this.restart.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.restart.FlatAppearance.BorderSize = 2;
            this.restart.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.restart.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.restart.Location = new System.Drawing.Point(770, 512);
            this.restart.Name = "restart";
            this.restart.Size = new System.Drawing.Size(160, 64);
            this.restart.TabIndex = 3;
            this.restart.Text = "RESTART";
            this.restart.UseVisualStyleBackColor = false;
            this.restart.Click += new System.EventHandler(this.restart_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.moves);
            this.panel1.Controls.Add(this.time);
            this.panel1.Location = new System.Drawing.Point(770, 96);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(159, 327);
            this.panel1.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label2.Location = new System.Drawing.Point(56, 179);
            this.label2.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 29);
            this.label2.TabIndex = 3;
            this.label2.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Location = new System.Drawing.Point(56, 60);
            this.label1.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "1";
            // 
            // moves
            // 
            this.moves.AutoSize = true;
            this.moves.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.moves.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.moves.Location = new System.Drawing.Point(47, 150);
            this.moves.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.moves.Name = "moves";
            this.time.Size = new System.Drawing.Size(47, 20);
            this.moves.TabIndex = 1;
            this.moves.Text = "MOVES";
            // 
            // time
            // 
            this.time.AutoSize = true;
            this.time.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.time.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.time.Location = new System.Drawing.Point(56, 30);
            this.time.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.time.Name = "time";
            this.time.Size = new System.Drawing.Size(47, 20);
            this.time.TabIndex = 0;
            this.time.Text = "TIME";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// onToolStripMenuItem
			// 
			this.onToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.onToolStripMenuItem1,
			this.offToolStripMenuItem});
			this.onToolStripMenuItem.Name = "onToolStripMenuItem";
			this.onToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.onToolStripMenuItem.Text = "Sound";
			// 
			// colorsToolStripMenuItem
			// 
			this.colorsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.tilesToolStripMenuItem,
			this.backgroundToolStripMenuItem});
			this.colorsToolStripMenuItem.Name = "colorsToolStripMenuItem";
			this.colorsToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.colorsToolStripMenuItem.Text = "Colors";
			// 
			// tilesToolStripMenuItem
			// 
			this.tilesToolStripMenuItem.Name = "tilesToolStripMenuItem";
			this.tilesToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.tilesToolStripMenuItem.Text = "Tiles";
			this.tilesToolStripMenuItem.Click += new System.EventHandler(this.tilesToolStripMenuItem_Click);
			// 
			// backgroundToolStripMenuItem
			// 
			this.backgroundToolStripMenuItem.Name = "backgroundToolStripMenuItem";
			this.backgroundToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.backgroundToolStripMenuItem.Text = "Background";
			this.backgroundToolStripMenuItem.Click += new System.EventHandler(this.backgroundToolStripMenuItem_Click);
			// 
			// onToolStripMenuItem1
			// 
			this.onToolStripMenuItem1.Name = "onToolStripMenuItem1";
			this.onToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
			this.onToolStripMenuItem1.Text = "On";
			this.onToolStripMenuItem1.Click += new System.EventHandler(this.onToolStripMenuItem1_Click);
			// 
			// offToolStripMenuItem
			// 
			this.offToolStripMenuItem.Name = "offToolStripMenuItem";
			this.offToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.offToolStripMenuItem.Text = "Off";
			this.offToolStripMenuItem.Click += new System.EventHandler(this.offToolStripMenuItem_Click);
			// 
			// musicToolStripMenuItem
			// 
			this.musicToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
			this.onToolStripMenuItem2,
			this.offToolStripMenuItem1});
			this.musicToolStripMenuItem.Name = "musicToolStripMenuItem";
			this.musicToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
			this.musicToolStripMenuItem.Text = "Music";
			// 
			// onToolStripMenuItem2
			// 
			this.onToolStripMenuItem2.Name = "onToolStripMenuItem2";
			this.onToolStripMenuItem2.Size = new System.Drawing.Size(180, 22);
			this.onToolStripMenuItem2.Text = "On";
			this.onToolStripMenuItem2.Click += new System.EventHandler(this.onToolStripMenuItem2_Click);
			// 
			// offToolStripMenuItem1
			// 
			this.offToolStripMenuItem1.Name = "offToolStripMenuItem1";
			this.offToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
			this.offToolStripMenuItem1.Text = "Off";
			this.offToolStripMenuItem1.Click += new System.EventHandler(this.offToolStripMenuItem1_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 729);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.restart);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.Text = "PuzzleBox";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem originalImageToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.Button restart;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label time;
        private System.Windows.Forms.Label moves;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.ToolStripMenuItem onToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem onToolStripMenuItem1;
		private System.Windows.Forms.ToolStripMenuItem offToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem colorsToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem tilesToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem backgroundToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem musicToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem onToolStripMenuItem2;
		private System.Windows.Forms.ToolStripMenuItem offToolStripMenuItem1;
	}
}

