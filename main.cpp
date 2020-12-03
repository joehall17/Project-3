/*
    main.cpp
        
    Implements the user interface for hangman.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 3/7/2019
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "hangman.h"

using namespace std;

// helper function prototypes
int get_integer(string prompt); // return a positive integer
char get_letter(string prompt); // return a valid lowercase letter
bool get_yesno(string prompt);  // return true == yes / false == no
string trim(string s);          // remove leading/trailing whitespace

int main() {
    cout << "Welcome to Hangman!" << endl;
    cout << "===================" << endl << endl;

    // get the hangman object
    hangman game;
    
    // Keep playing the game until the user decides otherwise
    while (true) {      
        // TODO: Maybe need a thing to track the word here idk
        int length;
        cout << "Enter the length of a word: " << endl;
        cin >> length;
        while(length < 1 or length > 29) {
            if (length < 1 or length > 29) {
                cout << "Invalid length try again: " << endl;
                cin >> length;
            }
        }
        cout << endl;

        int num_guesses;
        cout <<"How many guesses would you like?" << endl;
        cin >> num_guesses;
        cout << endl;

        // TODO: prompt user to decide whether or not they want to see how many words
        // remain possible for the current display word and previous guesses
        char wcount;
        bool count;
        cout << "Display total words left? (y/n)" << endl;
        cin >> wcount;
        cout << endl;
        if(wcount == 'y'){
            count = true;
        }
        else if(wcount == 'n'){
            count = false;
        }
        else{
            cout << "Invalid answer, try again: ";
            cin >> wcount;
            cout << endl;
        }

        /// Start game ///
        game.start_new_game(num_guesses, length, count);

       
        cout << endl;
        if (!get_yesno("Would you like to play again (y/n)?")) break;
    }

    cout << endl << "Thank you for playing Hangman." << endl;

    return 0;
}

// Prompt for a positive integer response, re-prompting if invalid
// input is given. This is not super-robust - it really should work
// harder to filter out responses like "123foo", but oh well.
int get_integer(string msg) {
    while (true) {
        string input;    
        int result = 0;

        cout << msg << endl;
        getline(cin, input);

        result = atoi(input.c_str());
        if (result > 0) return result;

        cout << "I didn't understand that. Please enter a positive integer.";
        cout << endl;
    }
}
    
// Prompt for a letter of the alphabet, re-prompting if invalid
// input is given.
char get_letter(string msg) {
    while (true) {
        string input;    
 
        cout << msg << endl;
        getline(cin, input);

        input = trim(input);

        if (input.size() == 1) {
            char result = tolower(input[0]);
            if (result >= 'a' && result <= 'z') return result;
        }
        
        cout << "I didn't understand that. ";
        cout << "Please enter a letter of the alphabet.";
        cout << endl;
    }
}


// Prompt for a yes/no response, re-prompting if invalid
// input is given.
bool get_yesno(string msg) {
    while (true) {
        string input;    
 
        cout << msg << endl;
        getline(cin, input);

        input = trim(input);
        for (int i = 0; i < input.size(); i++) {
            input[i] = tolower(input[i]);
        }

        if (input == "y" || input == "yes") return true;
        if (input == "n" || input == "no") return false;
        
        cout << "I didn't understand that. ";
        cout << "Please enter y(es) or n(o).";
        cout << endl;
    }
}

string trim(string s) {
    int a, b;

    for (a = 0; a < s.size() && isspace(s[a]); a++);
    for (b = s.size() - 1; b >= a && isspace(s[b]); b--);
    
    return s.substr(a, b - a + 1);
}


