#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int routerId;

    TrieNode() : isEndOfWord(false), routerId(-1) {}
};

class PrefixMatcher {
public:
    PrefixMatcher();
    ~PrefixMatcher();
    void insert(const std::string& word, int routerId);
    std::vector<std::string> getSuggestions(const std::string& partialWord);
    int selectRouter(const std::string& prefix);

private:
    TrieNode* root;
    void findWordsFromNode(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
    void clearTrie(TrieNode* node);
};

#endif // PREFIXMATCHER_H