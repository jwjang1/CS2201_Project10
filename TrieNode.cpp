// File name: TrieNode.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 10
// Description:  provides support for holding a collection of words (in the form of a trie)
// Honor statement: I have not given or received unauthorized aid on this assignment.

#include "TrieNode.h"
#include <cstddef>
#include <stdexcept>
#include <iostream>

// Constructor
// pre: parameter char c exists
// post: node is initialized with c
TrieNode::TrieNode(char c, bool b): item(c), isEndOfWord(b), cur(){
}

// Copy Constructor
// pre:  parameter object, rhs, exists
// post: Object is initialized to be a copy of the parameter
TrieNode::TrieNode(const TrieNode& rhs): item(rhs.item), isEndOfWord(rhs.isEndOfWord){
    for(size_t ii = 0; ii < ALPHABET; ii++){
        if(rhs.cur[ii] != nullptr){
            cur[ii] = new TrieNode(*rhs.cur[ii]);
        }else{
            cur[ii] = nullptr;
        }
    }
}

// Class Destructor
// Destroys a TrieNode
// pre:  Class object exists
// post: Class object does not exist
TrieNode::~TrieNode( ){
    for(size_t ii = 0; ii<ALPHABET; ii++){
        delete(cur[ii]);
        cur[ii] = nullptr;
    }
}

// Assignment operator
// Assigns a TrieNode to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const TrieNode& TrieNode :: operator= (const TrieNode& rhs){
    if(this != &rhs){
        TrieNode temp(rhs);
        std::swap(item, temp.item);
        std::swap(isEndOfWord, temp.isEndOfWord);
        for(size_t ii = 0; ii < ALPHABET; ii++) {
            std::swap(cur[ii], temp.cur[ii]);
        }
    }
    return *this;
}

// insert
// inserts str starting with the given TrieNode.
// pre:  str is a string.
// post: str added at the right position.
void TrieNode::insert (const std::string& str){
    if (str == ""){
    }else if(item == ' ' && cur[str[0] - 'a'] == nullptr){
        cur[str[0] - 'a'] = new TrieNode(str[0], false);
        cur[str[0]-'a']->insert(str);
    }else if (item == ' ' && cur[str[0] - 'a'] != nullptr){
        cur[str[0]-'a']->insert(str);
    }
    else if (item == str[0]) {
        if (str.length() == 1) {
            isEndOfWord = true;
        }else if (cur[str[1] - 'a'] == nullptr) {
            cur[str[1] - 'a'] = new TrieNode(str[1], false);
            cur[str[1] - 'a']->insert(str.substr(1, str.length()));
        }else if (cur[str[1] - 'a'] != nullptr){
            cur[str[1] - 'a']->insert(str.substr(1, str.length()));
        }
    }
}

// isWord
// Returns true if str is in the sub-Trie starting at the given TrieNode,
// else returns false
// pre:  str is a string.
// post: return true or false.
bool TrieNode::isWord (const std::string& str) const{
    if (str == ""){
        return false;
    }else if(item == ' ' && cur[str[0]-'a'] != nullptr){
        return cur[str[0]-'a']->isWord(str);
    }else if(item == ' ' && cur[str[0]-'a'] == nullptr){
        return false;
    }else if(item == str[0]){
        if(str.length() == 1 && isEndOfWord){
            return true;
        }else if(cur[str[1]-'a'] != nullptr){
            return cur[str[1]-'a']->isWord(str.substr(1, str.length()));
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// isPrefix
// Returns true if pre is a prefix of a word in the sub-Trie starting at
// the given TrieNode, else returns false
// pre:  pre is a string.
// post: returns true or false.
bool TrieNode::isPrefix (const std::string& pre) const{
    if(pre.length() == 0){
        return true;
    }else if(item == ' ' && cur[pre[0]-'a'] != nullptr){
        return cur[pre[0]-'a']->isPrefix(pre);
    }else if(item == ' ' && cur[pre[0]-'a'] == nullptr) {
        return false;
    }else if(item == pre[0]){
        if(pre.length() == 1){
            return true;
        }else if(cur[pre[1]-'a'] != nullptr){
            return cur[pre[1]-'a']->isPrefix(pre.substr(1, pre.length()));
        }else {
            return false;
        }
    }else{
        return false;
    }
}

// print
// Prints all words starting at the given TrieNode.
// pre:  str is a string.
// post: all words starting at the given TrieNode are printed.
void TrieNode::print (const std::string& str) const{
    if (item == ' ') {
        for (size_t ii = 0; ii < ALPHABET; ii++) {
            if (cur[ii] != nullptr)
                cur[ii]->print(str);
        }
    }else if(isEndOfWord){
        std::cout << str << item << "\n";
        for (size_t ii = 0; ii < ALPHABET; ii++) {
            if (cur[ii] != nullptr)
                cur[ii]->print(str+item);
        }
    }else{
        for (size_t ii = 0; ii < ALPHABET; ii++) {
            if (cur[ii] != nullptr)
                cur[ii]->print(str+item);
        }
    }
}

// size
// Returns the number of words.
size_t TrieNode::wordCount ( ) const{
    size_t numWord = 0;

    if (isEndOfWord) {
        numWord++;
        for (size_t i = 0; i < ALPHABET; i++) {
            if (cur[i] != nullptr) {
                numWord += cur[i]->wordCount();
            }
        }
    }else {
        for (size_t i = 0; i < ALPHABET; i++) {
            if (cur[i] != nullptr) {
                numWord += cur[i]->wordCount();
            }
        }
    }
    return numWord;
}