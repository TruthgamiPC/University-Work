namespace PuzzleBox
{
    partial class AssistanceForm
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
        //private void InitializeComponent()
        //{
        //    this.components = new System.ComponentModel.Container();
        //    this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        //    this.ClientSize = new System.Drawing.Size(800, 450);
        //    this.Text = "assistanceFormcs";
        //}

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AssistanceForm));
            this.label1 = new System.Windows.Forms.Label();
            this.Exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(21, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(322, 168);
            this.label1.TabIndex = 0;
            this.label1.Text = "1. Press on 4 to move it to the top.\n2. Press on 7 to move it to the left.\n3. Press on 5 to move it to the left.\n4. Press on 8 to move it to the bottom.\n5. Press on 6 to move it to the right.\n6. Press on 5 to move it ot the top.\n7. Press on 8 to move it to the right.";
                
                //resources.GetString("label1.Text");
            // 
            // Exit
            // 
            this.Exit.BackColor = System.Drawing.Color.DarkRed;
            this.Exit.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.Exit.FlatAppearance.BorderSize = 2;
            this.Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Exit.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Exit.Location = new System.Drawing.Point(103, 211);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(160, 64);
            this.Exit.TabIndex = 3;
            this.Exit.Text = "EXIT";
            this.Exit.UseVisualStyleBackColor = false;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // AssistanceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(364, 287);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.label1);
            this.Name = "AssistanceForm";
            this.Text = "Tutorial";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Exit;
    }
}