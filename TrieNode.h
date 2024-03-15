// File name: TrieNode.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 10
// Description:  provides support for holding a collection of words (in the form of a trie)
// Honor statement: I have not given or received unauthorized aid on this assignment.

#ifndef PROJECT10_TRIENODE_H
#define PROJECT10_TRIENODE_H


#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>

const size_t ALPHABET = 26;
class TrieNode
{
private:
    char item;
    bool isEndOfWord;
    TrieNode *cur[ALPHABET];

public:

    // Constructor
    // constructs a TrieNode
    // pre: parameter char c exists
    // post: node is initialized with c
    TrieNode(char c, bool isEndOfWord);

    // Copy Constructor
    // constructs a TrieNode from the parameter
    // pre:  parameter object, rhs, exists
    // post: Object is initialized to be a copy of the parameter
    TrieNode(const TrieNode& rhs);

    // Class Destructor
    // Destroys a TrieNode
    // pre:  Class object exists
    // post: Class object does not exist
    ~TrieNode( );

    // Assignment operator
    // Assigns a TrieNode to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const TrieNode& operator= (const TrieNode& rhs);

    // insert
    // inserts str starting with the given TrieNode.
    // pre:  str is a string.
    // post: str added at the right position.
    void insert (const std::string& str);


    // isWord
    // Returns true if str is in the sub-Trie starting at the given TrieNode,
    // else returns false
    // pre:  str is a string.
    // post: return true or false.
    bool isWord (const std::string& str) const;

    // isPrefix
    // Returns true if pre is a prefix of a word in the sub-Trie starting at
    // the given TrieNode, else returns false
    // pre:  pre is a string.
    // post: returns true or false.
    bool isPrefix (const std::string& pre) const;

    // print
    // Prints all words starting at the given TrieNode.
    // pre:  str is a string.
    // post: all words starting at the given TrieNode are printed.
    void print (const std::string& str) const;

    // size
    // Returns the number of words.
    // pre:  TrieNode exists
    // post: number of words in the sub-Trie is returned.
    size_t wordCount ( ) const;

};

#endif //PROJECT10_TRIENODE_H
