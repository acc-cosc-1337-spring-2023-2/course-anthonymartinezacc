//script to calculate G & C precent of a DNA string, and to find the DNA compliment
//contributors: Anthony
//progress: complete

#include <iostream>
#include <iomanip>
#include <string>
//#include <string.h>
#include <algorithm>
#include "func.cpp"
#include "func.h"
using std::cout; using std::cin; using std::string;

int main() {
    string       menuOption,    //user input for what to do on the menu
                 exitOption,    //user input to confirm leaving the program
                 dnaString;     //user input of DNA string
    const string dnaCharacters = "ATGCatgc"; //checks if user input is a valid dna string
    bool         validDNA = false;

    //displays menu
    cout << "Choose an option to do: (type in the number)\n"
         << "1-Get GC Content\n"
         << "2-Get DNA Complement\n"
         << "3-Exit\n";

    //do while loop for menu, that also calls the functions
    do {
        //menu input, and invalid input message
        cout << "option: ";
        cin >> menuOption;
        menuOption.erase(std::remove(menuOption.begin(),menuOption.end(),' '),menuOption.end());
        if (menuOption != "3" && menuOption != "2" && menuOption != "1") {
            cout << "please pict a valid option (1,2,3)\n";}

        //ask user for DNA string input then calls a function based on the menu option
        if (menuOption == "1" || menuOption == "2") {
            //ask for user input, while loop to verify
            while (validDNA == false){
            cout << "DNA String (ATGC): ";
            cin >> dnaString;
            validDNA = onlyConsistsOf(dnaString, dnaCharacters);
            if (validDNA == false){cout << "Invalid input, can only consist of (A,T,G,C)\n";}
            }


            if (menuOption == "1") {
                //gets and displays what % of the tring is 'G' and 'C'
                double gcPrecent{get_gc_content(dnaString)};
                cout << std::fixed << std::setprecision(1)
                     << "The DNA string consist of " << gcPrecent << "% G & C\n";
            }

            if (menuOption == "2") {
                //gets and displays the dna compliment of dnaString
                string dnaStringComplement {get_dna_complement(dnaString)};
                cout << "The dna Complement of " << dnaString << " is " << dnaStringComplement << "\n";
            }

             }

        //will ask the user to confirm exiting the program and will then exit
        if (menuOption == "3") {
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> exitOption;
            exitOption.erase(std::remove(exitOption.begin(),exitOption.end(),' '),exitOption.end());
            while (exitOption != "Y" && exitOption != "y" && exitOption != "N" && exitOption != "n") {
                cout << "Please put in a valid input (y/n): ";
                cin >> exitOption;}
            //if (exitOption == 'Y' || exitOption == 'y') {}
            if (exitOption == "N" || exitOption == "n") {menuOption = "n";} }

    //loops if menu has invalid input
    } while(menuOption != "3" && menuOption != "2" && menuOption != "1");

return 0; }
