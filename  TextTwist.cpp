// File name: TextTwist.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 10
// Description: creates words from 7 letters for the game Text Twist.
// Honor statement: I have not given or received unauthorized aid on this assignment.

#include <iostream>
#include <string>
#include "Trie.h"

const int NUM_LETTERS = 7;

void getLetter(std::string& set);
void combinations(std::string set, std::string prefix, Trie& myWords, Trie lexicon);
bool isLowerCharacters(std::string s);


int main() {
    Trie lexicon;
    lexicon.loadFromFile("ospd.txt");

    std::string set = ""; //the set of 7 letters
    while(set.length() != NUM_LETTERS || !isLowerCharacters(set)) { //letters are in lower case and there are 7
        getLetter(set);
    }

    Trie myWords; //myWords store the words from the 7 letters

    combinations(set, "", myWords, lexicon); //making words

    myWords.print();

}

// getLetter
// prompts the user to enter 7 letters and verifies that those letters are 7 and in lowercase
// pre: set is an empty string.
// post: set is a string of 7 lowercase letters.
void getLetter(std::string& set){

    std::cout << "Enter the seven letters of the Text Twist game: " << std::endl;

    std::string given;
    std::cin >> given;
    set = given;

    if (set.length() != NUM_LETTERS){
        std::cout << "You must enter exactly 7 characters." << std::endl;
    }
    else if (!isLowerCharacters(set)){
        std::cout << "You must enter only lower case alphabetic characters." << std::endl;
    }

}

// isLowerCharacters
// checks if the parameter string is in all lowercase letters
// pre: s is a string
// post: returns false if not all letters are in lower case, true if all letters are.
bool isLowerCharacters(std::string s){
    for(size_t i = 0; i<s.length(); i++){
        if(!islower(s[i])){
            return false;
        }
    }
    return true;
}

// combinations
// combines the 7 letters in the set to make different words of length 3 to 7
// pre: set has the 7 letters, prefix is an empty string, myWords store the words made, lexicon is the dictionary used
// to make sure the words are legal.
// post: all words are in myWords.
void combinations(std::string set, std::string prefix, Trie& myWords, Trie lexicon){
    if (prefix.length() > NUM_LETTERS){
        combinations(set, "", myWords, lexicon);
        return;
    }else{
        if(prefix.length() >=3) {
            if (lexicon.isWord(prefix)) {
                myWords.insert(prefix);
            }
        }
        for (size_t i = 0; i < set.length(); i++){
            std::string newPrefix;
            newPrefix = prefix + set[i];
            if (lexicon.isPrefix(newPrefix)) {
                if (i==0){
                    combinations(set.substr(1), newPrefix, myWords, lexicon);
                }else {
                    combinations(set.substr(0,i) + set.substr(i+1), newPrefix, myWords, lexicon);
                }
            }
        }
    }
}
