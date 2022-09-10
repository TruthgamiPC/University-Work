#include <iostream>
#include <string>
#include "functionality.cpp"
using namespace std;

// Initialise the method from functionality.cpp
void gridGeneration(); 

// Display the list of options the user has to choose from
void menuDisplay(){
    cout << "========================================" << endl;
    cout << " Option 1-3 require several inputs to generate a grid" << endl;
    cout << "1. Generate a grid with hardcoded start point" << endl;
    cout << "2. Generate a grid with custom start point" << endl;
    cout << "3. Generate a grid with a random start point" << endl;
    cout << "4. Generate a completely randomised grid" << endl;
    cout << "q. Exit the program" << endl;
}

// Read input from the user and process in the program with it
void useMenu(){
    string userInput;
    cout << "Please select your option" << endl;
    cin >> userInput;

    if (userInput == "1"){
        gridGeneration(1);
        // End
    } else if (userInput == "2"){
        gridGeneration(2);
    } else if (userInput == "3"){
        gridGeneration(3);
    } else if (userInput == "4"){
        gridGeneration(4);
    } else if (userInput == "q"){
        cout << "Entered q" << endl;
        exit(0);
    } else {
        std::cout << "Bad Input, Try again " << std::endl;
    }
}

int main(){
    while (true){
        menuDisplay();
        useMenu();
    }
    return 0;
}




   // CASE is as bad as usual so will use if statements
    // need a bit

    // switch (userInput) {
    //     case 'a' :
    //         cout << "Entered 1" << endl;
    //     case 'b' :
    //         cout << "Entered 2" << endl;
    //     case 'c' :
    //         cout << "Entered 3" << endl;
    //     case 'q' :
    //         cout << "Entered 9 - program will stop now" << endl;
    //         exit(0);
    //     default :
    //         std::cout << "Bad Input, Try again " << std::endl;
    //         break;
    // }