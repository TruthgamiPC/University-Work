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
    public partial class originalImage : Form
    {
        public originalImage(Image img)
        {
            InitializeComponent();
			this.BackgroundImage = img;
			this.Size = new Size(606, 630);

        }
    }
}
