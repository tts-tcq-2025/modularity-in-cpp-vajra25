#pragma once

namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    constexpr int numberOfMajorColors = 5;
    constexpr int numberOfMinorColors = 5;

    const char* MajorColorNames[numberOfMajorColors] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[numberOfMinorColors] = {"Blue", "Orange", "Green", "Brown", "Slate"};
}
