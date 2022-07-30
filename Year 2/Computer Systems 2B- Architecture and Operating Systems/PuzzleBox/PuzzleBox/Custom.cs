/*
 * Preslav Chonev - 180007405
 * Brandon Clark - 180009209
 * Tadas Saltenis - 180015959
 */


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PuzzleBox
{
    public partial class Custom : Form
    {
		MainMenu temp;
        string format;

		public Custom(MainMenu m,String form)
		{
			InitializeComponent();
			temp = m;
            format = form;
		}

		private void Custom_Load(object sender, EventArgs e)
		{

		}

		private void btnStartCustom_Click(object sender, EventArgs e)
		{
			int customSize = Convert.ToInt32(nudCustomMultiplier.Value);
			this.Hide();
			game customGame = new game(customSize, temp.tiles(customSize), temp,format);
			customGame.Show();
		}

		private void label1_Click(object sender, EventArgs e)
		{

		}
	}
}
