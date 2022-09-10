#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <array>
#include <bits/stdc++.h>

#include "Patterns.cpp"
using namespace std;

int binary[8];
int counter = 7;

int convertBtInt(int variable,int n, char char_array[]){
    int count = 0;
    for (int pos = n; pos >= 0; --pos){
        if (char_array[pos] == '1'){
            variable = variable + (pow(2,(count-1)));
        }
        count++;
    }
    return variable;
}

int binaryToInteger(){
    int variable = 0;
    bool statement;

    while (true){
        string s = "";
        cout << "ENTER A BINARY THING" << endl;
        cin >> s;

        if ( s == "q"){
            break;
        }

        int n = s.length();
        char char_array[n-1];
        strcpy(char_array, s.c_str());

        for (int i = 0; i < n; i++){
            if (char_array[i] != '0' && char_array[i] != '1'){
                cout << "This is not a binary number please use only 0 and 1's" << endl;
                statement = true;
                break;
            }
        }
        
        if (statement != true){
            variable = convertBtInt(variable,n,char_array);
            cout << endl;
            cout << variable << endl;
            cout << endl;
            break;
        } else {
            statement = false;
        }
    }    
    return variable;
}

// int writeToFile(pattern ** a){
//     char arr2[8][8];
//     ofstream out("text_file_1.txt");
//     out.write(a[0].patternval,64);
//     out.close();

//     ifstream in ("text_file_1.txt");
//     in.read(arr2[0],64);
//     for (int i = 0; i < 8; ++i){
//         for (int x = 0; x < 8; ++x){
//             cout << arr2[i][x];
//         }
//         cout << endl;
//     }
//     return 0;
// }

void binaryCalc(int tester, int n, int tt) {
    tt = tester;
    if (tester > 1) {
        if ((tt %= 2) != 0) {
            n = (tt % 2);
            tester = tester / 2;
            binary[counter] = n;
            counter--;
            binaryCalc(tester, n, tt);
        } else {
            n = (tt % 2);
            tester = tester / 2;
            binary[counter] = n;
            counter--;
            binaryCalc(tester, n, tt);
        }
    } else {
        binary[counter] = 1;
    }

}

// sets the values of the pattern
pattern ** ArrayAllocater(int Y, int X, pattern ** a, int loc) {            // LOC code: 900 - hard coded       ||    #any value~ - custom / random
    a = new pattern * [Y];
    for (int i = 0; i < Y; ++i)
        a[i] = new pattern[X];

    // fill
    for (int i = 0; i < Y; ++i) {
        for (int j = 0; j < X; ++j) {
            a[i][j].patternval = "_";
            a[i][j].binValue = 0;
            if (loc == 900){                
                if (j == X / 2 && i == 0) {             //Kekws
                    a[i][j].patternval = "■";           // Here is where it sets the starting point - NOTE NOTE NOTE - change it to a custom setting.
                    a[i][j].binValue = 1;
                }
            } else {
                a[i][loc].patternval = "■";           // Here is where it sets the starting point - NOTE NOTE NOTE - change it to a custom setting.
                a[i][loc].binValue = 1;
            }

            // if (j == X / 3 && i == 0) {             //Kekws
            //     a[i][j].patternval = "■";           // Here is where it sets the starting point - NOTE NOTE NOTE - change it to a custom setting.
            //     a[i][j].binValue = 1;
            // }
        }
    }
    return a;
}

//prints the array 
void Arrayprinter(int Y, int X, pattern ** b) {
    for (int i = 0; i < Y; ++i) {
        for (int j = 0; j < X; ++j) {
            cout << b[i][j].patternval << " ";
        }
        cout << endl;       // Line ender
    }
}

bool Patterncompare(pattern array[3], bool p) {
    pattern ob;
    int turn = 0;
    ob.Assignarray();
    for (int i = 0; i < 8; i++) {
        int c;
        c = 0;
        int y = 0;
        for (int j = 0; j < 3; j++) {
            p = NULL;
            if (y > 2) {
                y = 0;
            }
            if (array[y].patternval == ob.patternArray[i][j]) {
                //  cout<<"The binary value is"<< binary[i]<<endl;
                c++;

            } else {
                // cout<<"The binary value is"<< binary[i]<<endl;

            }

            if (c == 3 && binary[i] == 1) {
                p = true;
                return true;
            }
            if (c == 3 && binary[i] == 0) {
                p = false;
                return false;
            }
            y++;

        }
        // cout << endl;
    }
    turn++;
}

void arrayMover(int Y, int X, pattern ** b) {
    pattern patternChecker[3];
    bool turn = NULL;
    pattern obj;
    obj.Assignarray();
    int count = 0;
    int timer = 0;
    // int cn=0;
    for (int i = 0; i < Y - 1; ++i) {
        for (int j = 0; j < X; j++) {
            if (j < X) {
                if (j - 1 < 0) {
                    pattern stat;
                    stat.patternval = "_";
                    patternChecker[0] = stat;
                    patternChecker[1] = b[i][j];
                } else {
                    patternChecker[0] = b[i][j - 1];
                    // cout << "j-1 is" << j - 1 << endl;
                    patternChecker[1] = b[i][j];
                    // cout << "j is" << j << endl;
                }
                if (j + 1 > X) {

                    pattern stat;
                    stat.patternval = "_";
                    patternChecker[2] = stat;

                }
                if (j + 2 > X) {

                    pattern stat;
                    stat.patternval = "_";
                    patternChecker[2] = stat;

                } else {
                    // cout << "j+1 is" << j + 1 << endl;
                    patternChecker[2] = b[i][j + 1];

                    count++;
                }

                // for(int k = 0; k < 3; ++k)
                // {
                // cout<<patternChecker[k].patternval;
                // }
                cout << endl;           //>>>??
                turn = Patterncompare(patternChecker, turn);

                if (turn == true) {

                    b[i + 1][j].patternval = "■";
                } else if (turn == false) {
                    for (int i = 0; i < 3; i++) {

                    }
                    b[i + 1][j].patternval = "_";
                }

            }

            // if (i == Y - 2 && j - 1 == 0) {
            //     pattern f;
            //     f.patternval = "■";
            //     b[i + 1][j - 1] = f;
            // }
        }
        // cout << endl;

    }
    //  for (int i = 0; i < Y; i+1)
    //  {
    //    for (int j = 0; j<X; j+1)
    //    {
    //         if(i==Y-1&& X==0)
    //         {
    //         pattern f;
    //         f.patternval="■";
    //         b[i][j]=f;
    //         }
    //    }

    //  }

    for (int i = 0; i < 3; i++) {
        // cout<<patternChecker[i].patternval;
    }
    // cout << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            // cout<<obj.patternArray[i][j];
        }
        // cout <<endl;
    }
}


int usrInputCheck(int maxV, int minV){
    int num;
    string snum;

    cout << "Enter an integer: " << endl;
    cin >> snum;
    int n = snum.length();
    char char_array[n+1];
    strcpy(char_array, snum.c_str());
    

    if (snum == "q"){
        return 997;
    }

    for (int i = 0; i < n; i++){
        cout << char_array[i] << endl;
        if (!isdigit(char_array[i])){
            cout << "That is not an integer or exit command" << endl;
            return 998;
        }
    }
  
    stringstream conv(snum);
    conv >> num; 

    if (num > maxV || num < minV){
        cout << "Please keep the valie in the range of: " << minV << " - " << maxV << endl;
        return 999;
    } else {
        return num;
    }
}

void gridGeneration(int setting){
    // Input parameters ->
    int x,y,f;
    int startP;
    pattern ** a;

    if (setting != 4){
        do {
            cout << "Please enter the width for the grid or enter q to exit to menu" << endl;
            x = usrInputCheck(40,5);
            if (x == 997){
                return;
            }
        } while ( x == 998 || x == 999);

        do {
            cout << "Please enter the length for the grid or enter q to exit to menu" << endl;
            y = usrInputCheck(50,2);
            if (y == 997){
                return;
            }
        } while ( y == 998 || y == 999);

        do {
            cout << "Please enter the rule for the grid or enter q to exit to menu" << endl;
            f = usrInputCheck(255,1);
            if (f == 997){
                return;
            }
        } while ( f == 998 || f == 999);


        // Setting checking
        if (setting == 1){
            a = ArrayAllocater(y, x, a, 900);

        } else if (setting == 2){
            do {
                cout << "Please enter the starting point for the grid or enter q to exit to menu" << endl;
                startP = usrInputCheck(x,1);
                if (startP == 997){
                    return;
                }
            } while ( startP == 998 || startP == 999);
            
            a = ArrayAllocater(y, x, a, (startP-1));

        } else if (setting == 3){
            startP = rand() % x;
            a = ArrayAllocater(y, x, a, startP);
        }

    } else {
        x = rand() % 40;
        y = rand() % 40;
        f = rand() % 255;
        startP = rand() % x;
        a = ArrayAllocater(y, x, a, startP);

    }

    binaryCalc(f,0,0);
    counter = 7;
    Arrayprinter(y, x, a);
    arrayMover(y, x, a);
    Arrayprinter(y, x, a);

    for (int i = 0; i < 8; i++) {
        binary[i] = NULL;
    }

    // writeToFile(a);

    // for (int i = 0; i < 8; i++) {
    //     cout << binary[i];
    // }
    // cout << endl;
}