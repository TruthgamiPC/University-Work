namespace PuzzleBox
{
    partial class PopupForm
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
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.nameTxtBox = new System.Windows.Forms.TextBox();
            this.submitBtn = new System.Windows.Forms.Button();
            this.InfoLbl = new System.Windows.Forms.Label();
            this.instructionLbl = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // nameTxtBox
            // 
            this.nameTxtBox.Location = new System.Drawing.Point(236, 178);
            this.nameTxtBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.nameTxtBox.MaxLength = 16;
            this.nameTxtBox.Name = "nameTxtBox";
            this.nameTxtBox.Size = new System.Drawing.Size(119, 20);
            this.nameTxtBox.TabIndex = 0;
            this.nameTxtBox.Text = "John Smith";
            // 
            // submitBtn
            // 
            this.submitBtn.Location = new System.Drawing.Point(236, 213);
            this.submitBtn.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.submitBtn.Name = "submitBtn";
            this.submitBtn.Size = new System.Drawing.Size(118, 25);
            this.submitBtn.TabIndex = 1;
            this.submitBtn.Text = "Submit";
            this.submitBtn.UseVisualStyleBackColor = true;
            this.submitBtn.Click += new System.EventHandler(this.submitBtn_Click);
            // 
            // InfoLbl
            // 
            this.InfoLbl.AutoSize = true;
            this.InfoLbl.Location = new System.Drawing.Point(40, 37);
            this.InfoLbl.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.InfoLbl.Name = "InfoLbl";
            this.InfoLbl.Size = new System.Drawing.Size(0, 13);
            this.InfoLbl.TabIndex = 2;
            // 
            // instructionLbl
            // 
            this.instructionLbl.AutoSize = true;
            this.instructionLbl.Location = new System.Drawing.Point(242, 155);
            this.instructionLbl.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.instructionLbl.Name = "instructionLbl";
            this.instructionLbl.Size = new System.Drawing.Size(87, 13);
            this.instructionLbl.TabIndex = 3;
            this.instructionLbl.Text = "Enter your name!";
            // 
            // PopupForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(605, 346);
            this.Controls.Add(this.instructionLbl);
            this.Controls.Add(this.InfoLbl);
            this.Controls.Add(this.submitBtn);
            this.Controls.Add(this.nameTxtBox);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "PopupForm";
            this.Text = "Popup";
            this.Load += new System.EventHandler(this.PopupForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.TextBox nameTxtBox;
        private System.Windows.Forms.Button submitBtn;
        private System.Windows.Forms.Label InfoLbl;
        private System.Windows.Forms.Label instructionLbl;
    }
}