using System;
namespace PuzzleBox
{
    partial class MainMenu
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
            this.TitleLbl = new System.Windows.Forms.Label();
            this.tutBtn = new System.Windows.Forms.Button();
            this.normalBtn = new System.Windows.Forms.Button();
            this.hardBtn = new System.Windows.Forms.Button();
            this.easyBtn = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.modeLbl = new System.Windows.Forms.Label();
            this.numberRadio = new System.Windows.Forms.RadioButton();
            this.pictureRadio = new System.Windows.Forms.RadioButton();
            this.highScoresBtn = new System.Windows.Forms.Button();
            this.ruleBtn = new System.Windows.Forms.Button();
            this.customGrid = new System.Windows.Forms.Button();
            this.creditsBtn = new System.Windows.Forms.Button();
            this.exitBtn = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // TitleLbl
            // 
            this.TitleLbl.AutoSize = true;
            this.TitleLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 55F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TitleLbl.Location = new System.Drawing.Point(313, 36);
            this.TitleLbl.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.TitleLbl.Name = "TitleLbl";
            this.TitleLbl.Size = new System.Drawing.Size(398, 85);
            this.TitleLbl.TabIndex = 0;
            this.TitleLbl.Text = "Puzzle Box";
            // 
            // tutBtn
            // 
            this.tutBtn.Location = new System.Drawing.Point(393, 157);
            this.tutBtn.Margin = new System.Windows.Forms.Padding(2);
            this.tutBtn.Name = "tutBtn";
            this.tutBtn.Size = new System.Drawing.Size(238, 48);
            this.tutBtn.TabIndex = 1;
            this.tutBtn.Text = "Tutorial";
            this.tutBtn.UseVisualStyleBackColor = true;
            this.tutBtn.Click += new System.EventHandler(this.tutBtn_Click);
            // 
            // normalBtn
            // 
            this.normalBtn.Location = new System.Drawing.Point(533, 241);
            this.normalBtn.Margin = new System.Windows.Forms.Padding(2);
            this.normalBtn.Name = "normalBtn";
            this.normalBtn.Size = new System.Drawing.Size(135, 48);
            this.normalBtn.TabIndex = 2;
            this.normalBtn.Text = "Normal";
            this.normalBtn.UseVisualStyleBackColor = true;
            this.normalBtn.Click += new System.EventHandler(this.normalBtn_Click);
            // 
            // hardBtn
            // 
            this.hardBtn.Location = new System.Drawing.Point(356, 241);
            this.hardBtn.Margin = new System.Windows.Forms.Padding(2);
            this.hardBtn.Name = "hardBtn";
            this.hardBtn.Size = new System.Drawing.Size(135, 48);
            this.hardBtn.TabIndex = 3;
            this.hardBtn.Text = "Hard";
            this.hardBtn.UseVisualStyleBackColor = true;
            this.hardBtn.Click += new System.EventHandler(this.hardBtn_Click);
            // 
            // easyBtn
            // 
            this.easyBtn.Location = new System.Drawing.Point(179, 241);
            this.easyBtn.Margin = new System.Windows.Forms.Padding(2);
            this.easyBtn.Name = "easyBtn";
            this.easyBtn.Size = new System.Drawing.Size(135, 48);
            this.easyBtn.TabIndex = 4;
            this.easyBtn.Text = "Easy";
            this.easyBtn.UseVisualStyleBackColor = true;
            this.easyBtn.Click += new System.EventHandler(this.easyBtn_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ControlDark;
            this.panel1.Controls.Add(this.modeLbl);
            this.panel1.Controls.Add(this.numberRadio);
            this.panel1.Controls.Add(this.pictureRadio);
            this.panel1.Location = new System.Drawing.Point(274, 325);
            this.panel1.Margin = new System.Windows.Forms.Padding(2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(475, 64);
            this.panel1.TabIndex = 5;
            // 
            // modeLbl
            // 
            this.modeLbl.AutoSize = true;
            this.modeLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.modeLbl.Location = new System.Drawing.Point(14, 20);
            this.modeLbl.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.modeLbl.Name = "modeLbl";
            this.modeLbl.Size = new System.Drawing.Size(81, 29);
            this.modeLbl.TabIndex = 2;
            this.modeLbl.Text = "Mode:";
            // 
            // numberRadio
            // 
            this.numberRadio.AutoSize = true;
            this.numberRadio.Checked = true;
            this.numberRadio.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numberRadio.Location = new System.Drawing.Point(143, 18);
            this.numberRadio.Margin = new System.Windows.Forms.Padding(2);
            this.numberRadio.Name = "numberRadio";
            this.numberRadio.Size = new System.Drawing.Size(130, 33);
            this.numberRadio.TabIndex = 1;
            this.numberRadio.TabStop = true;
            this.numberRadio.Text = "Numbers";
            this.numberRadio.UseVisualStyleBackColor = true;
            this.numberRadio.CheckedChanged += new System.EventHandler(this.numberRadio_CheckedChanged);
            // 
            // pictureRadio
            // 
            this.pictureRadio.AutoSize = true;
            this.pictureRadio.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pictureRadio.Location = new System.Drawing.Point(334, 18);
            this.pictureRadio.Margin = new System.Windows.Forms.Padding(2);
            this.pictureRadio.Name = "pictureRadio";
            this.pictureRadio.Size = new System.Drawing.Size(118, 33);
            this.pictureRadio.TabIndex = 0;
            this.pictureRadio.Text = "Pictures";
            this.pictureRadio.UseVisualStyleBackColor = true;
            this.pictureRadio.CheckedChanged += new System.EventHandler(this.pictureRadio_CheckedChanged);
            // 
            // highScoresBtn
            // 
            this.highScoresBtn.Location = new System.Drawing.Point(179, 425);
            this.highScoresBtn.Margin = new System.Windows.Forms.Padding(2);
            this.highScoresBtn.Name = "highScoresBtn";
            this.highScoresBtn.Size = new System.Drawing.Size(190, 48);
            this.highScoresBtn.TabIndex = 6;
            this.highScoresBtn.Text = "High Scores";
            this.highScoresBtn.UseVisualStyleBackColor = true;
            this.highScoresBtn.Click += new System.EventHandler(this.highScoresBtn_Click);
            // 
            // ruleBtn
            // 
            this.ruleBtn.Location = new System.Drawing.Point(417, 425);
            this.ruleBtn.Margin = new System.Windows.Forms.Padding(2);
            this.ruleBtn.Name = "ruleBtn";
            this.ruleBtn.Size = new System.Drawing.Size(190, 48);
            this.ruleBtn.TabIndex = 7;
            this.ruleBtn.Text = "Rules";
            this.ruleBtn.UseVisualStyleBackColor = true;
            this.ruleBtn.Click += new System.EventHandler(this.ruleBtn_Click);
            // 
            // customGrid
            // 
            this.customGrid.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.customGrid.Location = new System.Drawing.Point(710, 241);
            this.customGrid.Name = "customGrid";
            this.customGrid.Size = new System.Drawing.Size(135, 48);
            this.customGrid.TabIndex = 9;
            this.customGrid.Text = "Custom";
            this.customGrid.UseVisualStyleBackColor = true;
            this.customGrid.Click += new System.EventHandler(this.customGrid_Click);
            // 
            // creditsBtn
            // 
            this.creditsBtn.Location = new System.Drawing.Point(655, 425);
            this.creditsBtn.Margin = new System.Windows.Forms.Padding(2);
            this.creditsBtn.Name = "creditsBtn";
            this.creditsBtn.Size = new System.Drawing.Size(190, 48);
            this.creditsBtn.TabIndex = 11;
            this.creditsBtn.Text = "Credits";
            this.creditsBtn.UseVisualStyleBackColor = true;
            this.creditsBtn.Click += new System.EventHandler(this.creditsBtn_Click);
            // 
            // exitBtn
            // 
            this.exitBtn.BackColor = System.Drawing.Color.DarkRed;
            this.exitBtn.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.exitBtn.FlatAppearance.BorderSize = 2;
            this.exitBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitBtn.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.exitBtn.Location = new System.Drawing.Point(393, 536);
            this.exitBtn.Name = "exitBtn";
            this.exitBtn.Size = new System.Drawing.Size(240, 61);
            this.exitBtn.TabIndex = 12;
            this.exitBtn.Text = "EXIT";
            this.exitBtn.UseVisualStyleBackColor = false;
            this.exitBtn.Click += new System.EventHandler(this.exitBtn_Click_1);
            // 
            // MainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 690);
            this.Controls.Add(this.exitBtn);
            this.Controls.Add(this.creditsBtn);
            this.Controls.Add(this.customGrid);
            this.Controls.Add(this.TitleLbl);
            this.Controls.Add(this.ruleBtn);
            this.Controls.Add(this.highScoresBtn);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.easyBtn);
            this.Controls.Add(this.hardBtn);
            this.Controls.Add(this.normalBtn);
            this.Controls.Add(this.tutBtn);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "MainMenu";
            this.Text = "Puzzle Box";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label TitleLbl;
        private System.Windows.Forms.Button tutBtn;
        private System.Windows.Forms.Button normalBtn;
        private System.Windows.Forms.Button hardBtn;
        private System.Windows.Forms.Button easyBtn;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label modeLbl;
        private System.Windows.Forms.RadioButton numberRadio;
        private System.Windows.Forms.RadioButton pictureRadio;
        private System.Windows.Forms.Button highScoresBtn;
        private System.Windows.Forms.Button ruleBtn;
        private System.Windows.Forms.Button customGrid;
        private System.Windows.Forms.Button creditsBtn;
        private System.Windows.Forms.Button exitBtn;
    }
}