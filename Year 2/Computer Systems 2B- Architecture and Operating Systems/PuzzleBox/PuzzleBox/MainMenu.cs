/*
 * Preslav Chonev - 180007405
 * Brandon Clark - 180009209
 * Tadas Saltenis - 180015959
 */


using PuzzleBox.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PuzzleBox
{
    public partial class MainMenu : Form
    {
        string format = "Number";
        public MainMenu()
        {
            InitializeComponent();
        }

        //This method is used to pick a random image and previously cut it into pieces, but then the cutting part was moved into the game constructor itself.
        public Image tiles(int gridSize)
        {

            //var imgarray = new Image[gridSize * gridSize];
            //int btnSize = 600 / gridSize;

            Random rnd = new Random();
            int randomNumber = rnd.Next(1, 3);

            System.Resources.ResourceManager rm = Resources.ResourceManager;
            var img = (Bitmap)rm.GetObject("game_Image" + randomNumber);
            
            /*
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    var index = i * gridSize + j;
                    imgarray[index] = new Bitmap(btnSize, btnSize);
                    var graphics = Graphics.FromImage(imgarray[index]);
                    graphics.DrawImage(img, new Rectangle(0, 0, btnSize, btnSize), new Rectangle(i * btnSize, j * btnSize, btnSize, btnSize), GraphicsUnit.Pixel);
                    graphics.Dispose();
                }
            }
            */
            return img;
        }

        // The Following buttons are all used.
        private void easyBtn_Click(object sender, EventArgs e)
        {
            //var imgs = new Image[16];
            var imgs = tiles(4);
            game easy = new game(4,imgs,this,format);
            easy.Show();
        }

        private void normalBtn_Click(object sender, EventArgs e)
        {
            var imgs = tiles(5);
            game normal = new game(5, imgs, this, format);
            normal.Show();
        }

        private void hardBtn_Click(object sender, EventArgs e)
        {
            var imgs = tiles(6);
            game hard = new game(6, imgs, this, format);
            hard.Show();
        }

        private void tutBtn_Click(object sender, EventArgs e)
        {
            var imgs = tiles(3);
            
            game tutorial = new game(imgs,this,format);
            this.Hide();
            tutorial.Show();
        }

        private void pictureRadio_CheckedChanged(object sender, EventArgs e)
        {
            format = "Picture";
        }

        private void numberRadio_CheckedChanged(object sender, EventArgs e)
        {
            format = "Number";
        }

        private void Tutorial_FormClosed(object sender, FormClosedEventArgs e)
        {
            throw new NotImplementedException();
        }

        private void ruleBtn_Click(object sender, EventArgs e)
        {
			MessageBox.Show("You move the tiles by clicking on them.\n\n" +
				"The goal of the game is to rearrange a grid of scrambled blocks to reveal the original image (which usually results in the empty block being in the bottom-right corner).\n\n" +
                "We recommend playing the tutorial to get the hang of it if you've never tried this before.", "Rules/How to play", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}


			private void customGrid_Click(object sender, EventArgs e)
        {
			Custom custom = new Custom(this,format);
			custom.Show();
		}

        private void highScoresBtn_Click(object sender, EventArgs e)
        {
            string easy="", normal = "", hard = "", output = "";
            string filepath = "highscores.txt";
            int count = 0;
            var info = new System.IO.FileInfo(filepath);
            if (info.Length == 0)
            {

            }
            else
            {
                //Reads in file into list of string arrays using a delimiter
                string[] lines = File.ReadAllLines(filepath);
                List<string[]> scorelist = new List<string[]>();
                for (int i = 0; i < lines.Length; i++)
                {
                    string[] line = new string[4];
                    line = lines[i].Split(',');
                    scorelist.Add(line);

                }

               
                // Add to easy
                for(int i = 0; i<scorelist.Count ; i++)
                {
                    if(count == 3)
                    {
                        break;
                    }
                    if(scorelist[i][1].Contains("Easy"))
                    {
                        for(int j = 0; j<4; j++)
                        {
                            easy += scorelist[i][j];
                            easy += " ";
                        }
                        easy += "\n";
                        count++;
                    }
                }

                count = 0;
                // Add to normal
                for (int i = 0; i < scorelist.Count ; i++)
                {
                    if (count == 3)
                    {
                        break;
                    }
                    if (scorelist[i][1].Contains("Normal"))
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            normal += scorelist[i][j];
                            normal += " ";
                        }
                        normal += "\n";
                        count++;
                    }
                }

                count = 0;
                // Add to Hard
                for (int i = 0; i < scorelist.Count ; i++)
                {
                    if (count == 3)
                    {
                        break;
                    }
                    if (scorelist[i][1].Contains("Hard"))
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            hard += scorelist[i][j];
                            hard += " ";
                        }
                        hard += "\n";
                        count++;
                    }
                }

                
                output = "Top scores\nName  Difficulty  Turns  Seconds  \n\nHard:\n" + hard + "\nNormal:\n" + normal + "\nEasy:\n" + easy;
                //outputs High score table in a message box
                MessageBox.Show(output,"High Scores");
                Console.WriteLine(output);

            }
        }

        private void creditsBtn_Click(object sender, EventArgs e)
        {
			MessageBox.Show("Gnome image - Puzzle box in OldSchool RuneScape by Jagex\n(https://oldschool.runescape.wiki/w/Puzzle_box)\n\n" +
				"Button moving sound effect - Title: Click, License: Attribution 3.0, Recorded by Mike Koenig\n(http://soundbible.com/783-Click.html)\n\n" +
				"Music - OldSchool RuneScape Soundtrack - Scape Main by Jagex", "Credits", MessageBoxButtons.OK, MessageBoxIcon.Information);
		}

        private void exitBtn_Click_1(object sender, EventArgs e)
        {
			this.Close();
		}
    }
}
