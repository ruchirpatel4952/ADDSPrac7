#include "Autocomplete.h"
#include <iostream>

int main() {
    Autocomplete autocomplete;

    // Insert words into the Trie
    autocomplete.insert("bin");
    autocomplete.insert("ball");
    autocomplete.insert("ballet");

    // Test the getSuggestions function
    std::vector<std::string> suggestions = autocomplete.getSuggestions("bal");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << std::endl;
    }

    return 0;
}
