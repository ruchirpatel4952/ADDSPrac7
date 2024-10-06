#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Autocomplete {
public:
    Autocomplete();
    ~Autocomplete();
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);

private:
    TrieNode* root;
    void findWordsFromNode(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
    void clearTrie(TrieNode* node);
};

#endif // AUTOCOMPLETE_H