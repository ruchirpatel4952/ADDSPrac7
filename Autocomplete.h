#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children; // Child nodes
    bool isEndOfWord; // Is this node the end of a word

    TrieNode() : isEndOfWord(false) {}  // Constructor initializing isEndOfWord to false
};

class Autocomplete {
private:
    TrieNode* root;  // Root of the Trie
    void findWordsFromNode(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
    
public:
    Autocomplete();  // Constructor
    ~Autocomplete();  // Destructor
    void insert(const std::string& word);  // Insert a word into the Trie
    std::vector<std::string> getSuggestions(const std::string& partialWord);  // Get suggestions for a prefix
    void clearTrie(TrieNode* node);  // Helper function to clear the Trie
};

#endif // AUTOCOMPLETE_H
