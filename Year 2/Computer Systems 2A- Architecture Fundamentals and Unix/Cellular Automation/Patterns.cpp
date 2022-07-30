#include <iostream>
#include <string>
using namespace std;
class pattern
{
    // Access specifier
    public:
    string patternGrid1[3] = {"■","■","■"};
    string patternGrid2[3] = {"■","■","_"};
    string patternGrid3[3] = {"■","_","■"};
    string patternGrid4[3] = {"■","_","_"};
    string patternGrid5[3] = {"_","■","■"};
    string patternGrid6[3] = {"_","■","_"};
    string patternGrid7[3] = {"_","_","■"};
    string patternGrid8[3] = {"_","_","_"};
    
    string** patternArray;

    string** Assignarray(){   
    patternArray = new string*[3];
    for(int i = 0; i < 8; ++i)
    {
    patternArray[i] = new string[3];
    }
    patternArray[0] = patternGrid1;
    patternArray[1] = patternGrid2;
    patternArray[2] = patternGrid3;
    patternArray[3] = patternGrid4;
    patternArray[4] = patternGrid5;
    patternArray[5] = patternGrid6;
    patternArray[6] = patternGrid7;
    patternArray[7] = patternGrid8;
    
    return patternArray;
    }
    int binValue;
        string patternval;
        void setpattern(pattern n)
        {
            n.patternval ="_";
        }
    void patternop(int value)
    {
        if (value = 0)
        {
            patternval = "_";
        }
        else
        {
            patternval = "■";
        }
    }
    void checkstring(string ch)
    {
        if (ch == "_")
        {
            binValue = 0;
        }
        else
        {
            binValue = 1;
        }
    }
    
};