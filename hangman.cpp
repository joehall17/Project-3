/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 3/7/2019
*/

#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() {

    ifstream fin("dictionary.txt");
    if (!fin) {
        cout << "Error opening / dictionary.txt / for reading." << endl;
         
    }
    string line;
    while(getline(fin, line)){
        dic[line.length()].insert(line);
    }
    map<int,set<string> >::iterator itr = --dic.end();

    itr = dic.begin();


}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses, int length, bool count) {
    // TODO: Initialize game state variables


    //Find words of given length
    set<string> words = dic[length];
    // Guessed letters
    vector<char> used(length+1, '_');
    used.clear();
    // WORD
    vector<char> theWord(length, '_');

    char letter;
    int x = 0;
    while(num_guesses>0){
        cout << "Your word is: ";
        get_display_word(theWord, used);
        cout << endl;
        cout << "You have " << get_guesses_remaining(num_guesses) + 1 << " remaining." << endl;
        get_guessed_chars(used);
        cout << endl;
        cout << "Enter a letter: ";
        cin >> letter;



        // Was it guessed already
        was_char_guessed(letter, used);
        // Add guess to used
        used.push_back(letter);

        /// Check if guess in word
        process_guess(letter, words, used, theWord, count,  num_guesses);

        num_guesses -= 1;
        vector<string> itr;

        map<string, int> fams;

        if(is_won(theWord)){
            cout << "You win!" << endl;

            return;
        }
        else if(is_lost(theWord, num_guesses)){
            cout << "You lost :(" << endl;
            return;
        }

    }


}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
void families(map<int,set<string> >& fams, vector<string>& ){

}

void hangman::process_guess(char c, set<string>& words, vector<char>& used, vector<char>& theWord, bool count, int guesses){
    if(count == true){
        cout << "Words in given family: " << words.size() << endl;
    }

    map<string, set<string> > fams;

    for(auto itr=words.begin(); itr!=words.end(); itr++) {
        string fam;
        int pos;
        string curWord = *itr;

        for(char const &x : *itr){
            if(x == c){
                fam += x;
            }
            else{
                fam += "_";
            }
        }
        fams[fam].insert(*itr);


    }


    string x;
    set<string> temp;
    for(auto i : fams){
        if(i.second.size() > temp.size()){
            temp = i.second;
            x = i.first;
        }
    }
    words = temp;

    for(int i = 0; i < x.size(); i++){
        if(x.at(i) != '_'){
            theWord[i] = x.at(i);
        }
    }
    if(is_won(theWord) == true) {
        cout << "The word was: ";
        for (auto itr = words.begin(); itr != words.end(); itr++) {
            cout << *itr;
        }
        cout << endl;
    }
    /// Output word if lost
    if(is_lost(theWord, guesses) == true) {
        cout << "The word was: ";
        for (auto itr = words.begin(); itr != words.end(); itr++) {
            cout << *itr;
        }
    }




}


// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
void hangman::get_display_word(vector<char>& theWord, vector<char>& used) {

    for(int i = 0; i < theWord.size(); i++){
        //if statment for if letters in word
        cout << theWord[i] << " ";
    }


}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.

int hangman::get_guesses_remaining(int num_guesses){
    num_guesses -= 1;
    return num_guesses;

}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
/// GOOD ///
void hangman::get_guessed_chars(vector<char>& used) {
    cout << "You have guessed: ";
    for(int i = 0; i<used.size(); i++){
            cout << used[i] << " ";

    }
}


// was_char_guessed()
//
// Return true if letter was already guessed.
/// GOOD ///
bool hangman::was_char_guessed(char c, vector<char>& used) {
    for(int i = 0; i<used.size(); i++){
        /// Is letter already Guessed
        if(used[i] == c){
            return true;
        }
        else{
            return false;
        }
    }


}


// is_won()
//
// Return true if the game has been won by the player.
/// GOOD ///
bool hangman::is_won(vector<char>& theWord) {
    if(count(theWord.begin(), theWord.end(), '_') == 0){
        return true;
    }
    else{
        return false;
    }

}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost(vector<char>& theWord, int num_guesses) {
    if(num_guesses <= 0 and !is_won(theWord)){
        return true;
    }
    else{
        return false;
    }
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word(vector<char>& theWord, vector<char>& used) {

    return "bla";
}


