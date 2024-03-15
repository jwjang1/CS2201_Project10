// File name: Trie.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 10
// Description:  provides support for holding a collection of words (in the form of a trie)
// Honor statement: I have not given or received unauthorized aid on this assignment.

#include <cstddef>
#include <stdexcept>
#include "Trie.h"

// Default Constructor
// Constructs a Trie
// post: Trie is constructed
Trie::Trie(): root(' ', false) {
}

// insert
// Inserts a node
// pre: Trie and parameter string word exists
// post: node is inserted into Trie
void Trie::insert(const std::string &word) {
    root.insert(word);
}

// loadFromFile
// inserts all words from a file into the Trie
// pre: Trie exists
// post: Trie has all the words from the file
// std::invalid_argument exception if the specified file cannot be opened.
void Trie::loadFromFile(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file) {
        throw std::invalid_argument("File does not exist!");
    }
    std::string word;
    while (file >> word) {
        insert(word);
    }
}

// isWord
// Determines if the parameter is in the Trie
// pre: Trie and parameter string word exists
// post: returns true or false depending on whether the word exists in the Trie
bool Trie::isWord(const std::string &word) const{
    return root.isWord(word);
}

// isPrefix
// Determines if the parameter is the prefix of a word in the Trie
// pre: Trie and parameter string pre exists
// post: returns true or false depending on whether pre is the prefix of a word in the Trie
bool Trie::isPrefix(const std::string &pre) const{
    return root.isPrefix(pre);
}

// print
// Prints all words in the Trie, one per line
// pre: Trie exists
// post: All words in the Trie printed
void Trie::print() const{
    root.print("");
}

// wordCount
// Returns a count all the words in the Trie
// pre: Trie exists
// post: returns the word count of a Trie
size_t Trie::wordCount() const{
    return root.wordCount();
}