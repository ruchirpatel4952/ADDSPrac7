#include "Autocomplete.h"
#include <iostream>

int main() {
    Autocomplete ac;
    ac.insert("hello");
    ac.insert("hell");
    ac.insert("heaven");
    ac.insert("heavy");

    std::vector<std::string> suggestions = ac.getSuggestions("he");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << std::endl;
    }

    return 0;
}