#include "PrefixMatcher.h"
#include <iostream>

int main() {
    PrefixMatcher match;
    match.insert("01", 1);
    match.insert("0101", 2);
    match.insert("01011", 3);
    match.insert("00", 4);

    int router;
    router = match.selectRouter("001110011");
    std::cout << "Selected router: " << router << std::endl;

    router = match.selectRouter("010100110");
    std::cout << "Selected router: " << router << std::endl;

    router = match.selectRouter("0101100110");
    std::cout << "Selected router: " << router << std::endl;

    return 0;
}