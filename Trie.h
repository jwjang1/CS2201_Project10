// File name: Trie.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 10
// Description:  provides support for holding a collection of words (in the form of a trie)
// Honor statement: I have not given or received unauthorized aid on this assignment.

#ifndef PROJECT10_TRIE_H
#define PROJECT10_TRIE_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "TrieNode.h"

class Trie {
private:
    TrieNode root;

public:

    // Default Constructor
    // Constructs a Trie
    // post: Trie is constructed
    Trie( );

    // insert
    // Inserts a node
    // pre: Trie and parameter string word exists
    // post: node is inserted into Trie
    void insert (const std::string& word);

    // loadFromFile
    // inserts all words from a file into the Trie
    // pre: Trie exists
    // post: Trie has all the words from the file
    // std::invalid_argument exception if the specified file cannot be opened.
    void loadFromFile (const std::string& filename);

    // isWord
    // Determines if the parameter is in the Trie
    // pre: Trie and parameter string word exists
    // post: returns true or false depending on whether the word exists in the Trie
    bool isWord (const std::string& word) const;

    // isPrefix
    // Determines if the parameter is the prefix of a word in the Trie
    // pre: Trie and parameter string pre exists
    // post: returns true or false depending on whether pre is the prefix of a word in the Trie
    bool isPrefix (const std::string& pre) const;

    // print
    // Prints all words in the Trie, one per line
    // pre: Trie exists
    // post: All words in the Trie printed
    void print ( ) const;

    // wordCount
    // Returns a count all the words in the Trie
    // pre: Trie exists
    // post: returns the word count of a Trie
    size_t wordCount ( ) const;
};


#endif //PROJECT10_TRIE_H
