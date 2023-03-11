//script to ask user if they want to solve a factorial of GCD then solves it
//contributors: Anthony
//progress: complete

#include <iostream>
#include <iomanip>
#include <string>
#include "dna.cpp"
#include "dna.h"
using std::cout; using std::cin; using std::string;

int main() {
    string menuOption,    //user input for what to do on the menu
           exitOption;    //user input to confirm leaving the program

    //displays menu
    cout << "Choose an option to do: (type in the number)\n"
         << "1-Factorial\n"
         << "2-Greatest Common Divisor\n"
         << "3-Exit\n";

    //do while loop for menu, that also calls the functions
    do {
        //menu input, and invalid input message
        cout << "option: ";
        cin >> menuOption;
        if (menuOption != "3" && menuOption != "2" && menuOption != "1") {
            cout << "please pict a valid option (1,2,3)\n";}

        //calls factorial function
        if (menuOption == "1") {
            int factorialInput,    //input for factorial function
                factorialInputDisp;//displays input for factorial function

                cout << "what number would you like to know the factorial of? ";
                cin >> factorialInput;
                factorialInputDisp = factorialInput;

            int factorialResult{factorial(factorialInput)};

            cout << "The factorial of " << factorialInputDisp << " is " << factorialResult << "\n"; }

        //calls greatest common divisor function
        if (menuOption == "2") {
            int gcdInput1,      //first input for gcd function
                gcdInput2,      //second input for gcd function
                gcdInput1Disp,  //displays first input for gcd function
                gcdInput2Disp;  //displays second input for gcd function

            cout << "what two numbers would you like to know the greatest common divisor of? ";
            cin >> gcdInput1;
            gcdInput1Disp = gcdInput1;
            cout << "And: ";
            cin >> gcdInput2;
            gcdInput2Disp = gcdInput2;

            int gcdResult{gcd(gcdInput1, gcdInput2)};

            cout << "The Greatest Common Divisor of " << gcdInput1Disp << " and " << gcdInput2Disp << " is " << gcdResult << "\n"; }

        //will ask the user to confirm exiting the program and will then exit
        if (menuOption == "3") {
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> exitOption;
            while (exitOption != "Y" && exitOption != "y" && exitOption != "N" && exitOption != "n") {
                cout << "Please put in a valid input (y/n): ";
                cin >> exitOption;}
            //if (exitOption == 'Y' || exitOption == 'y') {}
            if (exitOption == "N" || exitOption == "n") {menuOption = "n";} }

    //loops if menu has invalid input
    } while(menuOption != "3" && menuOption != "2" && menuOption != "1");

return 0; }
