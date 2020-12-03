#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: 

    last modified: 9/24/2017
*/

#include <string>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();

    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int num_guesses, int length, bool count);

    // player guesses letter c; return whether or not char is in word
    void process_guess(char c, set<string>& words, vector<char>& used, vector<char>& theWord, bool count, int guesses);

    // display current state of word - guessed characters or '-'
    void get_display_word(vector<char>& theWord, vector<char>& used);

    // How many guesses remain?
	int get_guesses_remaining(int num_guesses);

    // What characters have already been guessed (for display)?
    void get_guessed_chars(vector<char>& used);

    // Has this character already been guessed?
    bool was_char_guessed(char c, vector<char>& used);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won(vector<char>& used);
    bool is_lost(vector<char>& used, int num_guesses);

    // Return the true hidden word.
    string get_hidden_word(vector<char>& theWord, vector<char>& used);

private:
    map<int, set<string> >dic;
};

#endif
