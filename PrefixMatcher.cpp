#include "PrefixMatcher.h"

// Constructor
PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

// Destructor
PrefixMatcher::~PrefixMatcher() {
    clearTrie(root);
}

// Insert a word into the Trie with a router ID
void PrefixMatcher::insert(const std::string& word, int routerId) {
    TrieNode* currentNode = root;
    for (char ch : word) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            currentNode->children[ch] = new TrieNode();
        }
        currentNode = currentNode->children[ch];
    }
    currentNode->isEndOfWord = true;
    currentNode->routerId = routerId;
}

// Get suggestions for a prefix
std::vector<std::string> PrefixMatcher::getSuggestions(const std::string& partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* currentNode = root;
    for (char ch : partialWord) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            return suggestions; // No suggestions if prefix not found
        }
        currentNode = currentNode->children[ch];
    }
    findWordsFromNode(currentNode, partialWord, suggestions);
    return suggestions;
}

// Select the router ID for the longest matching prefix
int PrefixMatcher::selectRouter(const std::string& prefix) {
    TrieNode* currentNode = root;
    int lastRouterId = -1;
    for (char ch : prefix) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            break;
        }
        currentNode = currentNode->children[ch];
        if (currentNode->isEndOfWord) {
            lastRouterId = currentNode->routerId;
        }
    }
    return lastRouterId;
}

// Helper function to find all words from a given node
void PrefixMatcher::findWordsFromNode(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& pair : node->children) {
        findWordsFromNode(pair.second, prefix + pair.first, suggestions);
    }
}

// Helper function to clear the Trie
void PrefixMatcher::clearTrie(TrieNode* node) {
    for (auto& pair : node->children) {
        clearTrie(pair.second);
    }
    delete node;
}