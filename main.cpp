#include <iostream>
#include <cassert>
#include "ColorFunctions.h"

using namespace TelCoColorCoder;

void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    int pairNumber = GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    // Tests
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    // Print reference manual
    std::cout << "\nColor Code Reference Manual:\n";
    for (const std::string &line : GetColorCodeReference()) {
        std::cout << line << std::endl;
    }

    return 0;
}
