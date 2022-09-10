#include <iostream>
#include "Patterns.cpp"
#include <string>
#include <array>
#include<vector>
#include <unistd.h>
// #include "main.cpp"
using namespace std;

void Arrayprinter(int Y , int X , pattern** b )
{
for(int i = 0; i < Y-1; ++i)
  {
     for(int j = 0; j < X; ++j)
    {
      cout <<b[i][j].patternval << " ";
    }
        cout << endl;
  }
  cout << "\n" << endl;
}

pattern** ArrayAllocater(int Y , int X , pattern** a )
{
    a = new pattern*[Y];
    for(int i = 0; i < Y; ++i)
        a[i] = new pattern[X];
 
  // fill
  for(int i = 0; i < Y; ++i){
    for(int j = 0; j < X; ++j){
        int randomNum = rand() % 2;
        if(randomNum == 1){
            a[i][j].patternval = "■";
            a[i][j].binValue = 1;
        }else{
            a[i][j].patternval = "□";
            a[i][j].binValue = 0;
        }
    }
  }
return a;
}

void converter(int Y, int X, pattern** a)
{
    int neighbour = 0;

    //for every cell
    for(int i = 0; i < Y-1; ++i)
    {
        for(int j = 0; j < X; j++)
        {
            neighbour = 0;
            //for the top left corner
            if(i==0&&j==0)
            {
                //left
                if(a[i][X-1].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;

                //up left
                if(a[Y-2][X-1].binValue==1) neighbour++;

                //up
                if(a[Y-2][j].binValue==1) neighbour++;

                //up right
                if(a[Y-2][j+1].binValue==1) neighbour++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down right
                if(a[i+1][j+1].binValue==1) neighbour++;        
            }
            
            //for the top right corner
            if(i==0&&j==X-1)
            {
                //left
                if(a[i][j-1].binValue==1) neighbour++;

                //right
                if(a[i][0].binValue==1) neighbour++;
                
                //up left
                if(a[Y-2][j-1].binValue==1) neighbour++;

                //up
                if(a[Y-2][j].binValue==1) neighbour++;

                //up right
                if(a[Y-2][0].binValue==1) neighbour++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down right
                if(a[i+1][0].binValue==1) neighbour++;        
            }
            
            //for the bottom left corner
            if(i==Y-2&&j==0)
            {
                //left
                if(a[Y-2][j].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;
                
                //up left
                if(a[i+1][j+1].binValue==1) neighbour++;

                //up
                if(a[i+1][j].binValue==1) neighbour++;

                //up right
                if(a[i+1][j+1].binValue==1) neighbour++;

                //down left
                if(a[0][X-1].binValue==1) neighbour++;

                //down
                if(a[0][j].binValue==1) neighbour++;

                //down right
                if(a[0][j+1].binValue==1) neighbour++;        
            }
            
            //for the bottom right
            if(i==Y-2&&j==X-1)
            {
                //up left
                if(a[i+1][j+1].binValue==1) neighbour++;

                //up
                if(a[i+1][j].binValue==1) neighbour++;

                //up right
                if(a[i+1][0].binValue==1) neighbour++;

                //left
                if(a[i][j+1].binValue==1) neighbour++;

                //right
                if(a[i][0].binValue==1) neighbour++;

                //down left
                if(a[0][j+1].binValue==1) neighbour++;

                //down
                if(a[0][j].binValue==1) neighbour++;

                //down right
                if(a[0][0].binValue==1) neighbour++;
            }
            
            //when i is 0 but j isn't 0 (i.e the top row but not a corner)
            if(i==0&&j!=0&&j!=X-1)
            {
                //left
                if(a[i][j-1].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;
                
                //up left
                if(a[Y-2][j-1].binValue==1) neighbour++;

                //up
                if(a[Y-1][j].binValue==1) neighbour++;

                //up right
                if(a[Y-1][j+1].binValue==1) neighbour++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down right
                if(a[i+1][j+1].binValue==1) neighbour++;       
            }
            
            //when j is 0 but i isnt 0 (i.e the left but not a corner)
            if(j==0&&i!=0&&i!=Y-2)
            {
                //down right
                if(a[i+1][j+1].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;

                //left
                if(a[i][X-1].binValue==1) neighbour++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour++;

                //up
                if(a[i-1][j].binValue==1) neighbour++;

                //up left
                if(a[i-1][X-1].binValue==1) neighbour++;       
            }
            
            //when j is X-1 (the last row) but (i.e the right but not a corner)
            if(j==X-1&&i!=0&&i!=Y-2)
            {
                //down right
                if(a[i+1][0].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour++;

                //right
                if(a[i][0].binValue==1) neighbour++;

                //left
                if(a[i][j-1].binValue==1) neighbour++;

                //up right
                if(a[i-1][0].binValue==1) neighbour++;

                //up
                if(a[i-1][j].binValue==1) neighbour++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour++;
            }

            //when i is Y-2 but j isnt 0 or X-1 (i.e the bottom row)
            if(i==Y-2&&j!=0&&j!=X-1)
            {
                //down right
                if(a[0][j+1].binValue==1) neighbour++;

                //down
                if(a[0][j].binValue==1) neighbour++;

                //down left
                if(a[0][j-1].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;

                //left
                if(a[i][j-1].binValue==1) neighbour++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour++;

                //up
                if(a[i-1][j].binValue==1) neighbour++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour++;
            }
            
            //everything thats not an edge or a corner
            if(i!=0&&j!=0&&i!=Y-2&&j!=X-1)
            {

                //down right
                if(a[i+1][j+1].binValue==1) neighbour++;

                //down
                if(a[i+1][j].binValue==1) neighbour++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour++;

                //right
                if(a[i][j+1].binValue==1) neighbour++;

                //left
                if(a[i][j-1].binValue==1) neighbour++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour++;

                //up
                if(a[i-1][j].binValue==1) neighbour++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour++;
            }

            //check if there are any live neighbours up, down, left, right, diagonals too
            //if(x=0) then check the end of the array 
            //if(x= the width X) then check the beginning of the array
            //if there is then add one to the array neightbours ? 

            //death by underpopulation (< 2) or overpopulation (> 3)
            if(neighbour < 2 || neighbour > 3)
            {
                 a[i][j].binValue=0;
            }

            //life by reproduction
            if(neighbour == 3)
            {   
                if(a[i][j].binValue==0)
                {
                    a[i][j].binValue = 1;
                }
            }

            //any LIVE cell with two or three live neighbours lives
            if(neighbour > 1 && neighbour < 4)
            {
                if(a[i][j].binValue==1)
                {
                    a[i][j].binValue = 1;
                }     
            }
        }

    } 

    for(int i = 0; i < Y-1; ++i)
    {
        for(int j = 0; j < X; j++)
        {
            a[i][j].patternop(a[i][j].binValue);
        }
    }
    usleep(500000);
    Arrayprinter(Y, X, a);
    converter(Y,X,a);
    for(int q = 0; q < 100; q++){
        cout << "\n";
    }
}

void setupGameOfLife()
{

    //create an array for the thing
    //Y=generations
    //X=width of the grid

    int y;
    //int f;
    int x;
    cout<<"Enter the amount of generations you want to view";
    cin>>y;
    cout<<"Enter the width of the table";
    cin>>x;
    // cout<<"Enter the rule you want to run from";
    // cin>>f;

    //binaryCalc(f,NULL,NULL);
    int Y = y;
    // int X = (2*Y)-1;
    int X = x;
    pattern** a = ArrayAllocater(Y,X,a);
    
    converter(Y,X,a);
}


int main(){
    setupGameOfLife();
}