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
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PuzzleBox
{
    public partial class PopupForm : Form
    {
		//Instances of parent & grandparent forms
		game game;
		MainMenu menu;
		String difficulty;
		int no_Moves, seconds;

		public PopupForm(game f, MainMenu m, int mode, int moves, int time)
		{
			InitializeComponent();

			//setting variables using parameters
			game = f;
			menu = m;
			no_Moves = moves;
			seconds = time;

			//Setting difficulty string using mode parameter
			switch (mode)
			{
				case 3:
					difficulty = "Tutorial";
					break;
				case 4:
					difficulty = "Easy";
					break;
				case 5:
					difficulty = "Normal";
					break;
				case 6:
					difficulty = "Hard";
					break;
				default:
					difficulty = "Custom";
					break;
			}
		}

		private void submitBtn_Click(object sender, EventArgs e)
		{
			string filepath = "highscores.txt";
			var info = new System.IO.FileInfo(filepath);

			//Checks if file is empty
			if (info.Length == 0)
            {

            }
            else
            {
                if(nameTxtBox.Text == "")
				{
					MessageBox.Show("No empty names allowed!", "", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);

				}
				else if(difficulty == "Custom" || difficulty == "Tutorial")
                {
					
					menu.Show();
					game.Close();
					this.Close();
                }
				else
				{
					// Reads file line by line into a string array
					string[] lines = File.ReadAllLines(filepath);

					
					List<string[]> scorelist = new List<string[]>();

					//delimits strings into arrays and puts said arrays into a list
					for (int i = 0; i < lines.Length; i++)
					{
						string[] line = new string[4];
						line = lines[i].Split(',');
						scorelist.Add(line);
					}


					//Adds new score
					string[] lineToAdd = new string[4];
					lineToAdd[0] = nameTxtBox.Text;
					lineToAdd[1] = difficulty;
					lineToAdd[2] = no_Moves.ToString();
					lineToAdd[3] = seconds.ToString();

					scorelist.Add(lineToAdd);



                    //test Print  function
                    /*foreach (string[] viewlines in scorelist)
					{
						foreach (string viewline in viewlines)
						{
							Console.Write(viewline + " ");
						}
						Console.WriteLine();
					}*/


                    int listLen = scorelist.Count;
					listLen--;

					//Sorts list by number of turns and then by time
					for (int i = 0; i < listLen; i++)
					{
						bool swapped = false;

						for (int j = 0; j < listLen; j++)
						{
							string[] temp;
							try
							{
								if (Int32.Parse(scorelist[j][2]) > Int32.Parse(scorelist[j + 1][2]))
								{
									temp = scorelist[j + 1];
									scorelist[j + 1] = scorelist[j];
									scorelist[j] = temp;
									swapped = true;
								}
								else if (Int32.Parse(scorelist[j][2]) == Int32.Parse(scorelist[j + 1][2]))
								{
									if (Int32.Parse(scorelist[j][3]) > Int32.Parse(scorelist[j + 1][3]))
									{
										temp = scorelist[j + 1];
										scorelist[j + 1] = scorelist[j];
										scorelist[j] = temp;
										swapped = true;
									}
									else
									{
										continue;
									}
								}
							}
							catch (System.IndexOutOfRangeException error)
							{
								Console.WriteLine(error + " at index " + j);
								//Console.WriteLine(scorelist[j][2]);
								game.Close();
								menu.Show();
								this.Close();
							}
						}

						if (!swapped)
						{
							break;
						}
					}

					List<string> linesToWrite = new List<string>();


					//COnverts string arrays back into strings in a list
					for (int i = 0; i < scorelist.Count; i++)
					{
						string line = "";
						for (int j = 0; j < 4; j++)
						{
							if (j != 3)
							{
								try
								{
									line += (scorelist[i][j] += (','));
								}
								catch (System.IndexOutOfRangeException b)
								{
									Console.WriteLine(b + " on index i: " + i + " and j: " + j);
								}
							}
							else
							{
								try
								{
									line += (scorelist[i][j]);
								}
								catch (System.IndexOutOfRangeException b)
								{
									Console.WriteLine(b + " on index i: " + i + " and j: " + j);
								}
							}
						}
						linesToWrite.Add(line.ToString());
					}


					//Writes list to file line by line
					System.IO.File.WriteAllLines("highscores.txt", linesToWrite.ToArray().Reverse());


					game.Close();
					menu.Show();
					this.Close();
				}
            }
        }

        private void PopupForm_Load(object sender, EventArgs e)
        {
            InfoLbl.Text = "You won on " + difficulty + " difficulty in " + no_Moves.ToString() + " moves and in " + seconds + " seconds";
        }
    }
}
