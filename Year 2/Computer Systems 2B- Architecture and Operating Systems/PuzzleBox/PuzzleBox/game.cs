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
using System.Media;
using System.IO;

namespace PuzzleBox
{
    public partial class game : Form
    {
        // array of buttons
        Button[,] btn;
        MainMenu temp;

		int gridSize;
		int emptyX;
        int emptyY;
        bool tutorial = false;
		bool sounds = true;
		bool music = true;
		string format;
		Image imgGlobal;

        // TUTORIAL
        public game(Image img, MainMenu t, string formatPass)
        {
			imgGlobal = img; // set the passed image to be global
            playMusic(); // doesn't work
            gridSize = 3; // ?x? board multiplier
            format = formatPass; // set passed format (numbers/pictures) to be global
            int btnSize = 600 / gridSize; // set the button size to be proportional to grid size
            temp = t; // main menu object for later use
            btn = new Button[gridSize, gridSize]; // create new array for buttons
            var imgarray = new Image[gridSize * gridSize]; // create new array for images to place on buttons

            // the initial empty tile X and Y coordinates
            emptyX = gridSize - 1;
            emptyY = gridSize - 1;

            InitializeComponent();

            //System.Resources.ResourceManager rm = Resources.ResourceManager;
            //var img = (Bitmap)rm.GetObject("game_Image" + randomNumber);


            for (int i = 0; i < gridSize; i++) // X
            {
                for (int j = 0; j < gridSize; j++) // Y
                {
                    btn[i, j] = new Button();
                    btn[i, j].Name = "gridBtn" + Convert.ToString(i) + "-" + Convert.ToString(j); // set ID for the buttons for later use
                    btn[i, j].TabStop = false; // remove the blue border on buttons
                    btn[i, j].SetBounds(btnSize * i + 78, btnSize * j + 78, btnSize, btnSize); //x, y coords; x, y size

                    // split image into tiles
                    var index = i * gridSize + j; 
                    imgarray[index] = new Bitmap(btnSize, btnSize);
                    var graphics = Graphics.FromImage(imgarray[index]);
                    graphics.DrawImage(img, new Rectangle(0, 0, btnSize, btnSize), new Rectangle(i * btnSize, j * btnSize, btnSize, btnSize), GraphicsUnit.Pixel);

                    // apply picture or color to the tile
                    graphics.Dispose();
                    if (format == "Picture")
                    {
                        btn[i, j].BackgroundImage = imgarray[i * gridSize + j];
                    } else
                    {
                        btn[i, j].BackColor = Color.DarkOrange; // color2
                    }

                    btn[i, j].Text = Convert.ToString(j * gridSize + i + 1); // add number text to the tile
                    btn[i, j].Click += new EventHandler(this.btnEvent_Click); // on click, call event handler
                    Controls.Add(btn[i, j]); // place button in window
                }
            }

            // assistance for tutorial
            Button tips = new Button();
            tips.Name = "assistance_button";
            tips.TabStop = false;
            tips.SetBounds(770, 512, 160, 64);
            tips.BackColor = Color.White;
            tips.Text = "Tutorial moves";
            tips.Click += new EventHandler(this.assistanceButton_Click);
            Controls.Add(tips);

            restart.Hide();
            btn[emptyX, emptyY].Visible = false;

            tutorialBuild();
            //checkInversions();
        }

        public game(int size, Image img, MainMenu t,string formatPass)
        {
			imgGlobal = img;
			playMusic();
            format = formatPass;
            gridSize = size;
            temp = t;
            int btnSize = 600 / gridSize;
            btn = new Button[gridSize, gridSize];
            emptyX = gridSize - 1;
            emptyY = gridSize - 1;
            var imgarray = new Image[gridSize * gridSize];
            InitializeComponent();

            for (int i = 0; i < gridSize; i++) // X
            {
                for (int j = 0; j < gridSize; j++) // Y
                {
                    btn[i, j] = new Button();
                    btn[i, j].Name = "gridBtn" + Convert.ToString(i) + "-" + Convert.ToString(j);
                    btn[i, j].TabStop = false; // remove the blue border on buttons
                    btn[i, j].SetBounds(btnSize * i + 78, btnSize * j + 78, btnSize, btnSize); //x, y coords; x, y size

                    var index = i * gridSize + j;
                    imgarray[index] = new Bitmap(btnSize, btnSize);
                    var graphics = Graphics.FromImage(imgarray[index]);
                    graphics.DrawImage(img, new Rectangle(0, 0, btnSize, btnSize), new Rectangle(i * btnSize, j * btnSize, btnSize, btnSize), GraphicsUnit.Pixel);


                    if (format == "Picture")
                    {
                        btn[i, j].BackgroundImage = imgarray[i * gridSize + j];
                    }
                    else
                    {
                        btn[i, j].BackColor = Color.DarkOrange; // color2
                    }
                    btn[i, j].Text = Convert.ToString(j * gridSize + i + 1);
                    btn[i, j].Click += new EventHandler(this.btnEvent_Click); // on click, call event handler
                    Controls.Add(btn[i, j]); // place button in window
                }
            }
            btn[emptyX, emptyY].Visible = false;
            //tutorialBuild();
            checkInversions();
        }


        //Music Scratched
        void playMusic()
		{
			if (music)
			{
				try
				{
					SoundPlayer splayer = new SoundPlayer(@"..\\..\\Resources\\bgmusic.wav");
					splayer.PlayLooping();
				}
				catch (FileNotFoundException error)
				{
					Console.WriteLine("ERROR: " + Convert.ToString(error));
				}
			}
		}

        void tutorialBuild()
        {
            // 8 5 6 8 5 7 4
            clickMove(-1, 0); // move 8
            clickMove(0, -1); // move 5
            clickMove(1, 0);  // move 6
            clickMove(0, 1);  // move 8
            clickMove(-1, 0); // move 5
            clickMove(-1, 0); // move 7
            clickMove(0, -1); // move 4

            label2.Text = "0";
            // FORMAT IS SET AS:
            // 1 - 2 - 3
            // 0 - 6 - 8
            // 4 - 7 - 5

            //Previously also used for testing purposes.
        }

        void assistanceButton_Click(object sender, EventArgs e)
        {
            AssistanceForm tutorialF = new AssistanceForm();
            tutorialF.Show();
        }

        void checkInversions()
        {
            int inversions, counter = 0;
            bool solvable = false;
            do
            {
                scrambleTiles();
                List<string> items = new List<string>();
                for (int i = 0; i < gridSize; i++)
                {
                    for (int j = 0; j < gridSize; j++)
                    {

                        if (btn[i, j].Text != (Math.Pow(gridSize, 2)).ToString())
                        {
                            items.Add(btn[i, j].Text);
                        }

                    }
                }

                inversions = 0;
                for (int i = 0; i < items.Count; i++)
                {
                    Console.WriteLine(items[i]);
                    for (int j = i; j < items.Count; j++)
                    {
                        if (Int32.Parse(items[i]) > Int32.Parse(items[j]))
                        {
                            inversions++;
                        }
                    }
                }
                counter++;
                if(((gridSize % 2 != 0 && inversions % 2 == 0) || (gridSize % 2 == 0 && (((gridSize - emptyY) % 2 == 0 && inversions % 2 != 0) || ((gridSize - emptyY) % 2 != 0 && inversions % 2 == 0)))))
                {
                    solvable = true;
                }
                Console.WriteLine("Shuffled " + counter + " times with " + inversions + " inversions");
            } while (!solvable);
            //while (inversions % 2 == 0);
        }

        // tile switching event handler
        void btnEvent_Click(object sender, EventArgs e)
        {
            if ((Button)sender == btn[emptyX, emptyY])
            {
                return;
            }
            if (emptyX > 0)
            {
                if (btn[emptyX - 1, emptyY] == (Button)sender)
                {
                    clickMove(-1, 0);
                    return;
                }
            }
            if (emptyX+1 < gridSize)
            {
                if (btn[emptyX + 1, emptyY] == (Button)sender)
                {
                    clickMove(1, 0);
                    return;
                }
            }
            if (emptyY > 0)
            {
                if (btn[emptyX, emptyY - 1] == (Button)sender)
                {
                    clickMove(0, -1);
                    return;
                }
            }
            if (emptyY+1 < gridSize)
            {
                if (btn[emptyX, emptyY + 1] == (Button)sender)
                {
                    clickMove(0, 1);
                    return;
                }
            }
        }

        void clickMove(int x, int y)
        {
            btn[emptyX + x, emptyY + y].Visible = false;
            
            String tmpText = btn[emptyX + x, emptyY + y].Text;
            String tmpName = btn[emptyX + x, emptyY + y].Name;
            Image tmpImg = btn[emptyX + x, emptyY + y].BackgroundImage;

            btn[emptyX + x, emptyY + y].Text = btn[emptyX, emptyY].Text;
            btn[emptyX + x, emptyY + y].Name = btn[emptyX, emptyY].Name;

            btn[emptyX, emptyY].BackgroundImage = tmpImg;
            btn[emptyX, emptyY].Text = tmpText;
            btn[emptyX, emptyY].Name = tmpName;

			Random rnd = new Random();
            if(sounds)
			{
				try
				{
					int rndSound = rnd.Next(1, 4);
					SoundPlayer splayer = new SoundPlayer(@"..\\..\\Resources\\TileMove" + Convert.ToString(rndSound) + ".wav");
					splayer.Play();
				}
				catch (FileNotFoundException error)
				{
					Console.WriteLine("ERROR: " + Convert.ToString(error));
				}
			}

            btn[emptyX, emptyY].Visible = true;

            emptyX += x;
            emptyY += y;
            int temp = Int32.Parse(label2.Text);
            temp += 1;
            label2.Text = temp.ToString();
            winCheck();
        }

        void scrambleTiles()
        {
            Random rnd = new Random();
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    int x = rnd.Next(gridSize);
                    int y = rnd.Next(gridSize);

                    if (btn[i, j].Name == btn[emptyX, emptyY].Name)
                    {
                        btn[i, j].Visible = true;
                        btn[x, y].Visible = false;
                        emptyX = x;
                        emptyY = y;
                    }
                    else if (btn[x, y].Name == btn[emptyX, emptyY].Name)
                    {
                        btn[i, j].Visible = false;
                        btn[x, y].Visible = true;
                        emptyX = i;
                        emptyY = j;
                    }

                    String tmpText = btn[i, j].Text;
                    String tmpName = btn[i, j].Name;
                    Image tmpImg = btn[i,j].BackgroundImage;

                    btn[i, j].Text = btn[x, y].Text;
                    btn[i, j].Name = btn[x, y].Name;
                    btn[i, j].BackgroundImage = btn[x, y].BackgroundImage;

                    btn[x, y].Text = tmpText;
                    btn[x, y].Name = tmpName;
                    btn[x, y].BackgroundImage = tmpImg;
                }
            }
        }

        void winCheck()
        {
            //Console.WriteLine(btn[gridSize - 1, gridSize - 1].Name);
			if (btn[gridSize - 1, gridSize - 1].Name == "gridBtn" + Convert.ToString(gridSize-1) + "-" + Convert.ToString(gridSize-1))
			{
                for (int i = 0; i < gridSize; i++)
                {
                    for (int j = 0; j < gridSize; j++)
                    {
                        // Console.Write(btn[i, j].Name);
                        if (btn[i, j].Name != "gridBtn" + Convert.ToString(i) + "-" + Convert.ToString(j))
                        {
                            return;
                        }
                    }
                }
                Console.WriteLine("WIN");
                int turns = Int32.Parse(label2.Text);
                int time = Int32.Parse(label1.Text);
                PopupForm victory;
                victory = new PopupForm(this, temp, gridSize, turns, time);
                victory.Show();
                               
                //temp.Show(); // display win (call another window?)
               // this.Close();
			}
        }
     
   
        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

		private void restart_Click(object sender, EventArgs e)
		{
			checkInversions();
            label1.Text = "0";
            label2.Text = "0";
		}

		private void Exit_Click(object sender, EventArgs e)
		{
			temp.Show();
			Close();
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			int temp = Int32.Parse(label1.Text);
			temp += 1;
			label1.Text = temp.ToString();
		}
		// ============================== MENU STRIP ==============================

		private void originalImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(format == "Picture")
			{
				originalImage originalImg = new originalImage(imgGlobal);
				originalImg.Show();
			}
        }

        private void settingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

		private void onToolStripMenuItem1_Click(object sender, EventArgs e)
		{
			sounds = true;
		}
		private void offToolStripMenuItem_Click(object sender, EventArgs e)
		{
			sounds = false;
		}
		private void onToolStripMenuItem2_Click(object sender, EventArgs e)
		{
            if(!music)
            {
                music = true;
                playMusic();
            }
        }
		private void offToolStripMenuItem1_Click(object sender, EventArgs e)
		{
			music = false;

		}

		private void tilesToolStripMenuItem_Click(object sender, EventArgs e)
		{
			// example from
			// https://docs.microsoft.com/en-us/dotnet/framework/winforms/controls/how-to-show-a-color-palette-with-the-colordialog-component
			ColorDialog clrDial = new ColorDialog();
			if (clrDial.ShowDialog() == DialogResult.OK)
			{
				for (int i = 0; i < gridSize; i++)
				{
					for (int j = 0; j < gridSize; j++)
					{
                        if(format=="Number")
						{
							btn[i, j].BackColor = clrDial.Color;
						}
                        else if(format=="Picture")
						{
							btn[i, j].ForeColor = clrDial.Color;
						}
					}
				}
			}
		}

		private void backgroundToolStripMenuItem_Click(object sender, EventArgs e)
		{
			// example from
			// https://docs.microsoft.com/en-us/dotnet/framework/winforms/controls/how-to-show-a-color-palette-with-the-colordialog-component
			ColorDialog clrDial = new ColorDialog();
			if (clrDial.ShowDialog() == DialogResult.OK)
			{
				this.BackColor = clrDial.Color;
			}
		}
	}
}
